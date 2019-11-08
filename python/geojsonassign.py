#!/usr/bin/python3

import urllib.request, urllib.parse, urllib.error
import json

serviceurl = 'http://py4e-data.dr-chuck.net/geojson?'

address = input('Enter Location: ')
url = serviceurl + urllib.parse.urlencode(
    {'address': address})

print('Retrieving', url)
uh = urllib.request.urlopen(url)
data = uh.read().decode()
print('Retrieved', len(data), 'characters')

try:
    js = json.loads(data)
except:
    js = None

if not js or 'status' not in js or js['status'] != 'OK':
    print('==== faliure To Retrieve ====')
    print(data)

placeid = js['results'][0]['place_id']
print("Place Id", placeid)
