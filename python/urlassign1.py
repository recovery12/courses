import urllib.request, urllib.parse, urllib.error
from bs4 import BeautifulSoup

n = input('Enter count: ')
n = int(n)
p = input('Enter position: ')
p = int(p)

url = input('Enter - ')
print(url)
i = 0
while n > 0:
    html = urllib.request.urlopen(url).read()
    soup = BeautifulSoup(html, 'html.parser')

    tags = soup('a')

    for tag in tags:
        url = tag.get('href', None)
        i = i + 1
        if i == p:
            i = 0
            #print(url)
            break
    n = n - 1
pieces = url.split('_')
name = pieces[2].split('.')
print(name[0])
