t = int(input())

for i in range(t):
    std = int(input())
    fname = list()
    lname = list()
    for j in range(std):
        name = input().split()
        fname.append(name[0])
        lname.append(name[1])
    for j in range(std):
        tmp = fname.copy()
        tmp.remove(fname[j])
        if fname[j] in tmp:
            print(fname[j]+" "+lname[j])
        else:
            print(fname[j])

