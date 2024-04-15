#### [Comparisons](https://javascript.info/comparison)

- String Comparision: compared lexographically, letter by letter

```JS
console.log('Z' > 'A'); // true;
console.log("Glow" > "Glee"); // true
console.log("Bee" > "Be"); //true

```

1. First compare the first character of both strings.
2. If first character of first string is greater than first character of second string, then first string is greater or vice-versa.
3. If first character of both the strings are same then second character is compared.
4. Repeat until one string ends.
5. If both the strings are of same length, then they are equal else the longest string is greater.

- Comparision of different types
  When comparing values of different types, JS convert the values to numbers.

```JS
console.log("2" > 1); // true
console.log("01" == 1); // trues

//For boolean values true becomes 1 false becomes 0
console.log(true == 1); // true
```

> It is possible that at the same time: Two values are equal

```JS
let a = 0;
alert( Boolean(a)); //false

let b = "0";
alert(Boolean(b)); // true

alert(a==b); // ture;

```

- Strict equality

A regular equality <code>==</code> has a problem. It cannot differentiate <code>0</code>
from <code>false</code>.  
The same thing happens with an empty string:

```JS
console.log(0 == false); //true
console.log(''== false); //true

```

<mark>A strict equality operator <code>===</code> checks the equality without type conversion. </mark>

```JS
console.log(0===false); false
```

> There is also "strict non-equality" operator <code>!==</code> analogous to <code>!=</code>

- Comparision with <code>null</code> and <code>undefined</code>

```JS
//for a strict equality check
alert(null === undefined); // false
// both are of different type.

//for a non-strict check
alert(null == undefined); //true

```

1. For maths and other comparisions <code>< > <= >=</code>
   <code>null/undefined</code> are converted to numbers: <code>null</code> becomes <code>0</code>, while <code>undefined</code> becomes
   <code>NaN</code>.

###### Strange result: null vs 0

```JS
alert(null > 0); // false (1)
alert(null == 0); // false (2)
alert(null >= 0); // true (3)
```

<mark>(3) contradicts (1) & (2), the reason is that an equality check == and comparisions work differently. Comparisions convert <code>null</code> to a number, treating it as 0. On the other hand, the equality check for <code>undefined</code> and <code>null</code> is defined such that, without any conversions they equal each other and don't equal anything else. That's why (2) is false.</mark>

###### An incomparable undefined

The value <code>undefined</code> shouldn't be compared to other values:

<mark>As always return false in comparision. Becuase gets converted to <code>NaN</code></mark>.
And in equality check <code>undefined</code> only equals <code>null</code>, undefined and no other value.

> Should we remember these pecularities all the time? Not really, gradually become familiar.

<div style= "border: 1px, solid black">
Avoid Problems:

1. Treat any comparision with undefined/null except the strict equality with exceptional care.
2. Don't use comparisions with a variable which may be null/undefined.
</div>

###### Some important cases

5 > 4 // true

"apple" > "pineapple" //false

"2" > "12" //true

undefined == null // true

undefined === null //false

null == "\n0\n" // false
null === +"\n0\n" //false
