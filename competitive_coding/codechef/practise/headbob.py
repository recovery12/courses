
t = int(input())

for i in range(t):
    n = int(input())
    s = input()

    if "I" in s:
        print("INDIAN")
    else:
        if "Y" in s:
            print("NOT INDIAN")
        else:
            print("NOT SURE")
