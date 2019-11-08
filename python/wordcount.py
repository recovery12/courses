counts = dict()
print('Enter a line of text below')
line = input('')

words = line.split()
print('The words are: ', words)
print('Counting is on progress.......')

for word in words:
    counts[word] = counts.get(word, 0) + 1

print(counts)

