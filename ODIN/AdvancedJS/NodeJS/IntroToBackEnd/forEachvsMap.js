/*
const a = [1, 2, 3, 4];

const b = a.forEach((i) => {
  return (i = i + 2);
});
console.log(b);

const c = a.map((i) => {
  return (i = i + 2);
});
console.log(c);
*/

/*
const a = [1, 2, 3, 4, 5];

const b = a
  .map((x) => x * x)
  .reduce((total, value) => {
    total + value;
  });

console.log(b);

//const c = a.forEach((x) => x * x).reduce((total, value) => total + value);
//Typeerror: Cannot read properties of undefined
console.log(c);
*/

const myAwesomeArray = [1, 2, 3, 4, 5];

const startForEach = performance.now();
myAwesomeArray.forEach((x) => (x + x) * 10000000000);
const endForEach = performance.now();
console.log(`Speed [forEach]: ${endForEach - startForEach} miliseconds`);

const startMap = performance.now();
myAwesomeArray.map((x) => (x + x) * 10000000000);
const endMap = performance.now();
console.log(`Speed [map]: ${endMap - startMap} miliseconds`);
