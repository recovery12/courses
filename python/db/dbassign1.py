#!/usr/bin/python3

import sqlite3

conn = sqlite3.connect("assign1db.sqlite")
dbhand = conn.cursor()

dbhand.execute('''CREATE TABLE Counts (org TEXT, count INTEGER)''')
dbhand.execute('''DELETE FROM Counts''')

fname = input("Enter the file name:- ")
if len(fname)<1:
    fname = "mbox.txt"
fhand = open(fname)

for line in fhand:
    if not line.startswith("From "): continue
    email = line.split()
    org = email[1].split('@')
    dbhand.execute('SELECT count FROM Counts WHERE org = ? ', (org[1],))
    row = dbhand.fetchone()

    if row is None:
        dbhand.execute('''INSERT INTO Counts (org, count) VALUES (?, ?)''', (org[1], 1))
    else:
        dbhand.execute('UPDATE Counts SET count = count + 1 WHERE org = ? ',(org[1],))
    conn.commit()

# https://www.sqlite.org/lang_select.html
sqlstr = 'SELECT org, count FROM Counts ORDER BY count DESC LIMIT 1'

for row in dbhand.execute(sqlstr):
    print(str(row[0]), row[1])

dbhand.close()

