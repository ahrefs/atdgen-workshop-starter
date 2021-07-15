let (catch, resolve, then_) = Js.Promise.(catch, resolve, then_);

/* State declaration */
type state =
  | Init
  | FetchingData
  | Error
  | DataReady(list(Refdomains_bs.refdomain));

/* Action declaration */
type action =
  | ComponentMounted
  | DataFetched(list(Refdomains_bs.refdomain))
  | DataFetchingFailed(Js.Promise.error);

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let s = React.string;

[@react.component]
let make = () => {
  /* State transitions */
  let (state, dispatch) =
    React.useReducer(
      (_state, action) =>
        switch (action) {
        | ComponentMounted => FetchingData
        | DataFetchingFailed(err) =>
          Js.log(err);
          Error;
        | DataFetched(json) => DataReady(json)
        },
      Init,
    );
  React.useEffect0(() => {
    Window.fetch("http://localhost:8000/refdomains")
    |> then_(response => response |> Window.json())
    |> then_(json =>
         json
         |> Refdomains_bs.read_response
         |> (decoded => dispatch(DataFetched(decoded.refdomains)) |> resolve)
       )
    |> catch(_error => {
         Js.log(_error);
         dispatch(DataFetchingFailed(_error)) |> resolve;
       })
    |> ignore;
    dispatch(ComponentMounted);
    None;
  });
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
         ->Belt.List.map(item =>
             <tr key={item.refdomain}>
               <td> {s(item.refdomain)} </td>
               <td> {s(string_of_int(item.backlinks))} </td>
               <td> {s(string_of_int(item.domain_rating))} </td>
               <td> {s(item.first_seen)} </td>
             </tr>
           )
         ->Belt.List.toArray
         ->React.array}
      </tbody>
    </table>
  };
};
