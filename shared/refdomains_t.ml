(* Auto-generated from "refdomains.atd" *)
              [@@@ocaml.warning "-27-32-35-39"]

type datetime = Wrap.Datetime.t

type refdomain = {
  refdomain: string;
  backlinks: int;
  refpages: int;
  first_seen: datetime;
  last_visited: datetime;
  domain_rating: Wrap.DomainRating.t
}

type response = { refdomains: refdomain list }
