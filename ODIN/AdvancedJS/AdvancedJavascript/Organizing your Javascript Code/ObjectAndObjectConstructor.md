# [Object and Object Constructor](https://www.theodinproject.com/lessons/node-path-javascript-objects-and-object-constructors)

- **Object Literal** syntax to define objects

```js
const myObject{
    property : "value",
    otherProperty: 77,
    "obnoxious property": function(){

    }
}
```

- There are also 2 ways to get information out of an object: <code>dot notation</code> and <code>bracket notation</code>

```js
// dot notation
myObject.property; // 'Value!'

// bracket notation
myObject["obnoxious property"]; // [Function]
```

- _When to use which?_

bracket notation, when working with property having space in it.
ex: "obnoxious property"
cannot use variable in dot notation

```js
const variable = "property";

console.log(myObject.variable); // this gives us 'undefined' because it's looking for a property named 'variable' in our object
console.log(myObject[variable]); // this is equivalent to myObject['property'] and returns 'Value!'
```

### Questions overview

- How to write an object constructor and instantiate the object.
- Describe what a prototype is and how it can be used.
- Explain prototypal inheritance.
- Understand the basic do's and dont's of prototypal inheritance
- Explain what the <code>this</code> keyword is.

### Objects as a design pattern

> One of the simplest ways we can organize our code is by grouping things into objects.

```js
// example one
const playerOneName = "tim";
const playerTwoName = "jenn";
const playerOneMarker = "X";
const playerTwoMarker = "O";

// example two
const playerOne = {
  name: "tim",
  marker: "X",
};

const playerTwo = {
  name: "jenn",
  marker: "O",
};
```

1. easy to access specific player properties.

```js
console.log(playerOne.name);
//vs
console.log(playerOneName);
```

It may not seem bad, but what if there are hundred of players, remembering variable _name_ for each player is tough task.

### Object constructors

- When we have a specific type of object that we need to duplicate like our player or inventory items, a better way to create them is using an <code>object constructor</code>, which is a function look like this:

```js
function Player(name, marker) {
  this.name = name;
  this.marker = marker;
  this.sayName = function () {
    console.log(this.name);
  };
}

const playerOne = new Player("steve", "X");
console.log(playerOne.name);

const playerTwo = new Player("jenn", "O");
console.log(playerTwo.name);

playerOne.sayName();
playerTwo.sayName();
```

### The prototype

**All objects in Javascript have a <code>prototype</code>. The <code>prototype</code> is another object that the original object inherits from, which is to say, original object has access, to all it's <code>prototype's</code> methods and properties.**

- **The prototype is another object**
  just like playerOne and playerTwo, <code>prototype</code> also have properties and functions.

#### Accessing an object's prototype

after creating player1 and player2 run following code in console.

```js
Object.getPrototypeOf(player1) === Player.prototype; //returns true
Object.getPrototypeOf(player2) === Player.prototype; //returns true
```

1. <code>Object.getPrototypeOf()</code>, return value of this function refers to the <code>.prototype</code> property of Object Constructor(i.e., <code>Player(name, marker)</code>)

2. The _reference_ the the value of <code>Player.prototype</code> is stored in every <code>Player</code> object, every time <code>Player</code> object is created.

3. Any properties or methods defined <code>Player.prototype</code> will be available to the created <code>Player</code> objects.

**_Object.getPrototypeOf() vs .\_\_proto\_\_ vs [[Prototype]]_**

Other two methods of accessing object prototype is deprecated

```js
console.log(player1.__proto__); //is legacy feature and should not be used in production code
console.log(player1.[[Prototype]]); //double square brackets signify that it is an internal property, and cannot be accessed directly in code
```

### Prototypal Inheritance

What is the purpose of defining properties and functions on the prototype?

- We can define properties and functions common among all objects on the <code>prototype</code> to save memory.

- as <code>player1</code> and <code>player2</code> object inherit form <code>Player.prototype</code> object.

```js
player1.valueOf();
```

The <code>.valueOf</code> is defined on <code>Object.prototype</code>

```js
player1.hasOwnProperty("valueOf"); //false
Object.prototype.hasOwnProperty("valueOf"); //true
```

> .valueOf is not a property of prototype of player1.

```js
console.log(Object.prototype == player1.__proto__.__proto__); //true
```

1. Every <code>prototype</code> object inherits from <code>Object.prototype</code> by default.
2. An object's <code>Object.getPrototypeOf()</code> value can only by one unique <code>prototype</code> object.

#### Recommended method for prototypal inheritance

```js
function Person(name) {
  this.name = name;
}

Person.prototype.sayName = function () {
  console.log(`Hello, I'm ${this.name}!`);
};

function Player(name, marker) {
  this.name = name;
  this.marker = marker;
}

Player.prototype.getMarker = function () {
  console.log(`My marker is '${this.marker}'`);
};

Object.getPrototypeOf(Player.prototype); // returns Object.prototype

// Now make `Player` objects inherit from `Person`
Object.setPrototypeOf(Player.prototype, Person.prototype);
Object.getPrototypeOf(Player.prototype); // returns Person.prototype

const player1 = new Player("steve", "X");
const player2 = new Player("also steve", "O");

player1.sayName(); // Hello, I'm steve!
player2.sayName(); // Hello, I'm also steve!

player1.getMarker(); // My marker is 'X'
player2.getMarker(); // My marker is 'O'
```

### <code>.prototype</code> on Constructors vs Objects:

- **_Constructors_**: When you define a constructor function (e.g., function Player(name,marker){...}), the <code>.prototype</code> property of that function holds the prototype object that future objects created using the constructor will inherit from.

- **_Objects_** : When you create an object using a constructor, that object itself doesn't have a <code>.prototype</code> property. It has a hidden reference to the constructor's <code>.prototype</code> object, which is where it inherits properties and methods.
