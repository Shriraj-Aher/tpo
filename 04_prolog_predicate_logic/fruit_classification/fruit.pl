% -------- FACTS --------
fruit(apple).
fruit(banana).

vegetable(carrot).
vegetable(spinach).

sweet(apple).
sweet(banana).

leafy(spinach).
root(carrot).

% -------- RULES --------
is_fruit(X) :-
    fruit(X).

is_vegetable(X) :-
    vegetable(X).

is_sweet_fruit(X) :-
    fruit(X),
    sweet(X).

is_leafy_veg(X) :-
    vegetable(X),
    leafy(X).

is_root_veg(X) :-
    vegetable(X),
    root(X).

/*
Sample Queries:
?- is_fruit(apple).
?- is_vegetable(carrot).
?- is_sweet_fruit(banana).
?- is_leafy_veg(spinach).

Sample Output:
true.
true.
true.
true.

Problem: Classify fruits and vegetables using predicate logic in PROLOG.
*/