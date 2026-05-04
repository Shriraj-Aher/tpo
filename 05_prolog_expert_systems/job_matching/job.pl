% -------- FACTS --------
skill(john, python).
skill(john, machine_learning).

skill(alice, accounting).
skill(alice, excel).

skill(bob, java).
skill(bob, dsa).

% -------- RULES --------
job(X, data_scientist) :-
    skill(X, python),
    skill(X, machine_learning).

job(X, accountant) :-
    skill(X, accounting),
    skill(X, excel).

job(X, software_engineer) :-
    skill(X, java),
    skill(X, dsa).

/*
Sample Queries:
?- job(john, data_scientist).
?- job(alice, accountant).
?- job(bob, software_engineer).

Sample Output:
true.
true.
true.

Problem: Build an expert system to match job roles based on skills.
*/