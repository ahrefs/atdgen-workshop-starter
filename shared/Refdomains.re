// Each refDomain object stored in the array of refdomains.json
type t = {
  refdomain: string, // The referring domain that contains at least one link to the target.
  backlinks: int, // Number of backlinks found in the referring domain that link to the target.
  refpages: int, // Number of referring pages found in the referring domain that link to the target.
  firstSeen: string, // Least recent date when the Ahrefs crawler was able to visit the backlinks in the referring domain.
  lastVisited: string, // Most recent date when the Ahrefs crawler was able to visit the backlinks in the referring domain.
  domainRating: int // Domain Rating of the referring domain.
};

// The main type that represents the object stored in refdomains.json
type main = {refDomains: array(t)};

// Encoders

let encodeOne = r =>
  Json.Encode.(
    object_([
      ("refdomain", string(r.refdomain)),
      ("backlinks", int(r.backlinks)),
      ("refpages", int(r.refpages)),
      ("first_seen", string(r.firstSeen)),
      ("last_visited", string(r.lastVisited)),
      ("domain_rating", int(r.domainRating)),
    ])
  );

let encodeArray = arr =>
  arr |> Js.Array.map(encodeOne) |> Json.Encode.jsonArray;

let encodeMain = main =>
  Json.Encode.(object_([("refdomains", encodeArray(main.refDomains))]));

// Decoders

let decodeOne = json =>
  Json.Decode.{
    refdomain: json |> field("refdomain", string),
    backlinks: json |> field("backlinks", int),
    refpages: json |> field("refpages", int),
    firstSeen: json |> field("first_seen", string),
    lastVisited: json |> field("last_visited", string),
    domainRating: json |> field("domain_rating", int),
  };
let decodeArray = json => Json.Decode.(json |> array(decodeOne));

let decodeMain = json =>
  Json.Decode.{refDomains: json |> field("refdomains", decodeArray)};
