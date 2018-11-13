import socket

from sardana import State
from sardana.pool.controller import MotorController, Type, Description,\
    DefaultValue


class CommunicationError(Exception):
    pass


class BlenderBlades(object):

    CMD = 0
    ANS_START = 1
    AXIS_NAMES = {1: "top", 2: "bot", 3: "left", 4: "right"}
    # blender blades axis state to sardana motor state map
    STATES = {"ON": State.On, "MOVING": State.Moving}
    # parameter name position in blender blades answer
    AXIS_ID = 0
    # parameter value position in blender blades answer
    VALUE = 1
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
    
    def get_state(self, axis):
        axis_name = self.AXIS_NAMES[axis]
        ans = self.ask("?state {0}".format(axis_name))
        state_raw = ans.split()[1]
        state = self.STATES[state_raw]
        
        return state
    
    def get_position(self, axis):
        axis_name = self.AXIS_NAMES[axis]
        ans = self.ask("?pos {0}".format(axis_name))
        position_raw = ans.split()[self.VALUE]
        position = float(position_raw)
        return position
    
    def moveMotor(self, axis, position):
        axis_name = self.AXIS_NAMES[axis]      
        ans = self.ask("move {0} {1}".format(axis_name, position))
        
    def GetAxisPar(self, axis, name):
        axis_name = self.AXIS_NAMES[axis]
        name = name.lower()
        if name == "acceleration":
            ans = self.ask("?acc {0}".format(axis_name))
            acc_raw = ans.split()[self.VALUE]
            v = float(acc_raw)
        elif name == "deceleration":
            ans = self.ask("?dec {0}".format(axis_name))
            dec_raw = ans.split()[self.VALUE]
            v = float(dec_raw)
        elif name == "base_rate":
            v = 0
        elif name == "velocity":
            ans = self.ask("?vel {0}".format(axis_name))
            vel_raw = ans.split()[self.VALUE]
            v = float(vel_raw)
        elif name == "step_per_unit":
            v = 1
        return v

    def SetAxisPar(self, axis, name, value):
        axis_name = self.AXIS_NAMES[axis]
        name = name.lower()
        if name == "acceleration":
            self.ask("acc {0} {1}".format(axis_name, value))
        elif name == "deceleration":
            self.ask("dec {0} {1}".format(axis_name, value))
        elif name == "base_rate":
            raise Exception("base_rate is always 0")
        elif name == "velocity":
            self.ask("vel {0} {1}".format(axis_name, value))
        elif name == "step_per_unit":
            raise Exception("step_per_unit is always 1")
            
    def stop(self, axis):      
        self.ask("abort")