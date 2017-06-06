/*Colby Holmes*/
/*Delete List atoms*/
/*easy peasy program*/

del(Atom, OldList, NewList) :-
    delete(OldList, Atom, NewList),
    print(NewList).

