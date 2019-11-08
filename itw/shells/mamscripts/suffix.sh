#!/bin/bash
# This adds the suffix to the filename
# Usage: suffix.sh filename extension
mv $1 $(echo $1 | sed "s/.*/&$2/")
