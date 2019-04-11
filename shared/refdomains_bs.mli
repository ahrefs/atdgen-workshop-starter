(* Auto-generated from "refdomains.atd" *)
              [@@@ocaml.warning "-27-32-35-39"]

type datetime = Refdomains_t.datetime

type refdomain = Refdomains_t.refdomain = {
  refdomain: string;
  backlinks: int;
  refpages: int;
  first_seen: datetime;
  last_visited: datetime;
  domain_rating: Wrap.DomainRating.t
}

type response = Refdomains_t.response = { refdomains: refdomain list }

val read_datetime :  datetime Atdgen_codec_runtime.Decode.t

val write_datetime :  datetime Atdgen_codec_runtime.Encode.t

val read_refdomain :  refdomain Atdgen_codec_runtime.Decode.t

val write_refdomain :  refdomain Atdgen_codec_runtime.Encode.t

val read_response :  response Atdgen_codec_runtime.Decode.t

val write_response :  response Atdgen_codec_runtime.Encode.t

