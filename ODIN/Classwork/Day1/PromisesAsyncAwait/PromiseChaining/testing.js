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
/*
loadScript("file1.js").then((script) =>
  loadScript("file2.js").then((script) =>
    loadScript("file3.js").then((script = {}))
  )
);
*/

//thenable

// class Thenable {
//   constructor(num) {
//     this.num = num;
//   }
//   debugger;
//   then(resolve, reject) {
//     alert(resolve); //function() {native code}
//     //resolve with this.num*2 after 1 second
//     setTimeout(() => {
//       resolve(this.num * 2);
//     }, 1000);
//   }
// }

// debugger;
// new Promise((resolve) => resolve(1))
//   .then((result) => {
//     return new Thenable(result);
//   })
//   .then(alert);
