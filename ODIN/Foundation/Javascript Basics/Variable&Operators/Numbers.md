## [Numbers](https://developer.mozilla.org/en-US/docs/Learn/JavaScript/First_steps/Math)

### Basic Maths in Javascript

- Unary: An operator is unary if it has single operands.

```JS
let x = 1;
x = -x;
console.log(x); //-1
```

- Binary: An operator is binary if it has two operands.

```JS
let y = 2+3;
```

#### Types of Number in Decimal (Base 10) Number System

1. Integer: Floating point numbers without fraction. Can be positive or negative.
2. Floating point numbers: have decimal points
3. Double: specific type of floating point numbers have greater precision.

We can also have

- Binary **Base(2)**
- Octal **Base(8)**
- Hexadecimal **Base(16)**

> Javascript only have one data type for numbers both decimal and Integer **Number**.

> Javascript has second number type **BigInt** used for very-very large integer values.

#### Useful Number methods

The **Number** object, an instance of which represents all standard numbers, has a number of useful methods available.

```JS
const lotsOfDecimal = 1.732435345;
console.log(lotsOfDecimal.toFixed(2));

```

#### Converting to number data types

- Way 1 using **Number()** constructor to return a number version of the same value

```JS
let myNumber = "74";
console.log(typeof myNumber); //string
console.log(typeof Number(myNumber)); //number
```

- Way 2 using **parseInt()**

```JS
let myNumber = "74";
console.log(typeof myNumber); //string
console.log(typeof parseInt(myNumber)); //number
```

> What if we give "abcd" to Number()

```JS
let invalidNum = Number("abcd");
console.log(invalidNum);//NaN

let invalidNumber = parseInt("abcd");
console.log(invalidNumber); //NaN
```

<mark>NaN (not a number) is a number that is not a legal number.</mark>

- Way 3 using **Unary _+_**
  _Unary +_ applied to number doesn't do anything but if operand is not a number, the unary + operator convert it into a number

```JS
console.log(typeof +"24");
console.log(typeof +"abcd");
console.log(typeof +"-23");
console.log(typeof +"");
console.log(typeof +NaN);
console.log(typeof +true);
// all are number


console.log(+"24");
24;
console.log(+"abcd");
NaN;
console.log(+"-23"); //-23
console.log(+""); //0
//empty string represents the number zero when converted to a number
console.log(+NaN); //NaN
console.log(+true); //1

```

<mark>
Converting a non-numeric string to a number results in NaN.
Converting an empty string to a number results in 0</mark>
<hr>
If we are getting values from HTML form fields they're generally strings what if we need to sum them?

```JS
let apples = "2"
let oranges = "3"
console.log(+apples + +oranges); //5
```

<h6>Operators</h6>
<table class="standard-table">
  <thead>
    <tr>
      <th scope="col">Operator</th>
      <th scope="col">Name</th>
      <th scope="col">Purpose</th>
      <th scope="col">Example</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>+</code></td>
      <td>Addition</td>
      <td>Adds two numbers together.</td>
      <td><code>6 + 9</code></td>
    </tr>
    <tr>
      <td><code>-</code></td>
      <td>Subtraction</td>
      <td>Subtracts the right number from the left.</td>
      <td><code>20 - 15</code></td>
    </tr>
    <tr>
      <td><code>*</code></td>
      <td>Multiplication</td>
      <td>Multiplies two numbers together.</td>
      <td><code>3 * 7</code></td>
    </tr>
    <tr>
      <td><code>/</code></td>
      <td>Division</td>
      <td>Divides the left number by the right.</td>
      <td><code>5 / 2</code>(returns <code>2.5</code> as value)</td>
    </tr>
    <tr>
      <td><code>%</code></td>
      <td>Remainder (sometimes called modulo)</td>
      <td>
        <p>
          Returns the remainder left over after you've divided the left number
          into a number of integer portions equal to the right number.
        </p>
      </td>
      <td>
        <p>
          <code>8 % 3</code> (returns 2, as three goes into 8 twice, leaving 2
          left over).
        </p>
      </td>
    </tr>
    <tr>
      <td><code>**</code></td>
      <td>Exponent</td>
      <td>
        Raises a <code>base</code> number to the <code>exponent</code> power,
        that is, the <code>base</code> number multiplied by itself,
        <code>exponent</code> times.
      </td>
      <td>
        <code>5 ** 2</code> (returns <code>25</code>, which is the same as
        <code>5 * 5</code>)
        <code>4 ** (1/2)</code> (returns <code> 2 </code>)
      </td>
    </tr>
  </tbody>
</table>

#### String concatenation with binary:

```JS
alert("my" + "string"); //"mystring"
alert("5" + 2); //"52"
alert("5" * 2); //10
alert("5" / 2); //2.5
alert("5" - 2); //3

alert(5 + "2"); //"52"
alert(5 * "2"); //10
alert(5 / "2"); //2.5
alert(5 - "2"); //3


//here are more complex examples

alert(2 + 2 + "1"); //"41" not "221"
//here operator works from left to right
alert("2" + 2 + 1); //"221" not "23"

```

#### [Operator Precedence](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Operator_precedence)

Assignment Operator has pretty low precedence.

> Assignment = returns a value
> All the operators in Javascript return a value. It's obvious for <code>+</code> and <code>-</code>, but also for <code>=</code>.  
> The x=value, writes value into x , but also return value.

```JS
let a = 1;
let b = 2;

let c = 3 - (a = b + 1);

alert( a ); // 3
alert( c ); // 0
```

<h5>Chaining Assignment</h5>
Chained assignments evaluate from right to left.

```JS
let a,b,c;

a = b = c = 2+2;

console.log(c); //4
console.log(a); //4
```

<h5>Modify in Place</h5>

```JS
let a = 2;
a += 3 + 5; //right part evaluated first
console.log(a); //16
```

<h5>Increment/Decrement</h5>

<h6>What is difference between postifix and prefix increment and decrement?</h6>

As we know all operators return some value, same for <code>++</code> and <code>--</code>operators.

- prefix: return new value after increment or decrement.
- postifx: returns old value as before increment or decrement.

> The operator ++ and -- can be used inside expression. As they have higher precedence than most of the operators.  
> However it's not readable.

```JS
let counter = 2;
console.log(2* counter++); //4
counter = 2;
console.log(2 *++counter); //6
```

[Bitwise Operators](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Expressions_and_Operators#bitwise_operators)

Bitwise takes argument as 32 bit integer number and work on the level of their binary representation.

<h5>Comma</h5>
Useful to write shorter code.

The comma operator allows us to evaluate several expressions, divide them using comma, each one of them is evaluated but only the last one is returned.

```JS
let a = (1+2,3+4);
console.log(a); //7
```

As <code>,</code> operator has lowest precedence than <code>=</code> operator.

```JS
let a = 1+2,3+4;
console.log(a)//4
```

```JS
for(a=1,b=3,c=a*b; a <5; a++){
//won't update c everytime as initiation statement runs only once.
}
//such tricks are used in every framework, but doesn't improve code readability
```

### Some important conversions

```JS
true + false // 1 + 0 = 1
"4px" - 2 //NaN
"  -9  " - 5 //ignoring spaces -14
null + 1 // 0 + 1 (null become zero after conversion)
undefined + 1 //NaN (undefined becomes NaN after the numeric conversion)
"\t\n" - 2 // 2 (similar to empty string here are spaces only so it will become zero)
```

```JS
"use strict";

let a = prompt("First number?", 1);
let b = prompt("Second number?", 2);

alert(+a + +b); // 3
```

<h5>PROMPT</h5>

> prompt(text, defaultText);
> If you want user to enter value.
> If user clicks "OK" it return value otherwise it returns <mark>null</mark>.

### Difference betweeen == and === operator

- Javascript numbers are primitive values created from literals.

But numbers can also be defined as object with keyword new

- Do not create Number objects, as it complicates the code and slows down execution speed.

```JS
let x = 123;
let y = new Number(123);

console.log(x==y); //true
console.log(x===y); false
```

Comparing two Javascript Objects **always** reutrns **false**.

```JS
let x = new Number(500);
let y = new Number(500);
console.log(x==y);
console.log(x===y);
```
