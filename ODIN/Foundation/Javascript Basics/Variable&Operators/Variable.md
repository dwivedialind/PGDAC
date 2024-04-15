## Ways to include JS in html

- Internal Script <script> </script>  
  Internal Script can be kept inside <head> tag or <body> tag depends on when js should run using JS Engine.

* External Script

```JS
<script src = "file.js" ></script>
```

### How do you declare a variable?

[Variable](https://javascript.info/variables)

Variable is named storage for data.

- using **let** keyword

```JS
let name = "John",
  age = 23,
  email = "alind@gmail.com";
console.log(name + age + email);
```

> For the sake of readability, please use a single line per variable.

```JS
//display a message on dialog box
alert(message)
```

- using **var** instead of **let**  
  almost same as let, however there are some subtle differences
  [old.var](https://javascript.info/var)

1. **"var"** has no block scope

Variables, declare with <code>var</code> are either function-scoped or global-scoped.

```JS
if(true){
  var test = true;
}
alert(test); //ture, the variable lives after if

```

The same thing for loops:

```JS
for(var i = 0; i < 10; i++)
 var one = 1;

alert(i) //10
alert(one) //1
//both are visible after loop, it's a global variable
```

If a code block is inside a function, then <code>var</code> becomes a function-level variable:

```JS
function sayHi(){
  if(true)
   var phrase = "HEllo";

  alert(phrase); //works
}

sayHi();
alert(phrase); //ReferenceError: phrase is not defined

```

2. **"var"** tolerates redeclarations

```JS
let user;
let user; // SyntaxError: 'user has already been declared
```

```JS
var user = "Pete";
var user = "John"; // this "var" does nothing ...it doesn't trigger an error

alert(user); //John
```

3. **"var"** variables can be declared below their use
   [Hoisting](https://www.freecodecamp.org/news/what-is-hoisting-in-javascript-3/)

4. IIFE (immediately-invoked function expressions)

In the past, as there was only <code>var</code>, and it has no block-level visibility, programmers invented a way to emulate it.

In IIFE:

- we define a function expression.
- we immediately invoke the function expression.
  > need to put <code>()</code> around function, because if JS engine encounter "function" in the main code, it interprets the start of function, But a function declaration must have a name.

> Even if we say let's add a name, it won't work, as JS does not allow function declarations to be called immediately.

```JS
(function () {
  var message = "Hello";
  alert(message); //Hello
})();


```

<mark>The purpose of an IIFE, is typically to create a new scope for variables without polluting the surrounding scope.</mark>

```JS
var x = 10;
function example() {
  var x = 20; //this variable declaration shadows the outer variable x
  console.log(x); // 20
}

example();
console.log(x); // 10

```

```JS
var x = 10;

(function() {
    var x = 20; // This variable declaration does not affect the outer variable x
    console.log(x); // Output: 20
})();

console.log(x); // Output: 10

```

<hr>
- JS is single threaded and loosely-typed language.

```JS
let message = "Hello"
console.log( typeof message); //string
message = 2;
console.log(typeof message); //number
```

> There exists pure functional languages such as **Haskell** in which we can't change the value inside a variables.

### Rules for naming a Variable

1. The name must contain letter, digits, \_$ and \_\_.
2. The name must not begin with number.
3. Case sensitive.
4. There are some reserved keywords which can not be used.

~~Non latin letters are allowed but not recommended.~~

```JS
let $ = 2;
let _ = 3;
//both are valid
let apple = "apple"
let APPLE = "APPLE"
// both are different variables.

```

Assignement without "use strict"

```JS
num = 5;
console.log(num);  //5
```

In old times, it is technically possible to create a variable by a mere assignment of value without using let.
It still works now if we don't use **use strict** in our scripts to maintain compaitability with old scripts.

```JS
"use strict"
num = 5;
console.log(num); // error -- num not defined.
```

### Constants

- Being a "constant" just means that once declared value won't change.

```JS
let a ;
a = 20;
const b; //syntaxError - Missing initializer in constant declaration
b = 20 ;
```

#### uppercase constants

It's widespread practice to use constants as aliases for difficult-to-remember values that are known before execution.<mark>(hard coded values)</mark>

> Such constants are named using capital letters and underscores.

**const COLOR_RED = "#F00";**

**When should we use capitals for a constant and when we name it normally?**

Some constants are known before execution and some constants are calculated in run-time, during the execution, but do not change after their initial assignment.

```JS
const pageLoadTime = /*time take by a webpage to laod*/
```

## Name things right

Some good-to-follow rules are:

1. Use human-readable names like userName or shoppingCart.
2. Stay away from abbreviatios or short names like a, b and c unless you know what you're doing.
3. Make names maximally descriptive and concise. Examples of bad names are data and value. Such names say nothing, it's only okay to use them if the context of the code makes it exceptionally obvious which data or value the variable is referencing.
4. Agree on terms within your team and in your mind. If a site visitor is called a "user" then we should name related variables currentUser or newUser instead of currentVisitor or newManInTown.
5. Using different variable for different values can help the engine optimize your code.
