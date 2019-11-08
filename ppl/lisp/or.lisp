#!/usr/bin/clisp

(defconstant x 10)
(defconstant y 30)

(print (if (or (= x 10) (= y 20)) "Both are true" Nil))
