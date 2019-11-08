#!/usr/bin/python3

"""
 A demo
"""

class Person():
    def __init__(self, name, job=None, pay=0):
        self.name = name
        self.job = job
        self.pay = pay
    def __repr__(self):
        return "[Name job pay]::%s %s %d"% (self.name, self.job, self.pay)

if __name__ == '__main__':
    tony = Person("Tony Stark", "Iron man", 23000000000)
    steve = Person("Steve Roger", "Captain", 43000)
    peter = Person("Peter Parker", "Spider-man", 30000)

    for hero in [tony, steve, peter]:
        print(hero)
