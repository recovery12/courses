
t = int(input())

for i in range(t):
    n = int(input())
    string = list(input())

    no = string.count("1")
    print(sum(range(no+1)))
