(* Auto-generated from "refdomains.atd" *)
              [@@@ocaml.warning "-27-32-35-39"]

type refdomain = {
  refdomain: string;
  backlinks: int;
  refpages: int;
  first_seen: string;
  last_visited: string;
  domain_rating: int
}

type response = { refdomains: refdomain list }
