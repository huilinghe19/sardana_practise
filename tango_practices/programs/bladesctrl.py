import socket
  

class CommunicationError(Exception):
    pass

class ClientSocket(object):

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

    
class TopCtrl(object):
    
    AXIS_ID = 0
    VALUE = 1
    MOTOR = 'left'
  
    def __init__(self, host, port):       
        self.blenderBladesSocket = ClientSocket(host,port)
        
    def __del__(self):
        del self.blenderBladesSocket
        
    def get_state(self):     
        blenderBlades = self.blenderBladesSocket
        ans = blenderBlades.ask("?state {0}".format(self.MOTOR))
        state_raw = ans.split()[1]
        return state_raw
    def get_status(self):     
        blenderBlades = self.blenderBladesSocket
        ans = blenderBlades.ask("?state {0}".format(self.MOTOR))
        state_raw = ans.split()[1]       
        if state_raw == 'ON':
            return 'Status is ON'
        elif state_raw == 'MOVING':
            return 'Status is MOVING'
        else:
            return 'Status is UNKNOWN'
        
    def get_position(self):        
        blenderBlades = self.blenderBladesSocket
        ans = blenderBlades.ask("?pos {0}".format(self.MOTOR))
        position_raw = ans.split()[1]
        position = float(position_raw)
        return position    
    
    def moveMotor(self, position):  
        blenderBlades = self.blenderBladesSocket
        blenderBlades.ask("move {0} {1}".format(self.MOTOR, position))
        
    def getAxisPar(self, name):
        blenderBlades = self.blenderBladesSocket
        name = name.lower()
        if name == "acceleration":
            ans = blenderBlades.ask("?acc {0}".format(self.MOTOR))
            acc_raw = ans.split()[1]
            v = float(acc_raw)
        elif name == "deceleration":
            ans = blenderBlades.ask("?dec {0}".format(self.MOTOR))
            dec_raw = ans.split()[1]
            v = float(dec_raw)
        elif name == "base_rate":
            v = 0
        elif name == "velocity":
            ans = blenderBlades.ask("?vel {0}".format(self.MOTOR))
            vel_raw = ans.split()[1]
            v = float(vel_raw)
        elif name == "step_per_unit":
            v = 1
        return v

    def setAxisPar(self, name, value):
        blenderBlades = self.blenderBladesSocket
        name = name.lower()
        if name == "acceleration":
            blenderBlades.ask("acc {0} {1}".format(self.MOTOR, value))
        elif name == "deceleration":
            blenderBlades.ask("dec {0} {1}".format(self.MOTOR, value))
        elif name == "base_rate":
            raise Exception("base_rate is always 0")
        elif name == "velocity":
            blenderBlades.ask("vel {0} {1}".format(self.MOTOR, value))
        elif name == "step_per_unit":
            raise Exception("step_per_unit is always 1")
            
    def stop(self):      
        blenderBlades = self.blenderBladesSocket
        blenderBlades.ask("abort")