### [How to run NodeJS from Terminal](https://nodejs.org/en/learn/command-line/run-nodejs-scripts-from-the-command-line)

### [How to read environment variables from Node.js](https://nodejs.org/en/learn/command-line/how-to-read-environment-variables-from-nodejs)

The <code>process</code> core module of Node.js provides the <code>env</code> property which hosts all the environment variables that were set at the moment the process was started.

The below code runs <code>app.js</code> and set <code>USER_ID</code> and <code>USER_KEY</code>

```JS
USER_ID = 239482 USER_KEY = foobar node app.js
```

> This is suitable for testing, however for production, you will probably be configuring some bash scripts to export variables

> Note: process does not require a "require", it's automatically available.

```JS
process.env.USER_ID;
proces.env.USER_KEY;
```

In the same way you can access any custom environment variable you set.

1. Node.js introduced experimental support for <code>.env</code> files.

Now use --env-file flag to specify an environment file while running Node.js applicatioin

```bash
# .env file
PORT = 3000
```

```JS
console.log(process.env.PORT);
```

Run <code>app.js</code> with env variable set in <code>.env</code> file

```bash
node --env-file=.env app.js
```

you can pass multiple <code>--env-file</code> arguments.

```bash
node --env-file=.env --env-file=.development.env app.js
```

> Note: if the same variable is defined in the environment and in the file, the value from the environment takes precedence.
