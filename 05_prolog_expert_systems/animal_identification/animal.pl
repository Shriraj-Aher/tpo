% -------- FACTS --------
animal(tiger).
animal(eagle).
animal(shark).

has_hair(tiger).
carnivore(tiger).

has_feathers(eagle).
can_fly(eagle).

lives_in_water(shark).
has_gills(shark).

% -------- RULES --------
is_mammal(X) :-
    has_hair(X).

is_bird(X) :-
    has_feathers(X),
    can_fly(X).

is_fish(X) :-
    lives_in_water(X),
    has_gills(X).

/*
Sample Queries:
?- is_mammal(tiger).
?- is_bird(eagle).
?- is_fish(shark).

Sample Output:
true.
true.
true.

Problem: Identify animals based on their characteristics using an expert system.
*/