// //Number Methods

// const lotsOfDecimal = 1.435435435456;
// console.log(lotsOfDecimal.toFixed(2));

// //converting string to number
// let myNumber = "74";
// console.log(typeof myNumber); //
// console.log(typeof Number(myNumber));

// let myNumber2 = "74";
// console.log(typeof myNumber2);
// console.log(typeof parseInt(myNumber2));

// //What if we give "ABCD"

// let invalidNum = Number("abcd");
// console.log(invalidNum);

// let invalidNumber = parseInt("abcd");
// console.log(invalidNumber);

// //String concatenation with numbers
// /*
// alert("my" + "string"); //"mystring"
// alert("5" + 2); //"52"
// alert("5" * 2); //10
// alert("5" / 2); //2.5
// alert("5" - 2); //3

// alert(5 + "2"); //"52"
// alert(5 * "2"); //10
// alert(5 / "2"); //2.5
// alert(5 - "2"); //3
// alert(2 + 2 + "1"); //"41" not "221"
// alert("2" + 2 + 1); //"221" not "23"

// */

// //Numeric conversion using Unary +
// console.log("Numeric conversion");
// console.log(+"24");
// 24;
// console.log(+"abcd");
// NaN;
// console.log(+"-23"); //-23
// console.log(+""); //0
// console.log(+NaN); //NaN
// console.log(+true); //1

// //Assignment = returns a value
// let a = 1;
// let b = 2;

// let c = 3 - (a = b + 1);

// // alert(a); // 3
// // alert(c); // 0

// //short hand operation

// let shortA = 2;
// shortA *= 3 + 2 / 2 - 1;
// console.log(shortA);

// //Increment and decrement among other operators
// let counter = 2;
// console.log(2 * ++counter);
// counter = 2;
// console.log(2 * counter++);

// //comma
// let x, y, z;
// for (x = 1, y = 2, z = x * y; x < 5; x++) {}
//
/*
// Type conversion
console.log(true + false);

//prompt
let promptResult = prompt("Enter a number");
console.log(promptResult);
*/

/*
//var has no block scope.
if (true) var test = true;

console.log(test);

if (true) {
  let test1 = true;
}

//console.log(test1); //Reference Error

//var with function scope

function sayHi() {
  if (true) var phrase = "Hello";

  console.log(phrase);
}
sayHi();
debugger;
//console.log(phrase); //Reference Error

//Hoisting with var and let
console.log(varHoistExample);

var varHoistExample = "varHoistExample";

//console.log(letHoistExample); cannot access before initialization

let letHoistExample = "letHoistExample";
//console.log(phrase); //ReferenceError

//Immediately invoked function expression

(function () {
  var message = "Hello";
  alert(message); //Hello
})();

*/

//Main use of IIFE
var x = 10;
function example() {
  var x = 20; //this variable declaration shadows the outer variable x
  console.log(x); // 20
}

example();
console.log(x); // 10
