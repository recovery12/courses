n = int(input())
inst = list(input())

string = ""
for i in inst:
    if i == "1":
        string = string + "a"
    elif i == "2":
        string = string + "bb"
    elif i == "3":
        string = string + "ab"
    elif i == "4":
        string = string.replace("a", "$")
        string = string.replace("b", "a")
        string = string.replace("$", "b")
print(string)
