# [Promise](https://javascript.info/promise-basics)

Promise is a special Javascript Object, that links the 'Producing Code' and 'Consuming Code'.

- Producing Code: that does something and takes time
- Consuming Code: that wants the result of _producing code_ once it's done.

The constructor syntax for a promise object is:

```JS
let promise = new Promise(function(resolve, reject)){
    //executor
}

```

The function passed to <code>new Promise</code> is called the executor. When <code>new Promise</code> is created, the executor runs automatically. It contains the producing code which should eventually produce the result.

It's argument <code>resolve</code> and <code>reject</code> are called callbacks provided by JS itself.
Our code is only inside the executor.

When the executor obtain the result, be it soon or late, doesn't matter, it should call one of these callbacks:

- <code>resolve(value)</code> - if the job is finished successfully, with result <code>value</code>.
- <code>reject(error)</code> - if an error has occured, <code>error</code> is the error object.

So to summarize: the executor runs automatically and attempts to perform a job. When it is finished with the attempt, it calls <code>resolve</code> if it was successful or <code>reject</code> if there was an error.

<hr>

The <code>Promise</code> object returned by the <code>new Promise</code> constructor has these internal properties:

- <code>state</code> initially <code>"pending"</code>, then changes to either <code>"fulfilled"</code> when <code>resolve</code> is called or <code>"rejected"</code> when <code>reject</code> is called.

- <code>result</code>-initially <code>undefined</code>, then changes to <code>value</code> when <code>resolve(value)</code> is called or <code>error</code> when <code>reject(error)</code> is called
  ![Screenshot from 2024-04-10 10-53-54](/assets/Screenshot%20from%202024-04-10%2010-53-54.png)

```JS
let promise = new Promise((resolve, reject) => {
  debugger;
  //the function is executed automatically when the promise is constructed
  // after 1 second signal that the job is done with the result "done"
  setTimeout(() => resolve("done"), 1000);
});
```

![Screenshot from 2024-04-10 11-05-09](/assets/Screenshot%20from%202024-04-10%2011-05-09.png)

```JS
let promise = new Promise(function(resolve, reject) {
  // after 1 second signal that the job is finished with an error
  setTimeout(() => reject(new Error("Whoops!")), 1000);
});

```

![Screenshot from 2024-04-10 11-06-02](/assets/Screenshot%20from%202024-04-10%2011-06-02.png)

A promise that is either resolved or rejected is called "settled", as opposed to an initially "pending" promise.

> There can only a single result or an error
> The executor should call only one resolve or one reject. Any state change is final. All the further calls of resolve and reject are ignored.

```JS
let promise = new Promise(function(resolve,reject){
    resolve("done");
    reject(new Error("......")); // ignored
    setTimeout(()=> resolve("...")); //ignored
})
```

The idea is that a job done by the executor may have only one result or an error.

Also, <code>resolve/reject</code> expect only one argument(or none) and will ignore additional arguments.

> Reject with Error objects

> Immediately calling resolve/reject
> In practice, an executor usually does something asynchronously and calls resolve/reject after some time, but it doesn't have to. We also can call resolve or reject immediately.

> The state and result are internal
> The properties state and result of the Promise object are internal. We can't directly access them. We can use the methods .then/.catch/.finally for that. They are described below

#### Consumers(then,catch)

Consuming functions can be registered using the methods <code>.then and .catch</code>

##### .then

The syntax is:

```JS
promise.then(
    function(result){/*handle a successful result*/},
    function(error){/*handle an error*/}
)
```

First argument function runs when the promise is resolved and receives the result.
And Second argument function runs when the promise is rejected and receives the errror.

Successfully resolved promise:

```JS
let promise = new Promise(function (resolve, reject) {
  setTimeout(() => resolve("done!"), 3000);
});

// resolve runs the first function in .then
promise.then(
  (result) => alert(result), // shows "done!" after 1 second
  (error) => alert(error) // doesn't run
);
console.log("Hi I am outside");

```

Rejected Promise

```JS
let promise = new Promise(function (resolve, reject) {
  setTimeout(() => reject(new Error("Whoops!")), 1000);
});
// resolve runs the first function in .then
promise.then(
  (result) => alert(result), // shows "done!" after 1 second
  (error) => alert(error) // doesn't run
);
console.log("Hi I am outside");


```

> If we're interested in only successful completion we can provide only one argument to .then function.

```JS
let promise = new Promise(function (resolve, reject) {
  setTimeout(() => reject(new Error("Whoops!")), 1000);
});
// resolve runs the first function in .then
promise.then(
  (result) => alert(result) // shows "done!" after 1 second
);

```

## A Good Case

The code creates a Promise that resolves immediately (due to the resolve call).
The .then method attaches a callback to handle the resolved value.
However, the asynchronous nature of Promises means the .then callback is queued for later execution by the event loop, even though it appears to be called after the Promise resolution.
The synchronous code (console.log("HI HI HI")) executes first, followed by the asynchronous execution of the .then callback when the event loop processes it.

```JS
debugger;
let promise = new Promise(function (resolve, reject) {
  if (2 < 10) resolve("pass");
  else reject(new Error("Failed"));
});
debugger;
// resolve runs the first function in .then
promise.then(
  (result) => console.log(result) // shows "done!" after 1 second
);
debugger;
console.log("HI HI HI");
```

<mark>Even if a Promise resolves quickly, the asynchronous nature of .then callback execution means it gets scheduled in the queue, ensuring efficient handling of both synchronous and asynchronous operations without blocking the main thread.</mark>

##### .catch()

If we are interested only in errors, then we can use null as the first argument as <code>.then(null,errorHandlingFunction)</code> or <code>.catch(errorHandlingFunction)</code>, which is exactly the same.

```JS
let promise = new Promise((resolve, reject) => {
  setTimeout(() => reject(new Error("function fails")), 1000);
});
promise.catch((error) => {
  console.log(error);
});
console.log("HI");


```

##### Cleanup:finally

Just like there's finally clause in <code>try{...} catch{...}</code>, there's <code>finally</code> in promises.

The call <code>.finally(f)</code> is similar to <code>.then(f,f)</code> in the sense that <code>f</code> runs always, when the promise is settled: be it resolve or reject.

The idea of <code>finally</code> is to set up a handler for performing cleanup/finalizing after the previous operations are complete.

E.g. stopping loading indicators, closing no longer needed connections, etc.

```JS

new Promise((resolve, reject) => {
  /* do something that takes time, and then call resolve or maybe reject */
})
  // runs when the promise is settled, doesn't matter successfully or not
  .finally(() => stop loading indicator)
  // so the loading indicator is always stopped before we go on
  .then(result => show result, err => show error)

```

The code may look like above.

#### Differences between finally and then

1. A <code>finally</code> handler has no arguments. In <code>finally</code> we don't know whether the promise is successful or not.
   In above code, we can see <code>finally</code> handler has no arguments, and the promise outcome is handled by the next handler.

2. A <code>finally</code> handler "passes through" the result or error to the next suitable handler.

Here the result i spassed through <code>finally</code> to
<code>then</code>:

```JS
new Promise((resolve, reject) => {
  setTimeout(() => resolve("value"), 2000);
})
  .finally(() => alert("Promise ready"))
  .then((result) => alert(result));

```

3. A <code>finally</code> handler also shouldn't return anything. If it does, the returned value is silently ignored.

> The only exception to this rule is when finally handler throws an error. Then this error goes to next handler, instead of any previous outcome.

**Summarize**

- A <code>finally</code> handler doesn't get outcome of the previous handler. This outcome is passed through instead, to the next suitable handler.

> We can attach handler to settled promises

```JS
let promise = new Promise((resolve) => {
  resolve("done");
});
promise.then(alert);

```

###### Examples

```JS
function loadScript(src) {
  return new Promise(function(resolve, reject) {
    let script = document.createElement('script');
    script.src = src;

    script.onload = () => resolve(script);
    script.onerror = () => reject(new Error(`Script load error for ${src}`));

    document.head.append(script);
  });
}

```

##### Promises vs Callbacks

1. Promises allow us to do things in natural order. First, we run <code>loadScript(script)</code>, and <code>.then</code> we write what to do with the result.
   vs
   We must have a <code>callback</code> function at our disposal when calling <code>loadScript(script, callback)</code>. In other words, we must know what to do with the result before <code>loadScript</code> is called.

2. We can call <code>.then</code> on a Promise as many times as we want.
   vs
   There can be only one callback
