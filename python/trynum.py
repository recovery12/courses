
rawstr = input("Enter a number: ")
try:
    ival = int(rawstr)
except:
    ival = -1

if ival > 0 :
    print("Nice job")
else :
    print("Not a num")
