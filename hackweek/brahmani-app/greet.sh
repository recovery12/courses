#!/bin/bash\nhour=$(date | cut -c12-13)\nif [ "$hour" -ge 0 -a "$hour" -le 11 ]\nthen\n                  echo "Good morning"\nelse\n                  if [ "$hour" -ge 12 -a "$hour" -le 17 ]\n                  then\n                           echo "Good afternoon"\n                  else\n                           echo "Good evening"\n                  fi\nfi

