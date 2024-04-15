//Mathematical operations with NaN

console.log(NaN * 1);
console.log(NaN ** 0); //exception

//Bigint

// const num = 1223435454354565464564564564564564564564565464564560;
// const bigInt = 1223435454354565464564564564564564564564565464564560n;
// console.log(num);
// console.log(bigInt);

//String Literal
let num = 2;
console.log(`This is ${num}`);
console.log(`sum of 1 + 2 is ${1 + 2}`);

//type of
console.log(typeof undefined); //undefined
console.log(typeof Symbol("id")); // "symbol"
console.log(typeof Math); //"object"
console.log(typeof null); //"object"
//above is offically recognized error of typeof, The behaviour of typeof is wrong here

console.log(typeof alert); //"function"

//String quotes
// let name = "Ilya";
// alert(`hello ${1}`); // hello 1
// alert(`hello ${"name"}`); // hello name
// alert(`hello ${name}`); // hello Ilya

//Multiple Strings
const newLine = `One day you finally knew
what you had to do, an dbegan,`;
console.log(newLine);

/*
One day you finally knew
what you had to do, and began,
*/
