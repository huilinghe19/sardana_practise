import socket
import time
import sys

class BlenderBlades(object):
    CMD = 0
    ANS_START = 1
  

    def __init__(self, host, port):
        self._socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self._socket.connect((host, port))

    def __del__(self):
        self._socket.close()

    def ask(self, command):
        command = "{0}\n".format(command)
        try:
            self._socket.sendall(command)
            raw_data = self._socket.recv(4096)
        except:
            raise CommunicationError("send/recv failed")
        data = raw_data.split()
        ans = " ".join(data[self.ANS_START:])
        return ans
        