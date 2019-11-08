
t = int(input())

def is_char_consec(string, char):
    c = string.count(char)

    if char*c in string+string:
        return True

    return False

def is_perfect():
    if is_char_consec(string, "A") and is_char_consec(string, "B") and is_char_consec(string, "C") and is_char_consec(string, "D"):
        return True
    return False

for i in range(t):
    c = 0
    string = input()
    if is_perfect():
        print(0)
        continue

    for j in range(len(string)-1):
        if string[j] == string[j+1]:
            continue
        else:
            if string[j] in string[j+1:]:
                ind = string[j+1:].index(string[j])
            else:
                continue
            l = list(string)
            l[j+1], l[ind+j+1] = l[ind+j+1], l[j+1]
            if ind+j+2 == len(string):
                l[j-1], l[ind+j-1] = l[ind+j-1], l[j-1]
            else:
                l[j+2], l[ind+j+2] = l[ind+j+2], l[j+2]
            string = "".join(l)
            c = c + 1
            if is_perfect():
                print(c)
                break
