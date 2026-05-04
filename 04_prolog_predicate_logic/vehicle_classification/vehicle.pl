% -------- FACTS --------
vehicle(bike).
vehicle(car).
vehicle(truck).
vehicle(bicycle).

wheels(bike, 2).
wheels(car, 4).
wheels(truck, 6).
wheels(bicycle, 2).

engine(bike).
engine(car).
engine(truck).

no_engine(bicycle).

% -------- RULES --------
is_bike(X) :-
    wheels(X,2),
    engine(X).

is_car(X) :-
    wheels(X,4),
    engine(X).

is_truck(X) :-
    wheels(X,N),
    N > 4,
    engine(X).

is_bicycle(X) :-
    wheels(X,2),
    no_engine(X).

/*
Sample Queries:
?- is_bike(bike).
?- is_car(car).
?- is_truck(truck).
?- is_bicycle(bicycle).

Sample Output:
true.
true.
true.
true.

Problem: Classify vehicles using predicate logic in PROLOG.
*/