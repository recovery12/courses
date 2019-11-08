#!/bin/bash\nhour=$(date | cut -c12-13)\nif [ "$hour" -ge 0 -a "$hour" -le 11 ]\nthen\n        echo "Good morning"\nelif [ "$hour" -ge 12 -a "$hour" -le 17 ]\nthen\n        echo "Good afternoon"\nelse\n        echo "Good evening"\nfi

