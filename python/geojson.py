#!/usr/bin/python3

import urllib.request, urllib.parse, urllib.error
import json

serviceurl = 'https://maps.googleapis.com/maps/api/geocode/json?'

while True:
    address = input('Enter Location: ')
    if len(address) < 1:
        break

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
        continue

    print(json.dumps(js, indent=4))
    lat = js['results'][0]['geometry']['location']['lat']
    lng = js['results'][0]['geometry']['location']['lng']
    print("latitude is ", lat, "longitude is ", lng)
    location = js['results'][0]['formatted_address']
    print(location)
