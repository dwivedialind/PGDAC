//setup apollo server, how to handle data and queries
import { ApolloServer } from "@apollo/server";

// startup server so that we can start listening to requests
//we need type = "module", to use import ES6 modules
import { startStandaloneServer } from "@apollo/server/standalone";

import { typeDefs } from "./schema.js";
import db from "./_db.js";
//server setup

const resolvers = {
  Query: {
    games() {
      return db.games;
    },
    reviews() {
      return db.reviews;
    },
    authors() {
      return db.authors;
    },
    review(_, args) {
      return db.reviews.find((review) => review.id === args.id);
    },
    game(_, args) {
      return db.games.find((game) => game.id === args.id);
    },
    gameT(_, args) {
      return db.games.find((game) => game.title === args.title);
    },
  },
  Mutation: {
    createUser: (parent, { id, name, email, age }, context, info) => {
      const newUser = { id, name, email, age };
      db.users.push(newUser);
      return newUser;
    },
    updateUser(parent, { id, name, email, age }, context, info) {
      let updatedUser = db.users.find((user) => user.id === id);

      updatedUser.name = name;
      updatedUser.age = age;
      updatedUser.email = email;
      return updatedUser;
    },
  },
  Subscription: {
    users() {
      return db.users;
    },
  },
};

const server = new ApolloServer({
  typeDefs,
  resolvers,
  //typeDefs: description of our datatypes and their relation with our datatypes/ describe the data on graph
  // resolvers: bunch of resolver functions that tells us how we respond to queries for different data on the graph
});

//to start a server
const { URL } = await startStandaloneServer(server, {
  listen: { port: 4000 },
});

console.log("Server ready at port ", 4000);
