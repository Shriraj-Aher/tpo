% -------- FACTS --------
positive_word(good).
positive_word(happy).
positive_word(excellent).

negative_word(bad).
negative_word(sad).
negative_word(terrible).

sentence(s1, [good, happy]).
sentence(s2, [bad, terrible]).
sentence(s3, [good, bad]).

% -------- RULES --------
positive_sentiment(S) :-
    sentence(S, Words),
    member(W, Words),
    positive_word(W).

negative_sentiment(S) :-
    sentence(S, Words),
    member(W, Words),
    negative_word(W).

/*
Sample Queries:
?- positive_sentiment(s1).
?- negative_sentiment(s2).
?- positive_sentiment(s3).
?- negative_sentiment(s3).

Sample Output:
true.
true.
true.
true.

Problem: Determine sentiment of sentences using an expert system.
*/