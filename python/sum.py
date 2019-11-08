import re

print("Enter the file name: ")
name = input('')
fh = open(name)

tot = 0
y1 = list()
for line in fh:
    y = re.findall('[0-9]+', line)
    y1 = y1 + y

for x in y1:
    tot = tot + int(x)
print(tot)        
