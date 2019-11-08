#!/usr/bin/python3

import socket

host = input("Enter the IP of server: ")
port = int(input("Enter the port number of server: "))

client_sock = socket.socket()

try:
    client_sock.connect((host, port))
except:
    print("Server is LOW")
    quit()

i = 0
while True:
    i = i + 1
    message = input(" -> ")
    client_sock.send(message.encode())
    print(i)
    data = client_sock.recv(1024).decode()
    print("Recevied from server: " + data)
    if message.lower().strip() == "bye":
        break
client_sock.send("bye".encode())
client_sock.close()
