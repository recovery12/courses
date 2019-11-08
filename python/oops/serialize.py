#!/usr/bin/python3

"""
    pickle, dbm, shelve are used for serialization
"""

import shelve
from person import Person

tony = Person("Tony Stark", "Iron man", 23000000000)
peter = Person("Peter Parker", "Spider-man")
star = Person("Star Lord")

db = shelve.open("persondb")
for hero in (tony, peter, star):
    db[hero.name] = hero
db.close()

#Retrive data
db = shelve.open("persondb")
print(db.keys())

tony = db['Tony Stark']
print(tony)
db.close()

#Update data
db = shelve.open("persondb")

tony = db["Tony Stark"]
tony.pay = 38000000000
db["Tony Stark"] = tony
db.close()
