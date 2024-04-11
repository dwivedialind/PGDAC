/*
let promise = new Promise((resolve, reject) => {
  debugger;
  //the function is executed automatically when the promise is constructed
  // after 1 second signal that the job is done with the result "done"
  setTimeout(() => resolve("done"), 1000);
});
*/
/*
let promise = new Promise(function (resolve, reject) {
  setTimeout(() => resolve("done!"), 3000);
});

// resolve runs the first function in .then
promise.then(
  (result) => alert(result), // shows "done!" after 1 second
  (error) => alert(error) // doesn't run
);
console.log("Hi I am outside");
*/
/*
let promise = new Promise(function (resolve, reject) {
  setTimeout(() => reject(new Error("Whoops!")), 1000);
});
// resolve runs the first function in .then
promise.then(
  (result) => alert(result), // shows "done!" after 1 second
  (error) => alert(error) // doesn't run
);
console.log("Hi I am outside");
*/
/*
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
*/
/*
let promise = new Promise((resolve, reject) => {
  setTimeout(() => reject(new Error("function fails")), 1000);
});
promise.catch((error) => {
  console.log(error);
});
console.log("HI");
*/

/*
new Promise((resolve, reject) => {
  setTimeout(() => resolve("value"), 2000);
})
  .finally(() => alert("Promise ready"))
  .then((result) => alert(result));
*/
// debugger;
// let promise = new Promise((resolve) => {
//   resolve("done");
// });
// debugger;
// promise.then(alert);

function loadScript(src) {
  return new Promise(function (resolve, reject) {
    let script = document.createElement("script");
    script.src = src;
    script.onload = () => resolve(script);
    script.onerror = () => reject(new Error(`Script load error for ${src}`));

    document.head.append(script);
  });
}
debugger;
loadScript("file.js").then(
  (script) => {
    console.log("Successfull");
  },
  (error) => {
    alert(error);
  }
);
