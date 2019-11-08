#!/bin/bash
# This script renames the suffix
# Usage: simple-mv.sh filename suffix1 suffix2
mv $1 $(echo $1 | sed "s/$2$/$3/")

