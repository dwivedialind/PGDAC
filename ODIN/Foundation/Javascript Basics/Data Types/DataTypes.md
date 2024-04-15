[Data Types](https://www.theodinproject.com/lessons/foundations-data-types-and-conditionals)

> There are 8 data types in Javascript.

[Data Types](https://javascript.info/types)

###### Numbers

The number type represents both integer and floating type.
Besides regular number there are some _special numeric values_

- <code>Infinity</code>: <code>alert(Infinity);</code>
- <code>-Infinity</code>
- <code>NaN</code>: It is a result of incorrect mathematical computation.

Any operation with <code>NaN</code> <code>returns NaN</code>.

```JS
alert(NaN + 1); //NaN
alert(NaN * 1); //NaN

//only exception
alert(NaN ** 0) // 1
```

> Mathematical operation are safe in Javascripts. There will be no fatal error. At worst we get NaN

"Number" type can store integers in range of <code><sup>+</sup>- (2^53 - 1)</code>.

Outside of this range there will be precision error, because not all digits fit into the fixed 64-bit storage.

###### [BigInt](https://javascript.info/bigint)

- recently addeed
- A Bigint value is created by appending n to the end of an integer.

```JS
const num = 1223435454354565464564564564564564564564565464564560;
const bigInt = 1223435454354565464564564564564564564564565464564560n;
console.log(num);
console.log(bigInt);

```

###### String

String in Javascript must be surrounded by quotes.  
In Javascript there are 3 type of quotes

- Double quotes(""): <code>"hello"</code>
- Single quotes(''): <code>'hello'</code>
- BackTicks(\`\`): <code>\`hello\`</code>

There is practically no difference in double quotes and single quotes, however backticks help us with embeding variable and expression in string, called <code>template literals</code>

```JS
let num = 2;
console.log(`This is ${num}`);
console.log(`sum of 1 + 2 is ${1+2}`);

```

> Please note this can be done only with backquotes.

<mark>There is no character type. string is used.</mark>

**We can write multiple strings using template literal**

Template literals respect the line breaks

```JS
const newline = `One day you finally knew
what you had to do, and began,`;
console.log(newline);

/*
One day you finally knew
what you had to do, and began,
*/

```

> putting a backslash just before the character we can escape.

```JS
const badString1 = This is a test; // error: missing; before statement
const badString2 = "This is a test; // error:
unterminated string literal
```

<code>String()</code> function converts its argument to a string

###### Boolean

has only two values <code>true</code> or <code>false</code>

###### The **"null"** value

The special <code>null</code> value does not belong to any of the types described above.

```JS
let age = null;
```

> In JS, <code>null</code> is not a _"reference to a non-existing"_ object.

<mark> > It's just a special value which represents _nothing_ _empty_ or _value unknown_. </mark>

###### The **"undefined"** value

It makes a type of its own, just like <code>null</code>

The meaning of <code>undefined</code> is _"value not assigned"_

```JS
let age;
alert(age); // shows "undefined"
```

Technically it is possible to explicityl assign <code>undefined</code> to a variable

```JS
let age = 100;
age = undefined;
alert(age); // "undefined"
```

> - Normally use <code>null</code> to assign an _empty_ or _unknown_ value to a variable.

- <code>undefined</code> is reserved as a default initial value for unassigned things.

###### Objects and Symbols

<code>object</code> is a special type.  
All other types are called "primitive" because they can store only single values but "object" can store complex entities.

<code>symbol</code> is used to create unique identifiers for objects

[OBJECTS](https://javascript.info/object)

##### typeof operator

- returns type of operand

```JS
console.log(typeof undefined); //undefined
console.log(typeof Symbol("id")); // "symbol"
console.log(typeof Math); //"object"
console.log(typeof null); //"object"
//above is offically recognized error of typeof, The behaviour of typeof is wrong here

console.log(typeof alert); //"function"
```

<mark>typeof(x) and typeof x both are same</mark>

> <code>typeof</code> is an operator, not a function. Here parentheses used for mathematical grouping.
