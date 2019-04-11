module Datetime = {
  type t = Js.Date.t;
  let wrap = Js.Date.fromString;
  let unwrap = Js.Date.toISOString;
};

module DomainRating = {
  type t =
    | Poor
    | Average
    | Amazing;
  let wrap =
    fun
    | x when x < 33 => Poor
    | x when x < 66 => Average
    | _ => Amazing;
  let unwrap =
    fun
    | Poor => 25
    | Average => 50
    | Amazing => 75;
  let show =
    fun
    | Poor => "Poor"
    | Average => "Average"
    | Amazing => "Amazing";
};
