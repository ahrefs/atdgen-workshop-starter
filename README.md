# Atdgen Workshop Starter Project

Clone this repo to help you start the [atdgen workshop](https://github.com/ahrefs/atdgen-workshop/).

## Prerequisites

Install BuckleScript

```bash
yarn init

# Install bs-platform
yarn add bs-platform --dev

# Add runtime to be used by generated code
yarn add @ahrefs/bs-atdgen-codec-runtime

# Create basic ReasonReact project
yarn bsb -init . -theme react-lite
```

We have compiled atdgen for you into a JavaScript file, you can view its documentation by running `node bin/atdgen.js --help`.

## Suggested approach

### Milestone 1

1. Start the server by running `yarn src/Server.bs.js`
1. Write a function to fetch the `localhost:8000/refdomains` endpoint
1. Add `Refdomains.re` file and define type like this:
   ```
   tbd
   ```
1. Use `bs-json` to decode JSON into your `Refdomains.t` type
1. Create `Index.re` to be your client app entry point
1. Write logic to display referring domains

### Milestone 2

1. Write refdomains.atd file
1. Use generated `Refdomains_bs` module to decode the response

### Milestone 3

1. Use generated `Refdomains_bs` module to decode the API response and encode it to return to client
