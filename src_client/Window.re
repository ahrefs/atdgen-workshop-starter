// Some bindings to functions available in the browser global `window` object

type response;

// https://developer.mozilla.org/en-US/docs/Web/API/WindowOrWorkerGlobalScope/fetch
[@bs.val] external fetch: string => Js.Promise.t(response) = "";
// https://developer.mozilla.org/en-US/docs/Web/API/Body/json
[@bs.send.pipe: response] external json: unit => Js.Promise.t(Js.Json.t) = "";