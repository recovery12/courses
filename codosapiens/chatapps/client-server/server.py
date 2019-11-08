#!/usr/bin/python3

import os
import socket

host = "192.168.43.96"
port = 1234 

os.system("figlet \"socket loaded\"")
server_sock = socket.socket()
print("Socket successfully created")

server_sock.bind(('', port))
print("Socket communicating through %s port\n" %(port))

server_sock.listen(5)
con, addr = server_sock.accept()
print("Connection from:", str(addr), "have been established")

while True:
    data = con.recv(1024).decode()
    if str(data) == "bye":
        break
    print("From " + str(addr) + ": " + str(data))
    data = input(" -> ")
    con.send(data.encode())
print("The client have left the connection")
print("Server shutting down")
con.close()
