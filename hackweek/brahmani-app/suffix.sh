#!/bin/bash\n# This adds the suffix to the filename\n# Usage: suffix.sh filename extension\nmv $1 $(echo $1 | sed "s/.*/&$2/")\n
