#!/bin/bash

who | grep "^$1 " > /dev/null && echo "$1 is logged in" \
|| echo "$1 is not logged in"
