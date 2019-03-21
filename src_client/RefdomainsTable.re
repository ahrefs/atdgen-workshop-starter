/* State declaration */
type state =
  | FetchedData
  | Mounted
  | NotInitialized;

/* Action declaration */
type action =
  | DidMount;

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent(__MODULE__);

let s = ReasonReact.string;

let make = _children => {
  /* spread the other default fields of component here and override a few */
  ...component,

  didMount: self => self.send(DidMount),
  initialState: () => NotInitialized,

  /* State transitions */
  reducer: (action, _state) =>
    switch (action) {
    | DidMount =>
      Js.log("Component did mount. Fetching data from `localhost:8000/refdomains` could be added here.");
      ReasonReact.Update(Mounted);
    },

  render: _self => {
    <table>
      <thead>
        <tr> <th> {s("Refdomain")} </th> <th> {s("Backlinks")} </th> </tr>
      </thead>
      <tbody>
        <tr> <td> {s("foo.com")} </td> <td> {s("3")} </td> </tr>
        <tr> <td> {s("bar.com")} </td> <td> {s("6")} </td> </tr>
      </tbody>
    </table>;
  },
};