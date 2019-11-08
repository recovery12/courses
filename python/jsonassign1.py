#!/usr/bin/python3

import urllib.request, urllib.parse, urllib.error
import json

url = input("Enter location: ")

print("Retrieving", url)
urlop = urllib.request.urlopen(url)
data = urlop.read().decode()
print("Retrieved", len(data))

try:
    js = json.loads(data)
except:
    js = None

no = 0
tot = 0
for num in js['comments']:
    nos = num['count']
    tot = tot + nos
    no = no + 1

print("Count:", no)
print("Sum:", tot)
