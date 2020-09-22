/* Medical Diagnosis expert system */
go:-
hypothesis(Disease),
write('The patient might have: '),
write(Disease),
nl,
write('Take care!'),
undo.

/* Hypotheses that should be tested */
hypothesis(cold) :- cold, !.
hypothesis(flu) :- flu, !.
hypothesis(typhoid) :- typhoid, !.
hypothesis(measles) :- measles, !.
hypothesis(malaria) :- malaria, !.
/* If none of the other cases match */
hypothesis(unknown).

/* Identification Rules */

cold :-
verify(headache),
verify(runny_nose),
verify(sneezing),
verify(sore_throat),
nl.

flu :-
verify(fever),
verify(headache),
verify(chills),
verify(body_ache),
nl.

typhoid :-
verify(headache),
verify(abdominal_pain),
verify(poor_appetite),
verify(fever),
nl.

measles :-
verify(fever),
verify(runny_nose),
verify(rash),
verify(conjunctivitis),
nl.

malaria :-
verify(fever),
verify(sweating),
verify(headache),
verify(nausea),
verify(vomiting),
verify(diarrhea),
nl.

/* Start asking questions */
ask(Question) :-
write('Does the patient have the following symptom? '),
write(Question),
write(': '),
read(Response),
nl,
( (Response == yes ; Response == y)
->
assert(yes(Question)) ;
assert(no(Question)), fail).

:- dynamic yes/1,no/1.
/* Verification */
verify(S) :-
(yes(S)
 ->
true ;
(no(S)
 ->
fail ;
ask(S))).
/* Undo all yes / no assertions */
%undo :- retract(yes(_)),fail.
%undo :- retract(no(_)),fail.
undo.