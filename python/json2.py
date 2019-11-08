#!/usr/bin/python3

import json

data = '''
[
   {"id":"001",
    "name":"anurag",
    "x":"2"
   } ,
   {
    "id":"002",
    "name":"anuhya",
    "x":"3"
   }
]
'''
info = json.loads(data)
print("Usercount: ", len(data))

for item in info:
    print("Name: ", item['name'])
    print("Id: ", item['id'])
    print("x: ", item['x'])
