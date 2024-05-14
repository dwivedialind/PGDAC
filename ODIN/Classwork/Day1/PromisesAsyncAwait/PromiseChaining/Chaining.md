## [Promise Chaining](https://javascript.info/promise-chaining)

How to handle **Pyramid of Doom** using Promises.

```JS
new Promise(function (resolve, reject) {
  setTimeout(() => resolve(1), 1000); // (*)
})
  .then(function (result) {
    // (**)

    alert(result); // 1
    return result * 2;
  })
  .then(function (result) {
    // (***)

    alert(result); // 2
    return result * 2;
  })
  .then(function (result) {
    alert(result); // 4
    return result * 2;
  });

```

The idea is that result is passed through the chain of <code>.then</code> handlers.

Flow:

1. The initial promise resolves in 1 second.
2. Then the <code>.then</code> handler is called, which in turn creates a new promise(resolved with 2 value).
3. The next <code>then</code> gets the result of previous one, process it and passes to next handler and so on.

The whole thing works, because every call to a <code>.then</code> returns a new promise, so that we can call the next <code>.then</code> on it.

When a handler returns a value, it becomes the result of that promise, so the next <code>.then</code> is called with it.

> **A classic newbie error: technically we can also add many <code>.then</code> to a single promise. This is not chaining**

```JS
let promise = new Promise((resolve, reject) => {
  setTimeout(() => resolve(1), 1000);
});

promise.then((result) => {
  alert(result); //1
  return result * 2;
});

promise.then((result) => {
  alert(result); //1
  return result * 2;
});

promise.then((result) => {
  alert(result); //1
  return result * 2;
});

```

All we did here is adding multiple handlers to single promise.

##### Returning promises

A handler, use in <code>.then(handler)</code> may create and return a promise.

In that case further handlers wait until it settles, and then get its result.

For instance:

```JS
new Promise((resolve, reject) => {
  setTimeout(() => resolve(1), 1000);
})
  .then((result) => {
    alert(result); //1
    return new Promise((resolve, reject) => {
      setTimeout(() => {
        resolve(result * 2);
      }, 1000);
    });
  })
  .then((result) => {
    alert(result); //2
    return new Promise((resolve, reject) => {
      setTimeout(() => resolve(result * 2), 1000);
    });
  })
  .then((result) => {
    alert(result); //4
  });

```

Returning promises allows us to build chains of asynchronous actions.

###### Promisified loadScript

```JS
loadScript("file1.js")
  .then(
    (result) => {
      alert(result);
      fun();
      return loadScript("file2.js");
    },
    (error) => {
      alert(error);
    }
  )
  .then(
    (result) => {
      debugger;
      alert(result);
      fun();
    },
    (error) => {
      alert(error);
    }
  );

```

Here each <code>loadScript</code> call returns a promise, and the next <code>.then</code> runs when it resolves.

> Code is still **flat** it grows down, not to the right. There are no signs of the **pyramid of doom**.

```JS
loadScript("file1.js").then((script1) =>
  loadScript("file2.js").then((script2) =>
    loadScript("file3.js").then((script3 => {
      //this function has access to variables script1, script2, script3
    }))
  )
);


```

Technically, we could add <code>.then</code> directly to each <code>loadScript</code>.

This code does the same: loads 3 scripts in sequence. But it **"grows to the right"**. So we have same problem as with callbacks.

Sometime it's ok to write <code>.then</code> directly, because the nested function
has access to the outer scope.

###### Thenables

A handler may return not exactly a promise, but a so-called **thenable** object-an arbitrary object that has a method <code>.then</code>. It will be treated the same way as promise.

The idea is that 3rd-party libraries may implement "promise-compatible" objects of their own. They can have an extended set of methods, but also be compatible with native promises, because they implement <code>.then</code>

```JS
class Thenable {
  constructor(num) {
    this.num = num;
  }
  then(resolve, reject) {
    alert(resolve); //function() {native code}
    //resolve with this.num*2 after 1 second
    setTimeout(() => {
      resolve(this.num * 2);
    }, 1000);
  }
}

new Promise((resolve) => resolve(1))
  .then((result) => {
    return new Thenable(result);
  })
  .then(alert);

```

###### Bigger example: fetch

```JS
let promise = fetch(url);
```

This makes a network request to the <code>url</code> and returns a promise. The promise resolves with a <code>response</code> object when the remote server responds with headers, but _before the full response is downloaded_
