// Property Access

let text = "Hello World";
console.log(typeof text[11]);
console.log(typeof text.charAt(11));

text[0] = "A"; //Gives no error, but does not work

console.log(text); // Hello World

//extracting a string

let str = "Apple, Banana, Kiwi";
console.log(str.slice(-7)); // a, Kiwi
console.log(str.substring(-7)); // Apple, Banana, Kiwi

//substr
console.log(str.substr(7, 6)); //Banana
console.log(str.substr(7)); //Banana, Kiwi
console.log(str.substr(-4)); // Kiwi

//trim() method
let str1 = "   Hello World;    ";
console.log(str1.trim());
console.log(str1.trimStart());
console.log(str1.trimEnd());

//padding
let str2 = 5;
console.log(str2.toString().padEnd(5, "x"));

//repeat()
console.log("HIHI".repeat(1)); //HIHIHIHIHIHI

//replace()
console.log("HI JOHN".replace("JOHN", "SUNNY")); //HI SUNNY

//
console.log(
  "Please visit Microsoft Microsoft".replace(/MICROSOFT/gi, "Sunbeam")
);

//replaceAll()

let str3 = "I love Cats\n. Cats are my favourite animal.";
console.log(str3.replace(/cats/gi, "dogs"));
//I love dogs. dogs are my favourite animal.

console.log(str3.replaceAll(/cats/gi, "Dogs"));

//split()

console.log("I AM GROOT".split(" "));
//['I', 'AM', 'GROOT']
