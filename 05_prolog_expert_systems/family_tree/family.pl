% -------- FACTS --------
male(john).
male(paul).

female(mary).
female(lisa).

parent(john, paul).
parent(mary, paul).
parent(john, lisa).
parent(mary, lisa).

% -------- RULES --------
father(X, Y) :-
    parent(X, Y),
    male(X).

mother(X, Y) :-
    parent(X, Y),
    female(X).

grandparent(X, Y) :-
    parent(X, Z),
    parent(Z, Y).

ancestor(X, Y) :-
    parent(X, Y).

ancestor(X, Y) :-
    parent(X, Z),
    ancestor(Z, Y).

/*
Sample Queries:
?- father(john, paul).
?- grandparent(john, lisa).
?- ancestor(john, lisa).

Sample Output:
true.
true.
true.

Problem: Build an expert system for family relationships using logical inference.
*/