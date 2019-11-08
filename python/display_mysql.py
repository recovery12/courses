#!/usr/bin/python3

def display(ip, port, message):
    print("+"+"-"*68+"+")
    print("|"+"From ("+ip.ljust(16, " ")+", "+port.ljust(5, " ")+"): "+message+("|").rjust(30, " "))
    print("+"+"-"*68+"+")

display("192.168.43.96", "1234", "a")
