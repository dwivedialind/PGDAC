## Features

Let's Cover features of C#, we will start from 2005 and cover till 2010 in detailed way.

### Table of Contents:

1. C# 2.0 (2005)

   - **Generics**(will be covered separately)
   - Partial Class
   - Anonymous Method
   - Nullable Type
   - Iterator

2. C# 3.0 (2008)

   - Implicit Type
   - Auto Property
   - Object Initializer
   - Anonymous Type
   - Lambda Expression
   - Extension Method
   - Partial Method
   - **LINQ**

3. C# 4.0 (2010)
   - Dynamic Type
   - Optional & Named Parameter
   - **Parallel Programming**( will be covered later )
     - Implicit
     - Explicit

In this article we covered C# 2.0 features.

### Partial Class:

#### Concept of Partial Class

Partial classes come into play to achieve **_separation of concerns_** within the same namespace. Imagine a scenario where two developers are working on the same class but developing different functionalities. For our convenience, let's say one developer is working on the <code>Add</code> method for the <code>Math</code> class on their machine, while another developer is working on the <code>Subtract</code> method for the same <code>Math</code> class on a separate machine. Both developers are working in the same namespace.

If both developers complete their implementations and push their code with the class name <code>Math.cs</code>, a redefinition error for <code>Math.cs</code> will occur during testing, causing integration problems. This is where partial classes come in handy.

#### Partial Classes for Easy Integration

Partial classes allow you to have two classes with the same name within a single namespace. Here's an example demonstrating how separate files can define the <code>Add</code> and <code>Subtract</code> methods for the <code>Math</code> class:

##### File 1: Math.cs(Features Namespace)

```C#
namespace Features
{
    internal partial class Math
    {
        public int Add(int x, int y)
        {
             return x + y;
        }
    }
}
```

##### File 2: Math.cs(Features Namespace)

```C#
namespace Features
{
    internal partial class Math
    {
        public int Subtract(int x, int y)
        {
            return x - y;
        }
    }
}
```

##### Main Program(Features Namespace)

```C#
namespace Features
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Math m = new Math();
            m.Add(10, 20); // output: 30
            m.Subtract(10, 20); // output: -10
        }
    }
}
```

In this example, the <code>Math</code> class is defined as a partial class across two separate files. The <code>Main</code> program can then access and utilize both the <code>Add</code> and <code>Subtract</code> methods defined in the separate files.

#### Origin of Partial Class:

The primary purpose of partial classes is to **_keep developer logic code and UI design code separate_** for better maintainability.

##### Example: Creating a Windows Form in .NET Core

When you create a Windows Form in .NET Core, you'll encounter a class named <code>Form1.cs</code>. The <code>Main</code> method in this class creates an instance of <code>Form1</code> and runs it.

```C#
internal static class Program
{

    static void Main()
    {
        ApplicationConfiguration.Initialize();
        Application.Run(new Form1());
    }
}
```

##### Form1.cs - A Partial Class

The <code>Form1.cs</code> file is a partial class that extends the base <code>Form</code> class. Here's a breakdown of its components:

1. <code>Form1 Constructor</code> (Form1()): This constructor initializes the form's components.
2. <code>InitializeComponent()</code> Method: This method, typically generated by the designer, is responsible for initializing the visual elements (like buttons, text boxes) placed on the form using the designer tool. The code for these elements isn't directly visible in <code>Form1.cs</code>.

```C#
public partial class Form1 : Form
{
    public Form1()
    {
        InitializeComponent();
    }

    private void Form1_Load(object sender, EventArgs e)
    {

    }
}
```

##### Form Designer and Code Generation

When you drag and drop a button from the toolbox in the form designer, the code for that button won't appear within the <code>Form1</code> class itself. Instead, it's defined within the <code>InitializeComponent()</code> method, which resides in a separate partial class for <code>Form1</code>. This separate partial class is auto-generated by the designer tool.

```C#
 #region Windows Form Designer generated code

 /// <summary>
 ///  Required method for Designer support - do not modify
 ///  the contents of this method with the code editor.
 /// </summary>
 private void InitializeComponent()
 {
     button2 = new Button();
     SuspendLayout();
     //
     // button2
     //
     button2.Location = new Point(335, 110);
     button2.Name = "button2";
     button2.Size = new Size(155, 59);
     button2.TabIndex = 2;
     button2.Text = "Click Me";
     button2.UseVisualStyleBackColor = true;
     button2.Click += button2_Click;
     //
     // Form1
     //
     AutoScaleDimensions = new SizeF(8F, 20F);
     AutoScaleMode = AutoScaleMode.Font;
     ClientSize = new Size(800, 450);
     Controls.Add(button2);
     Name = "Form1";
     Text = "Form1";
     ResumeLayout(false);
 }

 #endregion
```

##### Double clicking a Button and Event Handlers

Double-clicking a button on the form in the designer generates a method signature within your <code>Form1</code> class. This method is typically associated with an <code>EventHandler</code> delegate, which handles the logic that gets executed when the button is clicked.

```C#
private void button2_Click(object sender, EventArgs e)
{

}
```

This <code>button2_Click</code> method is designed to handle the button click event. You can write your custom logic within this method to define what happens when the button is pressed.

```C#
 public partial class Form1 : Form
 {
     public Form1()
     {
         InitializeComponent();

     }

     private void button2_Click(object sender, EventArgs e)
     {
         MessageBox.Show("Hi this is Medium");
     }
 }
```

##### Running the Program

When you run the program and click the button, the <code>MessageBox.Show</code> statement you placed within the <code>button2\*Click</code> method will be executed, displaying the message \*\*\*"Hi this is Medium"\_\*\*.

This separation of **_UI design code_** (generated in the separate partial class) and **_developer logic code_** (written in the Form1 class) promotes **_better maintainability and easier collaboration_**.

### Anonymous Method

Anonymous methods and lambda expressions are techniques in C# for defining methods without explicitly creating a named function.

- Introduced in C# 2.0, anonymous methods provide a way to define a method inline where it's used.

- They serve as a foundation for lambda expressions introduced in later versions.

- Anonymous methods are typically used with delegates.

This is our delegate that takes a method that return <code>bool</code> and takes <code>int</code> as a parameter.
And a method <code>Check</code>

```C#
namespace Features
{
    internal class Program
    {
        public delegate bool MyDelegate(int i);
        static void Main(string[] args){
             MyDelegate pointer = new MyDelegate(Check);

            bool result = pointer(20);
            Console.WriteLine(result); // output : False
        }
        public static bool check(int i)
            {
                return i < 10;
            }
    }
}
```

Now instead of passing a method, we are going to pass an **_anonymous method_** to <code>MyDelegate</code>.

##### Example with Delegate and Anonymous Method

```C#
MyDelegate pointer = delegate (int i)
{
    return i < 10;
};
bool result = pointer(20);
Console.WriteLine(result); // output: False
```

We can also pass a **_Lambda Expression_**

```C#
MyDelegate pointer = (i) => i < 10;

bool result = pointer(20);
Console.WriteLine(result); // output : False

```

- Introduced in C# 3.0, lambda expressions offer a more concise syntax for defining anonymous methods.
- They infer the parameter types based on the context (delegate signature) in which they are used.
  **_Lambda Expression_** get type of parameter <code>i</code> by checking the Signature of <code>MyDelegate</code> on it's left.
- The choice between them often depends on personal preference and code readability.

### Nullable Type

Nullable types, introduced in C# 2.0, provide a way to represent the absence of a value for value types (like <code>int, double,</code> etc.) while still maintaining type safety.

- Nullable Type **_allows to assign a null value to a variable_**.
- Introduced in C# 2.0, works with value types and not with reference types.

**_Syntax_**: The syntax for declaring a nullable type is to append a question mark <code>(?)</code> to the base value type. For example, <code>int?</code> represents a nullable integer.

```C#
object obj = null; // OK(reference type with null value)
int salary = 0; // OK(value type with default value)

//int marks = null // NOT OK(value type with null value)

int? marks = null // OK(nullable type with null value)

```

```C#
int? marks = null;

//This is same as

Nullable<int> marks = null;
```

<code>Nullable\<T></code> is a <code>struct</code> where <code>T</code> is also a <code>struct</code> value type.

After we use <code>value type</code> as <code>nullable</code>,
it allows us to use <code>HasValue</code> on variable.

- <code>HasValue</code>: returns <code>true</code> if current <code>Nullable\<T></code> object has value, false if has no value.

```C#
if (salary.HasValue)
{
    Console.WriteLine("Salary is {0}", salary);
}
else
{
    Console.WriteLine("Salary is Null");
}
```

> By using nullable types in your POCO properties, you can accurately reflect the possibility of null values in the corresponding database columns.

### Iterator

It is used to iterate on a class.

Let's consider we have a class named <code>Week</code> with <code>String[] days</code> we want to iterate on days string using <code>foreach</code>.

```C#
public class Week: IEnumerable{
    private string[] days = new string[] {"Mon", "Tue", "Wed",
    "Thu", "Fri", "Sat", "Sun"};

    public IEnumerator GetInumerator(){
        foreach(int i = 0; i < days.Length; i++){
            yield return days[i];
        }
    }
}
```

- <code>IEnumerable</code> interface allows <code>foreach</code> to be called on a class.
- <code>GetEnumerator</code> comes from <code>IEnumerable</code> which will be called by <code>foreach</code>, returns <code>IEnumerator</code> object that can be used to iterate through collection.
- <code>yield</code> stores value of <code>i</code>, it is used to run <code>for-loop</code> in deferred manner, so that every-time it won't return <code>"Mon"</code>.

In our <code>Main</code>

```C#
static void Main(){
    Week week = new Week();
    foreach(var day in week){
        Console.WriteLine(day);
    }
}
```

```output
Mon
Tue
Wed
Thu
Fri
Sat
Sun

```

<code>foreach</code> gives call to <code>GetEnumerator</code> in <code>Week</code>

Wait for C# 3.0 features.