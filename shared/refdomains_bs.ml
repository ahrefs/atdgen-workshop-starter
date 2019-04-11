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

let write__1 = (
    Atdgen_codec_runtime.Encode.string
  |> Atdgen_codec_runtime.Encode.contramap (Wrap.Datetime.unwrap)
)
let read__1 = (
  (
    Atdgen_codec_runtime.Decode.string
  ) |> (Atdgen_codec_runtime.Decode.map (Wrap.Datetime.wrap))
)
let write_datetime = (
  write__1
)
let read_datetime = (
  read__1
)
let write__2 = (
    Atdgen_codec_runtime.Encode.int
  |> Atdgen_codec_runtime.Encode.contramap (Wrap.DomainRating.unwrap)
)
let read__2 = (
  (
    Atdgen_codec_runtime.Decode.int
  ) |> (Atdgen_codec_runtime.Decode.map (Wrap.DomainRating.wrap))
)
let write_refdomain = (
  Atdgen_codec_runtime.Encode.make (fun (t : refdomain) ->
    (
    Atdgen_codec_runtime.Encode.obj
      [
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.string
            )
          ~name:"refdomain"
          t.refdomain
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.int
            )
          ~name:"backlinks"
          t.backlinks
        ;
          Atdgen_codec_runtime.Encode.field
            (
            Atdgen_codec_runtime.Encode.int
            )
          ~name:"refpages"
          t.refpages
        ;
          Atdgen_codec_runtime.Encode.field
            (
            write_datetime
            )
          ~name:"first_seen"
          t.first_seen
        ;
          Atdgen_codec_runtime.Encode.field
            (
            write_datetime
            )
          ~name:"last_visited"
          t.last_visited
        ;
          Atdgen_codec_runtime.Encode.field
            (
            write__2
            )
          ~name:"domain_rating"
          t.domain_rating
      ]
    )
  )
)
let read_refdomain = (
  Atdgen_codec_runtime.Decode.make (fun json ->
    (
      ({
          refdomain =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.string
              |> Atdgen_codec_runtime.Decode.field "refdomain"
            ) json;
          backlinks =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.int
              |> Atdgen_codec_runtime.Decode.field "backlinks"
            ) json;
          refpages =
            Atdgen_codec_runtime.Decode.decode
            (
              Atdgen_codec_runtime.Decode.int
              |> Atdgen_codec_runtime.Decode.field "refpages"
            ) json;
          first_seen =
            Atdgen_codec_runtime.Decode.decode
            (
              read_datetime
              |> Atdgen_codec_runtime.Decode.field "first_seen"
            ) json;
          last_visited =
            Atdgen_codec_runtime.Decode.decode
            (
              read_datetime
              |> Atdgen_codec_runtime.Decode.field "last_visited"
            ) json;
          domain_rating =
            Atdgen_codec_runtime.Decode.decode
            (
              read__2
              |> Atdgen_codec_runtime.Decode.field "domain_rating"
            ) json;
      } : refdomain)
    )
  )
)
let write__3 = (
  Atdgen_codec_runtime.Encode.list (
    write_refdomain
  )
)
let read__3 = (
  Atdgen_codec_runtime.Decode.list (
    read_refdomain
  )
)
let write_response = (
  Atdgen_codec_runtime.Encode.make (fun (t : response) ->
    (
    Atdgen_codec_runtime.Encode.obj
      [
          Atdgen_codec_runtime.Encode.field
            (
            write__3
            )
          ~name:"refdomains"
          t.refdomains
      ]
    )
  )
)
let read_response = (
  Atdgen_codec_runtime.Decode.make (fun json ->
    (
      ({
          refdomains =
            Atdgen_codec_runtime.Decode.decode
            (
              read__3
              |> Atdgen_codec_runtime.Decode.field "refdomains"
            ) json;
      } : response)
    )
  )
)
