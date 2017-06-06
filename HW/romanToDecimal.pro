/*Colby Holmes*/
/*Mediocre Prolog Program*/
/*by Mediocre Prolog Programmer*/

/*Does not account for incorrectly formatted numbers :(*/

digit(i, 1).
digit(v, 5).
digit(x, 10).
digit(l, 50).
digit(c, 100).
digit(d, 500).
digit(m, 1000).

romanToDecimal(Roman, Arabic) :-
    convert(Roman, 0, Arabic).

convert([], Acc, Acc).

convert([A], Acc, Arabic) :-
    digit(A, AVal),
    Arabic is Acc + AVal.

convert([A, B | Rest], Acc, Arabic) :-
    digit(A, AVal), digit(B, BVal),
    AVal < BVal,
    NewAcc is Acc + BVal - AVal,
    convert(Rest, NewAcc, Arabic).

convert([A, B | Rest], Acc, Arabic) :-
    digit(A, AVal), digit(B, BVal),
    AVal >= BVal,
    NewAcc is Acc + AVal,
    convert([B | Rest], NewAcc, Arabic).

/* Doesn't account for "No" case :( */