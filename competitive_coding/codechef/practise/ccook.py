t = int(input())

stat = ["Beginner", "Junior Developer", "Middle Developer", "Senior Developer", "Hacker", "Jeff Dean"]
for i in range(t):
    num = input().split(" ")
    print(stat[num.count("1")])
