t = int(input(""))

def is_pure(string):
    if '0101' in string or '1010' in string:
        return False
    else:
        i = 0
        str1 = '0101'
        for c in string:
            if c == str1[0]:
                i = i + 1

            if i == 4:
                return False

        i = 0
        str1 = '1010'
        for c in string:
            if c == str1[0]:
                i = i + 1

            if i == 4:
                return False

    return True

for i in range(t):
    string = input()

    if is_pure(string):
        print("Is Pure")
