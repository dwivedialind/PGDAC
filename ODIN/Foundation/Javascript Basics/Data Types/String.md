#### [String Methods](https://www.w3schools.com/js/js_string_methods.asp)

[String Reference](https://www.w3schools.com/jsref/jsref_obj_string.asp)

[MDN String Methods](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String)

- <code>String length</code>

```JS
let text = "ABCD";
console.log(text.length); //4
```

- <code>Extracting String Characters</code>

1. charAt()

```JS
let text = "HELLO";
console.log(text.charAt(0)); //"H"
```

2. charCodeAt()

returns the code of the character at a specified index in a string:

> The method returns a UTF-16 code (an integer between 0 and 65535).

```JS
let text = "HELLO WORLD";
let char = text.charCodeAt(0); //72
```

3. at()
   ES2022 introduce this
   The at() method returns the character at a specified index

```JS
const name = "W3Schools";
console.log(name.at(2)); // S
console.log(name[2]); //S
```

> <mark>It allows the use of negative indexes whuke charAt() do not.</mark>

```JS
const name = "W3Schools";
console.log(name.at(-2)); //0
//Instead of doing this
console.log(name.charAt(name.length-2));
```

- <code>Property Access []</code>

<ul style = "list-style-type: circle">
<li>It makes string look like arrays ( but they are not) </li>
<li>If no character is foudn, [] returns undefined, while charAt() returns an empty string.</li>
<li>It is read only. str[0] = "A" gives no error (but does not work)</li>
</ul>

```JS
let text = "Hello World";
console.log(typeof text[11]);
console.log(typeof text.charAt(11));

text[0] = "A"; //Gives no error, but does not work

console.log(text); // Hello World

```

- Extracting String Parts

1. <code>slice(start, end)</code>
   extracts a part of a string and returns the extracted part in a new string.

```JS
let text = "Apple, Banana, Kiwi";
console.log(text.slice(7,13)); //Banana
console.log(text.slice(7)); //Banana, Kiwi

```

If a parameter is negative, the position is counted from the end of the string:

```JS
let text = "Apple, Banana, Kiwi";
let part = text.slice(-12,-8); //Banana
```

2. <code>substring()</code> is similar to <code>slice()</code>, difference is that start and end values less than 0 are treated as 0 in substring().

```JS
let str = "Apple, Banana, Kiwi";
console.log(str.slice(-7)); // a, Kiwi
console.log(str.substring(-7)); // Apple, Banana, Kiwi
```

3. <code>substr()</code> is similar to <code>slice()</code>, difference is that the second parameter specifies the length of the extracted part

If the first parameter is negative, the position counts from end of the string.

```JS
console.log(str.substr(7, 6)); //Banana
console.log(str.substr(7)); //Banana, Kiwi
console.log(str.substr(-4)); // Kiwi
```

- <code>toUpperCase()</code> and <code>toLowerCase()</code>

- <code>concat()</code>

<mark>All the string methods return a new string. They don't modify the original string.</mark>

- <code>trim()</code>

1. <code>trim()</code>:
   remove whitespaces from both the sides of a string.

2. <code>trimStart()</code>:
   remove whitespaces only from the start of a string.
3. <code>trimEnd()</code>:
   remove whitespace only from the end of a string.

```JS
let str1 = "   Hello World;    ";
console.log(str1.trim());
console.log(str1.trimStart());
console.log(str1.trimEnd());
```

- Javascript String Padding

1. <code>padStart()</code>
   method pads a string from the start.
   It pads a string with another string(multiple times) until it reaches a given length
2. <code>padEnd()</code>
   method pads a string from the end.
   It pads a string with another string(multiple times) until it reaches a given length

> Both are string methods to pad a number first convert it into String.

```JS
let str2 = 5;
console.log(str2.toString().padEnd(5, "x")); // 5xxxx
```

- JavaScript String repeat()

1. returns a string with a number of copies of a string.
2. returns a new string.
3. does not change the original string.

```JS
console.log("HIHI".repeat(1)); //HIHIHIHIHIHI
```

- Replacing String Content
  <code>replace()</code> method replaces a specified value with another value in a string:

  > does not change the original string, return a new string, replaces only the first match

```JS
console.log("HI JOHN JOHN".replace("JOHN", "SUNNY")); //HI SUNNY JOHN

```

> To replace case insensitive use a regular expression with an /i flag

```JS
console.log("Please visit Microsoft".replace(/MICROSOFT/i, "Sunbeam"));
// Please visit Sunbeam
```

> To replace all the matches use a regular expression with an /g flag

```JS
  "Please visit Microsoft Microsoft".replace(/MICROSOFT/gi, "Sunbeam")

```

- Javascript <code>ReplaceAll()</code>

```JS
let str3 = "I love Cats\n. Cats are my favourite animal.";
console.log(str3.replace(/cats/gi, "dogs"));
//I love dogs. dogs are my favourite animal.

console.log(str3.replaceAll(/cats/gi, "Dogs"));
```

- Javascript String <code>split()</code>
  A string can be converted to an array with the
  <code>split()</code> method.
  ```JS
  console.log("I AM GROOT".split(" "));
  //['I', 'AM', 'GROOT']
  ```
  > If the separator is omitted, the returned array will contain the whole string in index[0].
