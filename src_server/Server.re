open Express;

let dirname =
  switch ([%bs.node __dirname]) {
  | Some(d) => d
  | None => Js.Exn.raiseError("Could not get __dirname")
  };

let getRefdomainsJson = () => {
  Node.Path.join([|dirname, "Refdomains.json"|])
  ->Node.Fs.readFileAsUtf8Sync
  ->Js.Json.parseExn
  ->Refdomains_bs.read_response;
};

let app = express();

App.disable(app, ~name="x-powered-by");

App.useOnPath(
  app,
  ~path="/",
  {
    Static.defaultOptions() |> Static.make(".") |> Static.asMiddleware;
  },
);

App.get(app, ~path="/refdomains") @@
Middleware.from((_next, _req) =>
  Response.sendJson(getRefdomainsJson()->Refdomains_bs.write_response)
);

let onListen = err =>
  switch (err) {
  | exception (Js.Exn.Error(exn)) =>
    Js.log(exn);
    Node.Process.exit(1);
  | _ => Js.log @@ "Listening at http://localhost:8000"
  };

let server = App.listen(app, ~port=8000, ~onListen, ());
