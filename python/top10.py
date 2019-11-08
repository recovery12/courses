print('Enter the file name: ')
name = input('')
fhand = open(name)

counts = dict()

for line in fhand:
    words = line.split()
    for word in words:
        counts[word] = counts.get(word, 0) + 1

lst = list()
for k, v in counts.items():
    newtup = (v, k)
    print(newtup)
    lst = lst.append(newtup)

lst = sorted(lst, reverse=True)

for val, key in lst[:10]:
    print(key, val)
