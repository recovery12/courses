#!/usr/bin/clisp

(write-line "I am not a comment")

; I am a comment

#|
   This is a
   multi-line comment
|#

(defvar val 57)
(print val)
