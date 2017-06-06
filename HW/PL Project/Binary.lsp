;;Colby Holmes
;;Decimal to Binary list

(defun DtoB (n r)
    (if (zerop n)
    r
    (multiple-value-bind (a b)
        (floor n 2)
        (DtoB a (cons b r)))))

(defun Binary (n)
    (if (and (numberp n) (plusp n))
    (DtoB n '())
    (if (eql n 0) '(0) nil)))