#### [Conditional Statements](https://www.w3schools.com/js/js_if_else.asp)

<code>if (condition1) {
// block of code to be executed if condition1 is true
} else if (condition2) {
// block of code to be executed if the condition1 is false and condition2 is true
} else {
// block of code to be executed if the condition1 is false and condition2 is false
}</code>

- switch statement
  <code>switch(expression) {
  case x:
  // code block
  break;
  case y:
  // code block
  break;
  default:
  // code block
  }</code>

  > If <code>default</code> is not the last case in the switch block, remember to end the default case with a break.

  1. Common Code Blocks
     Different switch cases using the same code.

  ```JS
  switch(new Date().getday()){
    case 4:
    case 5:
        text = "Soon it is Weekend";
        break;
    case 0:
    case 6:
        text = "It is Weekend!";
        break;
    default:
        text = "Looking forward to the Weekend";
  }

  ```

2. Switching Details:
   If multiple cases matches a case value, the first case is selected.

<mark>Switch cases use **strict** comparision.
The values must be of the same type.
</mark>

```JS
let x = "0"
switch(x){
    case 0:
        text = "Off";
        break;
    case 1:
        text = "On";
        break;
    default:
        text = "No value found";
}

```

> In this example there will be no match for x.

###### A note on comparison operators

1. Any value that is not <code>false</code>, <code>undefined</code>, <code>null</code>, <code>0</code>, <code>NaN</code> or an empty string <code>('')</code> actually returns <code>true</code>.

```JS
let cheese = "Cheddar";
if(cheese){
    console.log("Yay!");
}else{
    console.log("No Cheese");
}

```

###### Ternary operator:

```JS
condition ? run this code : run this code instead
```

```JS
const greeting = isBirthday
? "Happy birthday Mrs. Smith - we hope you have a great day!"
: "Good morning Mrs. Smith.";
```
