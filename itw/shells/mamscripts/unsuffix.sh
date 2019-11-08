#!/bin/bash
# This script renames files by removing a suffix from the filename
# Usage: unsuffix <filename> <suffix-to-be-removed>
mv $1 $(echo $1 | sed "s/$2$//")
