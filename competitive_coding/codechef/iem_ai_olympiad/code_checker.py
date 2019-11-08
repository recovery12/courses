src_one = input()
src_two = input()

intl1 = set()
floatl1 = set()
charl1 = set()
intl2 = set()
floatl2 = set()
charl2 = set()

def extract_words(src):
    word = ""
    words = list()
    for l in src:
        if (l >= "a" and l <= "z") or (l >= "A" and l <= "Z"):
            word = word + l
        else:
            if word != "":
                words.append(word)
            word = ""
    return words

w1 = extract_words(src_one)
w2 = extract_words(src_two)

for i in range(len(w1)):
    if w1[i] == "int":
        for j in range(i+1, len(w1)):
            if w1[j] not in ["float", "char"]:
                if w1[j] not in ["for", "if", "else"]:
                    intl1.add(w1[j])
            else:
                break
    if w1[i] == "float":
        for j in range(i+1, len(w1)):
            if w1[j] not in ["int", "char"]:
                if w1[j] not in ["for", "if", "else"]:
                    floatl1.add(w1[j])
            else:
                break
    if w1[i] == "char":
        for j in range(i+1, len(w1)):
            if w1[j] not in ["float", "int"]:
                if w1[j] not in ["for", "if", "else"]:
                    charl1.add(w1[j])
            else:
                break
for i in range(len(w2)):
    if w2[i] == "int":
        for j in range(i+1, len(w2)):
            if w2[j] not in ["float", "char"]:
                if w2[j] not in ["for", "if", "else"]:
                    intl2.add(w2[j])
            else:
                break
    if w2[i] == "float":
        for j in range(i+1, len(w2)):
            if w2[j] not in ["int", "char"]:
                if w2[j] not in ["for", "if", "else"]:
                    floatl2.add(w2[j])
            else:
                break
    if w2[i] == "char":
        for j in range(i+1, len(w2)):
            if w2[j] not in ["float", "int"]:
                if w2[j] not in ["for", "if", "else"]:
                    charl2.add(w2[j])
            else:
                break
l = list()
l.extend(intl1.intersection(intl2))
l.extend(floatl1.intersection(floatl2))
l.extend(charl1.intersection(charl2))
l.sort()
for i in range(len(l)-1):
    print(l[i], end=",")
print(l[-1])
