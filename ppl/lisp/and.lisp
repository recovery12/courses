#!/usr/bin/clisp

(defconstant x 10)
(defconstant y 30)

(print (if (and (= x 10) (= y 20)) "Both are true" Nil))
