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

sibling(X, Y) :-
    parent(Z, X),
    parent(Z, Y),
    X \= Y.

/*
Sample Queries:
?- father(john, paul).
?- mother(mary, lisa).
?- sibling(paul, lisa).

Sample Output:
true.
true.
true.

Problem: Implement family tree relationships using predicate logic in PROLOG.
*/