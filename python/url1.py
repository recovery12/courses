import urllib.request, urllib.parse, urllib.error

fhand = urllib.request.urlopen('http://www.facebook.com/login.php')
for line in fhand:
    print(line.decode().strip())
