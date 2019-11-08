#!/usr/bin/python3
import urllib.request, urllib.parse, urllib.error

whand = urllib.request.urlopen('http://www.facebook.com/login.php')

counts = dict()
for line in whand:
    words = line.decode().strip()
    for word in words:
        counts[word] = counts.get(word, 0) + 1
print(counts)
