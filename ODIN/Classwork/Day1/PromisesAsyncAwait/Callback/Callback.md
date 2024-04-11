#### Calback

Many functions are provided by JavaScript host environments that allow you to schedule _asynchronous_ actions. In other words, actions that we initiate now, but they finish later.

```JS
function loadScript(src){
    //creates a <scrip> tag and append it to the page
    //this causes the script with given src to start loading and run when complete
    let script = document.createElement('script');
    script.src = src;
    document.head.append(script);
}
//load and execute the script at the given path
loadScript('file.js');
```

The script is executed "asynchronously", as it starts loading now, but runs later, when the function has already finished.

> If there's any code below **loadScript(...)**, it doesn't wait until the script loading finishes.

```JS
loadScript('file.js');
console.log("Hi this is testing");
```

IF we want to use new script as soon as it loads. It won't work.

```JS
loadScript('file.js');
fun1(); //no such function!
```

Let's add a <code>callback</code> function as a second argument to <code>loadScript</code> that should execute when the scripts load:

```JS
function loadScript(src,callback){
    let script = document.createElement('script');
    script.src = src;
    script.onload = () => callback(script);
    document.head.append(script);
}
```

onload event basically executes a function after the script is loaded and executed.

Now if we want to call new functions from the script, we should write that in the callback.

```JS
loadScript('/my/script.js', function() {
  // the callback runs after the script is loaded
  newFunction(); // so now it works
});
```

> That's the idea: the second argument is a function(usually anonymous) that runs when the action is completed.

<mark> That’s called a “callback-based” style of asynchronous programming. A function that does something asynchronously should provide a callback argument where we put the function to run after it’s complete.
</mark>

#### Callback in callback

How can we load two scripts sequentially: the first one, and then the second one after it?

> The natural solution would be to put the <code>loadScript</code> call inside the callback.

```JS
function loadScript(src, callback) {
  debugger;
  let script = document.createElement("script");
  script.src = src;
  script.onload = () => callback(script);
  document.head.append(script);
}
debugger;
loadScript("file.js", (script) => {
  debugger;
  alert(`Cool, the ${script.src} is loaded let's load one more`);
  loadScript("file2.js", (script) => {
    debugger;
    alert(`Cool, the second script is loaded ${script.src}`);
  });
});

```

#### Handling error

What if script loading fails?

```JS
function loadScript(src, callback) {
  debugger;
  let script = document.createElement("script");
  script.src = src;
  script.onload = () => {
    callback(null, script);
  };
  script.onerror = () => {
    callback(new Error(`Script load Error for ${src}`));
  };
  document.head.append(script);
}

debugger;
loadScript("//file.js", (error, script) => {
  debugger;
  if (error) {
    alert(error.message);
  } else {
    alert(`${script} loaded successfully`);
  }
});
```

This is called **"error-first callback"** style.

Single <code>callback</code>
function is used both for reporting errors and passing back results.

#### Pyramid of Doom

For multiple asynchronous actions that follow one after another, we'll have a code like this.

```JS
loadScript('1.js', function(error, script) {

  if (error) {
    handleError(error);
  } else {
    // ...
    loadScript('2.js', function(error, script) {
      if (error) {
        handleError(error);
      } else {
        // ...
        loadScript('3.js', function(error, script) {
          if (error) {
            handleError(error);
          } else {
            // ...continue after all scripts are loaded (*)
          }
        });

      }
    });
  }
});
```

This called **Callback hell** or **Pyramid of doom**.

We can try to alleviate the problem by making every action a standalone function, like this:

```JS
loadScript('1.js', step1);

function step1(error, script) {
  if (error) {
    handleError(error);
  } else {
    // ...
    loadScript('2.js', step2);
  }
}

function step2(error, script) {
  if (error) {
    handleError(error);
  } else {
    // ...
    loadScript('3.js', step3);
  }
}

function step3(error, script) {
  if (error) {
    handleError(error);
  } else {
    // ...continue after all scripts are loaded (*)
  }
}


```

###### Problem with this:

1. Code looks like torn apart spreadsheet.
2. Difficult to read
3. Functions named <code>step\*</code> are all of single use.

> We'd like to have something better. Lucking there are other ways to avoid such pyramids. One of the best ways is to use "promises".

# Explain Asynchronous programming

###### The Problem:

- Some tasks in js take time to complete, like downloadin gdata from internet or waiting for user input.
- if your code waits for these tasks to finish before moving on, it can free or become unresponsive.

###### The Solution: Asynchronous Programming

- Asynchronous programming allows your code to continue running other tasks while waiting for slow operation to complete.
- It's like delegating those slow tasks and focusing on other things until they're done.

<mark>Makes your web applications feel faster and more responsive.</mark>
