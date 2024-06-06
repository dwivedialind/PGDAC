#### HTTP

```JS
onst http = require('node:http')

const server = http.createServer((request, response) => {
  console.log(`method = ${request.method}`)
  console.log(`path = ${request.url}`)

  if (request.method == 'GET') {
    if (request.url == '/user') {
      console.log(`select * from user`)
    } else if (request.url == '/product') {
      console.log(`select * from product`)
    }
  } else if (request.method == 'POST') {
    if (request.url == '/user') {
      console.log(`insert into user ...`)
    } else if (request.url == '/product') {
      console.log(`insert into product ...`)
    }
  } else if (request.method == 'PUT') {
    if (request.url == '/user') {
      console.log(`update user ...`)
    } else if (request.url == '/product') {
      console.log(`update product ...`)
    }
  } else if (request.method == 'DELETE') {
    if (request.url == '/user') {
      console.log(`delete from user`)
    } else if (request.url == '/product') {
      console.log(`delete from product`)
    }
  }

  response.statusCode = 200
  response.end('this is a test message')
})

server.listen(4000, '0.0.0.0', () => {
  console.log(`server started on port 4000`)
})

```
