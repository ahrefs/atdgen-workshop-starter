# Atdgen Workshop Starter Project

## Goal

Learn about `atdgen` and how it automates the generation of encoders / decoders to make sure different parts of an application stay type safe. To do so, a small server-client app created with Node.js (via `bs-express`) and ReasonReact is updated through a series of milestones.

## Repo overview

- `bin`: contains the `atdgen` executable, compiled to JavaScript
- `shared`: contains the shared types between client and server
- `src_client`: a ReasonReact app that will be used to visualize the obtained data in the browser
- `src_server`: a server that uses `bs-express` . It exposes an API endpoint (`/refdomains`) that the ReasonReact app in `src_client` will use to fetch data. It includes a file `refdomains.json` with some demo data that represents [referring domains](https://ahrefs.com/api/documentation/refdomains).

## Getting started

    cd atdgen-workshop-starter
    
    # Can use npm too
    yarn install
    
    # Runs the bsb watcher to compile the code on change
    yarn start
    
    # In a separate terminal, start the API and static server
    yarn server

Now, open your browser in [`http://localhost:8000/`](http://localhost:8000/), you should see a table rendered.

## Suggested approach

*Note: new approach proposed here. the old one is kept below*

### Milestone 1: Use bs-json to encode/decode data

1. Start the server by running `yarn server` (or `npm run server`)
2. Write encoders and decoders for `Refdomain.t` in `shared/Refdomain.re`
3. In `src_client/RefdomainsTable.re` show the data fetched on the UI

### Milestone 2: Automate encoders & decoders generation with atdgen

1. Remove `bs-json` from the package and `bsconfig.json`
2. Add the atdgen runtime as dependency: `yarn add @ahrefs/bs-atdgen-codec-runtime`. This runtime is what will allow later to call functions like `Atdgen_codec_runtime.Decode.decode` from the server and client.
3. Replace `[RefDomains.re](http://refdomains.re)` with a new `refdomains.atd` file, based on the types in `Refdomain.re` from milestone 1 (you can see the `examples` folder for a reference).
4. Use atdgen to generate the encoders and decoders automatically
    1. `node bin/atdgen.js -t shared/refdomains.atd` to generate the types
    2. `node bin/atdgen.js -bs shared/refdomains.atd` to generate the functions
5. Use the generated `Refdomains_bs` module to replace the calls to `Refdomains.decodeMain` and `Refdomains.encodeMain`

### Milestone 3: Keep code in sync through ATD generated types

1. Use generated `Refdomains_bs` module to decode the API response and encode it to return to client
2. Change `lastVisited` from `string` to `date`
