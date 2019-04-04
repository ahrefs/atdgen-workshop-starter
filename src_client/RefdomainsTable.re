let (catch, resolve, then_) = Js.Promise.(catch, resolve, then_);

/* State declaration */
type state =
  | Init
  | FetchingData
  | Error
  | DataReady(array(Refdomains.t));

/* Action declaration */
type action =
  | ComponentMounted
  | DataFetched(array(Refdomains.t))
  | DataFetchingFailed(Js.Promise.error);

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent(__MODULE__);

let s = ReasonReact.string;

let make = _children => {
  /* spread the other default fields of component here and override a few */
  ...component,

  didMount: self => self.send(ComponentMounted),

  initialState: () => Init,

  /* State transitions */
  reducer: (action, _state) =>
    switch (action) {
    | ComponentMounted =>
      ReasonReact.UpdateWithSideEffects(
        FetchingData,
        self =>
          Window.fetch("http://localhost:8000/refdomains")
          |> then_(response => response |> Window.json())
          |> then_(json =>
               json
               |> Refdomains.decodeMain
               |> (
                 decoded =>
                   self.send(DataFetched(decoded.refDomains)) |> resolve
               )
             )
          |> catch(_error => {
               Js.log(_error);
               self.send(DataFetchingFailed(_error)) |> resolve;
             })
          |> ignore,
      )
    | DataFetchingFailed(err) =>
      Js.log(err);
      ReasonReact.Update(Error);
    | DataFetched(json) => ReasonReact.Update(DataReady(json))
    },

  render: ({state}) => {
    switch (state) {
    | Init => <p> {s("Component ready")} </p>
    | FetchingData => <p> {s("Fetching data...")} </p>
    | Error =>
      <p> {s("Error while loading data. Check the browser console.")} </p>
    | DataReady(refdomains) =>
      <table>
        <thead>
          <tr>
            <th> {s("Refdomain")} </th>
            <th> {s("Backlinks")} </th>
            <th> {s("Domain rating")} </th>
            <th> {s("First seen")} </th>
          </tr>
        </thead>
        <tbody>
          {refdomains
           ->Belt.Array.map(item =>
               <tr key={item.refdomain}>
                 <td> {s(item.refdomain)} </td>
                 <td> {s(string_of_int(item.backlinks))} </td>
                 <td> {s(string_of_int(item.domainRating))} </td>
                 <td> {s(item.firstSeen)} </td>
               </tr>
             )
           ->ReasonReact.array}
        </tbody>
      </table>
    };
  },
};
