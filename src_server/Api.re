open Express;

let dirname =
  switch ([%bs.node __dirname]) {
  | Some(d) => d
  | None => Js.Exn.raiseError("Could not get __dirname")
  };

let getRefdomainsJson = () => {
  Node.Fs.readFileAsUtf8Sync(Node.Path.join([|dirname, "Refdomains.json"|]))
  |> Js.Json.parseExn;
};

let app = express();

App.disable(app, ~name="x-powered-by");

App.get(app, ~path="/refdomains") @@
Middleware.from((next, req) =>
  switch (Request.baseUrl(req)) {
  | "" => Response.sendJson(getRefdomainsJson())
  | _ => next(Next.route)
  }
);

let onListen = e =>
  switch (e) {
  | exception (Js.Exn.Error(e)) =>
    Js.log(e);
    Node.Process.exit(1);
  | _ => Js.log @@ "Listening at http://127.0.0.1:8000"
  };

let server = App.listen(app, ~port=8000, ~onListen, ());