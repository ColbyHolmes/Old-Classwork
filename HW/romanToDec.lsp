;Colby Holmes -Worst LISP Programmer-
;Homework 3 Roman Numeral converter
;Can't get it to print errors correctly
;Also takes quoted input instead of lists, I'm really not great at this
;Ex. for '(C D V), the program accepts "CDV"
;(romanToDecimal '(C D V)) ---> (romanToDecimal "CDV")

(defun roman-digit-convert (v)
  "Converts a single roman-numeral into its equivalent value."
  (case v
    ;; Maps each character.
    ;; Returns the value corresponding to V or NIL.
    (#\M 1000)
    (#\D 500)
    (#\C 100)
    (#\L 50)
    (#\X 10)
    (#\V 5)
    (#\I 1)))

(defun roman-convert-help (rest last sum)
  "Converts roman-numerals into numbers. Works on list)."
  (if (consp rest)
    (let ((this (car rest))
          (rest (cdr rest)))

      ;; Recursively call: roman-convert-help on list; if
      ;; the last number was less than this one then subtract the new value,
      ;; else add them.
      (roman-convert-help rest this 
	(funcall (if (< this last)
		#'-
		#'+)
	sum this)))
    sum)) ;Returns sum

(defun romanToDecimal (v)
  "Called to convert a roman-numeral."
  (roman-convert-help
      ;; Calls roman-digit-convert on each item of the newly coerced
      ;; list of characters.
      (reverse(mapcar #'roman-digit-convert
          (coerce v 'list)))
      0 0))


;Ehhhhh I suck at LISP.
;Still doesn't print errors