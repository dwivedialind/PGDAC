### Introduction

1. **_API_**: interface with which people can interact with data.

### Graph QL

[Youtube Link](https://youtu.be/5199E50O7SI?si=Bb-fIivLHWGoWwSz)

[CourseCode](https://github.com/iamshaunjp/graphql-crash-course)

- GraphQL is a Query Language(specific syntax) developed by facebook.
  - use http under the hood
  - used to fetch and mutate data from DB Server.
- Alternative to using a RESP API(architecture)

```Query
Query{
    books{
        title,
        author,
        price
    }
}

```

#### REST API

##### Endpoints:

- pokemonsite.com/api/pokemon
- pokemonsite.com/api/pokemon/123

##### Drawbacks

- Over Fetching: Getting back more data than we need

mysite.com/api/courses/1 ----------->

```sql
{
    "id": "1",
    "title": "Thud",
    "author": {...},
    "price" : "10.99",
    "video-url" : "....",
}

```

What, if we need <code>id</code> only

- Under Fetching: Getting back less data then we need

Need to make different requests to different endpoints to get all the data.

mysite.com/api/courses/1 ----------->

```json
{
    "id": "1",
    "title": "Thud",
    "author": {...},
    "price" : "10.99",
    "video-url" : "....",
}
```

But what if we need information about author also, then we have to make more such requests

mysite.com/api/author/1

**_ These things can be combatted using GraphQL _**

#### GraphQL

##### Single Endpoint

- mygraphqlsite.com/graphql

In REST API there are different api for <code>GET POST PUT DELETE</code>

- We send Query with api, with what specific things we want to overcome **Over Fetching**.

```sql
Query{
    courses{
        id,
        title,
        thumbnail_url
    }
}
```

- fetch nested related data, overcome **under fetching** using single query.

```sql
Query{
    course(id: "1"){
        id,
        title,
        thumbnail_url,
        author{
            name,
            id,
            courses{
                id,
                title,
                thumbnail_url
            }
        }
    }
}


```

- GraphQL is **_strongly-typed_**, and with that you can validate a query within the GraphQL type system before execution.
  > When a client submits a GraphQL query, it's validated against the schema.
- Perform Mutations with GraphQL(DML operations)

> We're going to use Apollo same as Postman to test API's.

[APollo Sandbox](https://studio.apollographql.com/sandbox/explorer)

#### How to make queries

```sql
query <name_for_query>{
    <resources>{
        <fields that we want to retrieve>
    }
}

```

```sql
query ReviewsQuery{
    reviews{
        rating,
        content,
        id
        author{
            name
        }
    }
}


```

#### GraphQL Server

[Getting Started](https://www.apollographql.com/docs/apollo-server/getting-started/)

1.  typedefs:

        - definitions of types of data that we expose on our graph ex: author, game
        - Types are custom objects that represent how your API is going to look.
        - Types have fields, and these fields return a specific type of data.

    ```sql

    type User {
    id: ID!
    name: String!
    email: String!
    age: Int
    }

    ```

- schema:
  - describe the shape of graphs and data available on it.
  - SDL(Schema Definition Language) is used to write schemas. SDL won't change with technology.

2. Query Variables:

```sql
query ReviewQuery($id: ID!) {
  review(id: $id){
    rating,
    content
  }
}


```

3. Mutations: Performing CUD operations

4. Subscriptions: way to maintain a real-time connection with a server.
   When something is updated in the server, the server will run the GraphQL query specified in the subscription, and send a newly updated result to the client.
