import time

from socket import *
from time import ctime

print('\nKartalGozu-Kontrol.Yazilimi by Halil Ibrahim ILHAN\n')


HOST = ''
PORT = 21567
BUFSIZE = 1024
ADDR = (HOST, PORT)

tcpSerSock = socket(AF_INET, SOCK_STREAM)
tcpSerSock.bind(ADDR)
tcpSerSock.listen(5)

while True:
    print('Waiting for connection')
    tcpCliSock, addr = tcpSerSock.accept()
    print('...connected from :', addr)
    data = ''
    while True:
        data += tcpCliSock.recv(BUFSIZE).decode()

        if not "." in data:
            continue

        print(data)
        break
        data = ''

# tcpSerSock.close(); # in the top condition now
