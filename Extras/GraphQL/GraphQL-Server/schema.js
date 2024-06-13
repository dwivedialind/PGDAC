export const typeDefs = `#graphql
    type Game {
        id: ID!
        title: String!
        platform: [String!]! 
        reviews: [String!]
    }
    type Review{
        id: ID!
        rating: Int!
        content: String!
        game: Game!
        author: Author!
    }
    type Author{
        id: ID!
        name: String!
        verified: Boolean!
        reviews: [String!]
    }
    type User{
        id: ID!
        name: String!
        email: String!
        age: Int
    }
    type Query{
        reviews: [Review]
        review(id: ID!): Review
        game(id: ID!): Game
        gameT(title: String!): Game
        games: [Game]
        authors: [Author]
    }
    type Mutation{
        createUser(id: ID!, name: String!, email: String!, age: Int): User!
        updateUser(id: ID!, name: String!, email: String!, age: Int): User!
        deleteUser(id: ID!): User!
    }

    type Subscription{
        users : [User]
    }

`;
//scalar types: int, float, string, boolean, ID()
//! can not be null
//type Query define entry and exit points
