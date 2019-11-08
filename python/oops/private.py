#!/usr/bin/python3

class Private():
    def __init__(self, item):
        self.__item = item
    def __str__(self):
        return self.__item

obj = Private("This is private")

#  Accessing private members in this way gives you an AttributeError
#print(obj.__item)

# private members are accessed like this
# object._<class-name>__<attribute>
print(obj._Private__item)
print(obj)
