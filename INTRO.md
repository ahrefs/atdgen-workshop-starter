# 2 minutes intro to atdgen

### What is atdgen?

`atdgen` is a command-line program that takes as input type definitions in the ATD syntax and produces OCaml code suitable for data serialization and deserialization.

### What is ATD?

ATD stands for "Adaptable Type Definitions". It is a syntax for defining cross-language data types.

### How does it work?

Using ATD requires just 2 steps:

1. Create a file with the `.atd` extension where types are defined using the ATD syntax ([reference](https://atd.readthedocs.io/en/latest/syntax.html))
2. Run `atdgen` (or `node bin/atdgen.js` if you are using the JS-compiled version) to generate the `.ml` files that include the types + the encoder/decoder.
3. It needs two commands, one to generate types and another for the encoders & decoders:
    - `node ./bin/atdgen.js -t ./shared/refdomains.atd`
    - `node ./bin/atdgen.js -bs ./shared/refdomains.atd`

### What does an `.atd` file look like?

    type profile = {
      id : string;
      email : string;
      ~emailValidated : bool;
      name : string;
      ?realName : string option;
      ~aboutMe : string list;
      ?gender : gender option;
      ?dateOfBirth : date option;
    }
    
    type gender = [ Female | Male ]
    
    type date = {
      year : int;
      month : int;
      day : int;
    }

## How does atdgen compare to bs-json and graphql?
| <img src="https://media.giphy.com/media/PkR8XIh9MHEJeqJEAa/giphy.gif" width="200" alt="yoshi" /> | <img src="https://media.giphy.com/media/10RgZyfaX0HBSg/giphy.gif" width="200" alt="mario" /> | <img src="https://media.giphy.com/media/gdeoUMHvEWi5DSjAbh/giphy.gif" width="200" alt="bowser" /> |
|---|---|---|
| **bs-json**| **atdgen**  | **graphql**  |
| Lightweight, easy to get started, <br>but hard to maintain, requires a lot of manual work | Automates code generation of encoders and decoders, <br> fairly easy to setup | Solves all kinds of problems (types, caching, overfetching and others), <br>but heavyweight, requires specific infrastracture  |

#### bs-json

`atdgen` provides more features than `bs-json`, as it doesn't require to write encoders and decoders manually: it automates the generation of those parts through tooling.

#### graphql

`atdgen` is a less "holistic" solution than GraphQL, and because of that, more compatible with any tech stack that your app is using. While GraphQL imposes restrictions on the way it has to be implemented (like the spec defining that ["clients use the GraphQL query language to make requests to a GraphQL service"](https://facebook.github.io/graphql/June2018/#sec-Language)) `atdgen` does not make any assumptions on how different parts might communicate between them, tackling exclusively the problem of encoding and decoding, so the data types are kept in sync.

### Where can I read more about ATD and `atdgen`?

In the official documentation: [https://atd.readthedocs.io](https://atd.readthedocs.io/).

Blog post: ["Getting started with atdgen and BuckleScript"](https://tech.ahrefs.com/getting-started-with-atdgen-and-bucklescript-1f3a14004081).
