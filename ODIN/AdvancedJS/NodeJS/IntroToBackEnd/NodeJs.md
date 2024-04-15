#### [Node.js website](https://nodejs.org/en/about/) declares

_As an asynchronous event driven Javascript runtime, Node is designed to build scalable network applications._

- Javascript Runtime: JS was designed to run on browser. Node brings JS out of browser-land. And allows to run JS code on a machine such as server without having to go through a web browser.
  Node has some added functionality not found in browser-based Javascript.

- Asynchronous event driven: when you write your code, you do not try to predict the exact sequence in which every line will run.

  Instead you write your code as a collection of smaller functions that get called in response to specific events such as a network request(event driven).

**Higher Order Functions**: Functions which take function as a parameter or return function are called Higher Order functions.

###### [forEach() vs map()](https://www.freecodecamp.org/news/4-main-differences-between-foreach-and-map/)

1. **The returning value**
   The <code>forEach()</code> method returns <code>undefined</code> and <code>map()</code> returns a new array with transformed values

```JS
const a = [1, 2, 3, 4];

const b = a.forEach((i) => {
  return (i = i + 2);
});
console.log(b); //undefined

const c = a.map((i) => {
  return (i = i + 2);
});
console.log(c); //[3,4,5,6]

```

2. **Ability to chain other methods**
   <code>map()</code> is chainable. That's something we can't do with <code>forEach()</code> because, as you might guess, it returns <code>undefined</code>.

```JS
const a = [1, 2, 3, 4, 5];

const b = a
  .map((x) => x * x)
  .reduce((total, value) => {
    total + value;
  });

console.log(b);

//const c = a.forEach((x) => x * x).reduce((total, value) => total + value);
//Typeerror: Cannot read properties of undefined
console.log(c);
```

3. **Mutability**
   A mutable object is an object whose state can be modified after it is created.

   <code>forEach()</code> and <code>map()</code> does not mutate the array on which it is called. (However <code>callback</code> may do so.)

<code>map()</code> method returns entirely new array. In the case of <code>forEach()</code>, even if it returns <code>undefined</code>, it will mutate the original array with the <code>callback</code>.

4. **Performance Speed**
   <code>forEach()</code> is faster than <code>map()</code>

#### Event Listeners DOM

```JS
const element = document.getElementById("myId");
const inputBox = document.getElementById("myIP");
element.addEventListener("click", (event) => {
  console.log(event.target.value);
});
```

The event object is passed into the callback function by the <code>.addEventListener</code> function.

#### [What is a web server?](https://developer.mozilla.org/en-US/docs/Learn/Common_questions/Web_mechanics/What_is_a_web_server)

The term web server can refer to hardware or software, or both of them working together.

- Hardware: a web server is a computer that stores web server software and a website's component files(ex HTML, images, CSS, JS). connects to internet and support physical data interchange with other devices connected to the web.

- Software: It is an _HTTP_ server. An HTTP server is a software that understands _URLs_(web addresses) and _HTTP_.
  ![enter image description here](https://developer.mozilla.org/en-US/docs/Learn/Common_questions/Web_mechanics/What_is_a_web_server/web-server.svg)

Browser sends a HTTP request to web server, the HTTP server accepts the request, find the requested document and sends it back to the browser, also using HTTP.

- **static web server** - consists of a computer(hardware) with an HTTP server(software). We call it "static" because the server send its hosted files as-is to your browser.

- **dynamic web server** - consists of static web server and application server and database. We call it "dynamic" because the application server updates the hosted files before sending the content to your browser via the HTTP server.
  ![dynamicSite](/assets/dynamicSite.png)

## Deeper dive

#### **Hosting files**:

Files namely HTML documents and their related assets, are hosted on web server.

We need dedicated web server to host all of them because:

1. dedicated web server is typically more avialble.
2. excluding downtime and system trouble, a dedicated web server is always connected to internet.
3. have same IP address all the time. known as dedicated IP address. (Not all ISPs provide a fixed IP address for home lines.)
4. a dedicated web server is typically maintained by a third party.

#### **Communicating through HTTP**

A web server support [HTTP](https://developer.mozilla.org/en-US/docs/Glossary/HTTP). As its name implies, HTTP specifies how to transfer hypertext(linked web documents) betweeen two computers.

A protocol is a set of rules for communication between two computers.

HTTP is a textual, stateless protocol.

> Textual: All commands are plain-text and human-readable.

> Stateless: Neither the server nor the client remember previous communications.
> For example, relying on HTTP alone, a server can't remember a password you typed or remember your progress on an incomplete transaction. You need an application server for tasks like that.

- Usually only clients make HTTP requests, and only to servers. Servers responds to a client's HTTP request. A server can also populate data into a client cache in advance of it being requested, through a mechanism called [server push](https://en.wikipedia.org/wiki/HTTP/2_Server_Push)

- When requesting a file via HTTP, clients must provide the file's URL.
- The web server must answer every HTTP request, at least with an error message.

On a web server, the HTTP server is responsible for processing and answering incoming requests.

- Upon receiving a request, an HTTP server checks if the requested URL matches an existing file.
- If so, the web server send the file content back to the browser. If not, the server will check if it should generate a file dynamically for the request.
- If neither of these options are possible, the web server returns an error message to the browser, most commonly [_404 Not found_]().

[Softwares Needed](https://developer.mozilla.org/en-US/docs/Learn/Common_questions/Tools_and_setup/What_software_do_I_need)

[How to upload Files to Server](https://developer.mozilla.org/en-US/docs/Learn/Common_questions/Tools_and_setup/Upload_files_to_a_web_server)

## [Server-side website programming first steps](https://developer.mozilla.org/en-US/docs/Learn/Server-side/First_steps)

### 1. [Introduction to the server side](https://developer.mozilla.org/en-US/docs/Learn/Server-side/First_steps/Introduction)

Server side code helps to generate dynamic website.

### [Cookie](https://developer.mozilla.org/en-US/docs/Glossary/Cookie)

A cookies is a small piece of information left on a visitor's computer by a website, via a web browser.
Cookie are used to personalize a user's web experience with a website. It may contain the user's preferences or inputs when accessing that website. A user can customize their web browser to accept, reject or delete cookies.

Cookies can be set and modified at the server level using <code>Set-Cookie</code> HTTP header, or with Javascript using document.cookie.

#### Are client side and server-side programming the same?

**Client Side Code vs Server Side Code**

1. improving appearance and behaviour of rendered web page.
   vs
   involves which content to return browser in response to requests. validating submitted data and revert.
   storing data in databases and send correct data to client as required.

2. written in HTML/CSS/JS, little or no access to OS (including limited access to File System).
   vs
   can be written in any programming language, developer can choose what programming language (and specific version ), access to server OS.

3. client-side programming involves handling cross-browser issues.

4. client-side framework simplify layout and presentation tasks.
   vs
   common server-side functionality is to speed up development.

> Both side framework speed-up development, but while creating simple UI websites, writting code by hand is much quicker, but on server-side implementing support for sessions, support for users authentication, easy database access all is hard to do from scratch.

**What you can do on server side?**

Allows efficiently deliever information tailored for individual user thus creating much better user experience.

Common benefits of server-side programming:

1. Efficient storage and delievery of information
   server-side programming allows us to store information in database and dynamically construct and return HTML and other types of files(e.g, PDF, images, etc.)

The server is not limited to sending information from database and might alternatively return the result of software tools or data from communication services.

The content even be targeted for the type of client device receiving it.

2. Customized user experience
   store and use information about user to provide convenient and tailored user experience.
   ex. storing credit card details, use saved and current location my google maps for routing information.

3. Controlled access to content:

restrict access to authorized user only and display only information to user that, user permitted to see.

ex. social network - user can control who can see his posts, and control over his home feed.

4. Store session/state information
   server side programming allows developer to use session information. Basically a mechanism that allows server to store information about the current user of site, and send responses based on that information.

ex: visit a newspaper site with subscription model. continue visit site for over few hours/days. Eventually you will start to redirected to pages explaining how to subscribe, and you will be unable to access articles. This information is an example of session information stored in cookies.

4. Notifications and communication:
   Server can send generated or user-specific notifications.
   ex. each time you open a new account, you receive a mail for "confirmation of registration"

5. Data Analysis:
   A website may collect a lot of data about users. Server-side programming can be used to refine responses based on analysis of this data.

6. ### [Client-Side Overview](https://developer.mozilla.org/en-US/docs/Learn/Server-side/First_steps/Client-Server_overview)

Objective: To understand client-server interactions in a dynamic website and in particular what operations need to be performed by server-side code.

**Web Servers and HTTP(a primer)**
HTTP request to web server includes:

- a <code>URL</code> identifying the target server and resource.
- a method defines the required action:

1. <code>GET</code> get the specific resource
2. <code>POST</code> create a new resource
3. <code>HEAD</code> getting the metadata information about the resource without getting the body as <code>GET</code> would.
   You might for example use a <code>HEAD</code> request to find out the last time a resource was updated, and they only use the _("more expensive")_ <code>GET</code> request to download the resource if it was changed.
4. <code>PUT</code> update an existing resource (or create a new one if it doesn't exist.)

5. <code>DELETE</code> delete the specified resource.

Additional information can be encoded with the request (for example HTML form data)

- <code>URL</code> parameters: <code>GET</code> requests encode data in the URL sent to the server by adding name/value pairs on the end of it-
  for example
  http://example.com>name=fred&age=11

<code>?</code> separating rest of URL from URL parameters.

age(<code>name</code>) = 11(<code>associated value</code>)

<code>&</code> separating each pair

<mark>URL parameters are inherently insecure, as they can be changed by user and resubmitted.
As a result <code>GET</code> requests are not used to update data on sever. </mark>

- <code>POST</code> POST requests add new resource, <mark>for which data is encoded in the request body.</mark>

- <code>Client Side Cookies</code>: Cookies contains session data about the client, including keys that the server can use to determine the login status and permissions(access to resources.)

> HTTP response contains [HTTP Response Status code](https://developer.mozilla.org/en-US/docs/Web/HTTP/Status) and HTTP response message.

When a HTML page is returned it is rendered by browser. As part of processing, browser may discover links to other resouces (e.g an HTML page usually references JS and CSS files), and will send separate HTTP requests to download these files.

**GET request/response example**

1. Each line of the request contains information about it. The first parts is called **header**.

```HTTP
GET /en-US/search?q=client+server+overview&topic=apps&topic=html&topic=css&topic=js&topic=api&topic=webdev HTTP/1.1
Host: developer.mozilla.org
Connection: keep-alive
Pragma: no-cache
Cache-Control: no-cache
Upgrade-Insecure-Requests: 1
User-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/52.0.2743.116 Safari/537.36
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8
Referer: https://developer.mozilla.org/en-US/
Accept-Encoding: gzip, deflate, sdch, br
Accept-Charset: ISO-8859-1,UTF-8;q=0.7,*;q=0.7
Accept-Language: en-US,en;q=0.8,es;q=0.6
Cookie: sessionid=6ynxs23n521lu21b1t136rhbv7ezngie; csrftoken=zIPUJsAZv6pcgCBJSCj1zU6pQZbfMUAT; dwf_section_edit=False; dwf_sg_task_completion=False; _gat=1; _ga=GA1.2.1688886003.1471911953; ffo=true

```

- type of request(<code>GET</code>).
- target resource URL (<code>/en-US/search</code>)
- the URL parameters
- the target/host website
- The end of the first line also includes a short string identifying the specific protocol version (<code>HTTP/1.1</code>)
- The final line contains information about the client-side cookies.

The remaining lines contain information about the browser used and the sort of responses it can handle.

- <code>User-Agent</code> my browser
- <code>Accept-Encoding:gzip</code> it can accept gzip compressed information.
- <code>Accept-Charset</code> it can accept specified set of characters
  <code>Accept-language</code>
- <code>Referer</code> indicates the address of the web page that contained the link to this resource

> HTTP request can also have a body, but it is empty in this case.

2. The response:

- response status code
- <code>Content-Type</code> - response is <code>text/html</code>
- <code>charset=utf-8</code> -<code>Content-Length</code>

Then there is response body

**POST request/response example**

1. The HTTP <code>POST</code> is made when you submit a form containing information to be saved on the server.
   The format of request is almost same as <code>GET</code>, the main difference is that the URL doesn't have any parameters.

> Static sites are excellent when you have a small number of pages and you want to send the same content to every user. However they can have a significant cost to maintain as the nu,ber of pages becomes larger.
