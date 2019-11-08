import random

def blah():
  p = list(range(10))
  a = [1,3,4,5,6,7,8,9,10,13,14,18,19,21,22,23]
  while (len(a) != 0):
    pi = random.choice(p)
    p.remove(pi)
    b = random.choice(a)
    a.remove(b)
    c = random.choice(a)
    a.remove(c)
    print(b,c, pi)

blah()

