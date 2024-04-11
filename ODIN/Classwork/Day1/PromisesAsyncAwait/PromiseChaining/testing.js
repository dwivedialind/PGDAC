/*
debugger;
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
console.log("Hi");
*/

/*
debugger;
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
*/

//Returning Promises

/*
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
*/

loadScript("file1.js").then((script) =>
  loadScript("file2.js").then((script) =>
    loadScript("file3.js").then((script = {}))
  )
);
