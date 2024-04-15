#### [Logical Operators](https://javascript.info/logical-operators)

There are four logical operators in Javascript: <code>||</code> (OR), <code>&&</code> (AND), <code>!</code> (NOT), <code>??</code>(Nullish Coalescing).

##### || (OR)

- result is always <code>true</code> except for the case when both operands are <code>false</code>.
  > If an operand is not a boolean, it's converted to a boolean for the evaluation.

```JS
console.log(1 || 0); // just like (true || false) false
```

- **OR "||" finds the first truthy value from a list of variables and expressions.**

> result = value1 || value2 || value3

The OR <code>||</code> operator does the following:

1. Evaluates operands from left to right.
2. For each operand, converts it to boolean, if the result is <code>true</code>, stops and returns the original value of that operand.
3. If all operand have been evaluated(i.e. all were <code>false</code>), returns the last operand.

A value is returned it its original form, without the conversion

```JS
alert( 1 || 0 ); // 1 (1 is truthy)

alert( null || 1 ); // 1 (1 is the first truthy value)
alert( null || 0 || 1 ); // 1 (the first truthy value)

alert( undefined || null || 0 ); // 0 (all falsy, returns the last value)

alert("" || "" | "SuperCoder" || "Anonymous"); //SuperCoder
```

1. Getting the first truthy value from the list of variables or expressions.

2. Short-circuit evaluation.
   <code>||</code> processes its arguments until the first truthy value is reached, and then the values is returned immediately, without even touching the other argument.

> The importance of this feature becomes obvious if an operand isn't just a value, but an expression with a side effect, such as a variable assignment or a function call.

```JS
true || alert("not printed");
false || alert("printed");
```

##### && (AND)

- **AND "&&" finds the first falsy values**

> result = value1 && value2 && value3;

1. Evaluates operand from left to right.
2. For each operand, converts it to boolean. If the result is <code>false</code>, stops and returns the original value of that operand.
3. If all operand have been evaluated, returns the last operand

```JS
// if the first operand is truthy,
// AND returns the second operand:
alert( 1 && 0 ); // 0
alert( 1 && 5 ); // 5

// if the first operand is falsy,
// AND returns it. The second operand is ignored
alert( null && 5 ); // null
alert( 0 && "no matter what" ); // 0
``
```

<mark>Precedence of AND <code>&&</code> is higher than OR <code>||</code></mark>

> a && b || c && d ---- (a && b) || (c && d)

> Don't replace **if** with **||** or **&&**.

##### ! (NOT)

1. converts the operand to boolean type
2. Returns the inverse value

A double NOT <code>!!</code> is sometimes used for converting a value to boolean type:

```JS
alert(!!"non-empty string"); // true
alert(!!null); // false

```

## <mark>The precedence of <code>NOT</code> is highest of all logical operators.</mark>
