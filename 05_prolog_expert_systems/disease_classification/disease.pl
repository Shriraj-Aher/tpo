% -------- FACTS --------
symptom(fever).
symptom(cough).
symptom(headache).
symptom(fatigue).

has_symptom(john, fever).
has_symptom(john, cough).

has_symptom(alice, headache).
has_symptom(alice, fatigue).

% -------- RULES --------
disease(X, flu) :-
    has_symptom(X, fever),
    has_symptom(X, cough).

disease(X, migraine) :-
    has_symptom(X, headache),
    has_symptom(X, fatigue).

/*
Sample Queries:
?- disease(john, flu).
?- disease(alice, migraine).

Sample Output:
true.
true.

Problem: Identify diseases based on symptoms using an expert system.
*/  