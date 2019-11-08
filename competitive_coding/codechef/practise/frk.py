t = int(input())

c = 0
strstr = ["ch","he","ef","che","hef"]
for i in range(t):
    name = input()
    for j in range(5):
        if strstr[j] in name:
            c = c + 1
            break
print(c)
