import urllib.request, urllib.parse, urllib.error
from bs4 import BeautifulSoup

url = input('Enter - ')
html = urllib.request.urlopen(url).read()
soup = BeautifulSoup(html, 'html.parser')

tags = soup('span')
tot = 0
for tag in tags:
    tot1 = int(tag.contents[0])
    tot = tot + tot1
print(tot)
