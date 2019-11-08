#!/usr/bin/python3

import urllib.request, urllib.parse, urllib.error
import xml.etree.ElementTree as ET

url = input("Enter the url: ")
print('Retrieving', url)
uh = urllib.request.urlopen(url)
data = uh.read().decode()
print('Retrieved', len(data), 'characters')

tree = ET.fromstring(data)
counts = tree.findall('comments/comment')

tot = 0
c = 0
for item in counts:
    c = c + 1
    tot = tot + int(item.find('count').text)
print("Count: ", c)
print("Sum: ", tot)
