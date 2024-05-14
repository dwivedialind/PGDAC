/*
const myObject = {
  property: "value",
  "obnoxious property": function () {
    console.log("Hi");
  },
};

// myObject["obnoxious property"]();

const variable = "property";

console.log(myObject.variable); // this gives us 'undefined' because it's looking for a property named 'variable' in our object
console.log(myObject[variable]); // this is equivalent to myObject['property'] and returns 'Value!'
*/

//Object constructor

/*
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

*/

//Exercise

/*
function book(title, author, pages, read) {
  this.title = title;
  this.author = author;
  this.pages = pages;
  this.read = read;
  this.info = () =>
    `${this.title} by ${this.author}, ${this.pages} pages, ${read}`;
}

const theHobbit = new book("The Hobbit", "J.R.R Tolkien", 295, "not read yet");

console.log(theHobbit.info());
*/

//setting prototypal inheritance

function person() {
  this.name = name;
}

person.prototype.sayName = function () {
  console.log(`Hello, I'm ${this.name}`);
};
console.log(person);
console.log(person.prototype);
function Player(name, marker) {
  this.name = name;
  this.marker = marker;
}

Player.prototype.getMaker = function () {
  console.log(`My mark is ${this.marker}`);
};

Object.getPrototypeOf(Player.prototype); // returns Object.prototype

//Now make 'Player objects inherit from 'Person'
Object.setPrototypeOf(Player.prototype, person.prototype);
console.log(Object.getPrototypeOf(Player.prototype)); //returns Person.prototype

const player1 = new Player("steve", "X");
const player2 = new Player("also steve", "o");
player1.sayName();
player2.sayName();

player1.getMaker();
player2.getMaker();
