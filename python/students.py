#!/usr/bin/python3

f1 = input("Enter the first file: ")
f2 = input("Enter the second file: ")

fhand1 = open(f1)
fhand2 = open(f2)

std = list()
for std1 in fhand1:
    std1 = std1.rstrip()
    std.append(std1)

for std2 in fhand2:
    if std2 in std:
        std.remove(std2)

print(std)
