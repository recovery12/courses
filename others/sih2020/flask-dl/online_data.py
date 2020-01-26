#!/usr/bin/python3

import json
import requests

url = 'http://localhost:5000/predict_api'
r = requests.post(url, data=json.dumps({'x1':97.12, 'x2':180.32}))

if r.status_code == 200:
    print(r, r.text)
else:
    print("Something happened")
    print("Didn't get the data")