#!/bin/bash\n# This script renames files by removing a suffix from the filename\n# Usage: unsuffix <filename> <suffix-to-be-removed>\nmv $1 $(echo $1 | sed "s/$2$//")
