% -------- FACTS --------
bird(sparrow).
bird(penguin).

has_feathers(sparrow).
has_feathers(penguin).

can_fly(sparrow).
cannot_fly(penguin).

swims(penguin).

% -------- RULES --------
flying_bird(X) :-
    bird(X),
    has_feathers(X),
    can_fly(X).

penguin_bird(X) :-
    bird(X),
    has_feathers(X),
    cannot_fly(X),
    swims(X).

flightless_bird(X) :-
    bird(X),
    has_feathers(X),
    cannot_fly(X).

/*
Sample Queries:
?- flying_bird(sparrow).
?- penguin_bird(penguin).
?- flightless_bird(penguin).

Sample Output:
true.
true.
true.

Problem: Classify birds using logical properties in PROLOG.
*/