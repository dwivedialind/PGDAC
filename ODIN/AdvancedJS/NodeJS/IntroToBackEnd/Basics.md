# [FrontEnd vs Backend](https://blog.teamtreehouse.com/i-dont-speak-your-language-frontend-vs-backend)

- Front-end developers focus on the user-facing aspect of web application.
- Back-end developers handle the application logic and data management.

- backend is **"data access layer"** and frontend is **presentation layer**.

What is back-end?

- process incoming request and generate and send response to the client.

1. Server: listens for incoming requests.

   > Though there are machines made and optimized for this particular purpose, any computer that is connected to a network can act as a server.

2. The app:

- contains logic about how to respond to various request.
- based on HTTP request methods and URI. The pair of HTTP request and URI is called a **route** and matching them based on a request is called **routing**.

Middleware:

- runs between receiving a request and sending a response.
- can modify the request, access data, or perform other actions.
- usually passes control to the next middleware function.
- One middleware function eventually sends the final response.

3. Databases: to organize and persist data.

# Introduction to Frameworks
