t = int(input())

for i in range(t):
    n = int(input())
    string = input()

    tot = 0
    vowels = "aeiou"
    for i in range(n-1):
        if string[i] not in vowels and string[i+1] in vowels:
            tot = tot + 1
    print(tot)
