;;Colby Holmes 
;;Homework 3 
;;Problem 2

(defun del (atom list) ;;takes atom and list
  (cond
    ((null list) nil) ;;check for null condition
    ((atom (car list))
    (cond ;;if the atom is in the list, take it out
      ((eq (car list) atom) (del atom (cdr list)))
      (t (cons (car list) (del atom (cdr list))))
    )
  )
  (t (cons (del atom (car list)) (del atom (cdr list))))
  )
)