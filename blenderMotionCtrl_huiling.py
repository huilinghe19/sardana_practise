import socket
import time
import blenderBlades
from sardana import State, SardanaValue
from sardana.pool.controller import MotorController
from sardana.pool.controller import DefaultValue, Description, FGet, FSet, Type

class CommunicationError(Exception):
	pass



class BlenderBladesMotorController(MotorController):
   
    ctrl_properties = \
        {"Host": {Type : str,
                  Description : "Host where runs the blander blades server",
                  DefaultValue : "localhost"},
         "Port": {Type : int,
                  Description : "Port the blender blades server listens on",
                  DefaultValue : 9999},
        }
   

    AXIS_NAMES = {1: "top", 2: "bot", 3: "left", 4: "right"}

    STATES = {"ON": State.On, "MOVING": State.Moving}

    AXIS_ID = 0

    VALUE = 1
   

    def __init__(self, inst, props, *args, **kwargs):
        MotorController.__init__(self,inst, props, *args, **kwargs)
        self.blender_blades = blenderBlades.BlenderBlades('127.0.0.1', 9999)
       
    def __del__(self):
        del self.blender_blades

    def StateOne(self, axis):
        axis_name = self.AXIS_NAMES[axis]
        blender_blades = self.blender_blades
        ans = blender_blades.ask("?state {0}".format(axis_name))
        state_raw = ans.split()[self.VALUE]
        state = self.STATES[state_raw]
        limit_switches = MotorController.NoLimitSwitch
        return state, limit_switches

    def ReadOne(self, axis):
        axis_name = self.AXIS_NAMES[axis]
        blender_blades = self.blender_blades
        ans = blender_blades.ask("?pos {0}".format(axis_name))
        position_raw = ans.split()[self.VALUE]
        position = float(position_raw)
        return position

    def StartOne(self, axis, position):
        axis_name = self.AXIS_NAMES[axis]
        blender_blades = self.blender_blades
        ans = blender_blades.ask("move {0} {1}".format(axis_name, position))

    def AbortOne(self, axis):
        blender_blades = self.blender_blades
        blender_blades.ask("abort")

    def GetAxisPar(self, axis, name):
        axis_name = self.AXIS_NAMES[axis]
        blender_blades = self.blender_blades
        name = name.lower()
        if name == "acceleration":
            ans = blender_blades.ask("?acc {0}".format(axis_name))
            acc_raw = ans.split()[self.VALUE]
            v = float(acc_raw)
        elif name == "deceleration":
            ans = blender_blades.ask("?dec {0}".format(axis_name))
            dec_raw = ans.split()[self.VALUE]
            v = float(dec_raw)
        elif name == "base_rate":
            v = 0
        elif name == "velocity":
            ans = blender_blades.ask("?vel {0}".format(axis_name))
            vel_raw = ans.split()[self.VALUE]
            v = float(vel_raw)
        elif name == "step_per_unit":
            v = 1
        return v

    def SetAxisPar(self, axis, name, value):
        axis_name = self.AXIS_NAMES[axis]
        blender_blades = self.blender_blades
        name = name.lower()
        if name == "acceleration":
            blender_blades.ask("acc {0} {1}".format(axis_name, value))
        elif name == "deceleration":
            blender_blades.ask("dec {0} {1}".format(axis_name, value))
        elif name == "base_rate":
            raise Exception("base_rate is always 0")
        elif name == "velocity":
            blender_blades.ask("vel {0} {1}".format(axis_name, value))
        elif name == "step_per_unit":
            raise Exception("step_per_unit is always 1")

