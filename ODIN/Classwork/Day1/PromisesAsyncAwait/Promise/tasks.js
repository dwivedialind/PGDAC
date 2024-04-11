//Re-resolve a promise?
/*
let promise = new Promise(function (resolve, reject) {
  debugger;
  resolve(1);
  setTimeout(() => resolve(2), 1000);
});
debugger;
promise.then(alert);
*/

// Delay with a promise
/*
function delay(ms) {
  return new Promise((resolve, reject) => {
    setTimeout(resolve, 3000);
  });
}

delay(3000).then(() => alert("run after 3 seconds"));
*/

//Animated circle with a promise
