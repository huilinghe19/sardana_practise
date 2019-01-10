"""
This program is a copley controller program for sardana system, sardana muss be opened at first. This file should be put in the folder such as "/controllers" and set this folder as the controller path which can be recognized by sardana, then this controller can be recognized by sardana and set the stepnet01 as the axis 1 of the controller and stepnet02 as the axis 2 of the controller. Then we can get the position of the 2 motors and make them move.  
"""

import serial
from time import sleep
from sardana import State, SardanaValue
from sardana.pool.controller import MotorController
from sardana.pool.controller import DefaultValue, Description, FGet, FSet, Type

class SerialObject(object):
    def __init__(self, port):
        self.ser = serial.Serial(port, 9600, timeout=0.5)
    
    def getCommandResult(self, command):
        ser= self.ser
        result =""        
        ser.write(command)
        print "Write command:", command
        while True:
            data =ser.read(1)
            #print "Read::", data
            if not data:
                break
            if data =="\n":
                break
            if data == "\r":
                continue
            result += data
        print "getCommandResult:", result
        return result

    
    def getNodeID(self, axis):
        """
        get the node id string. Here the node id string of the first motor controller is none,
        the node id string of the second motor controller is 2. 
        """
        
        if axis == 1:
            return ""
        elif axis == 2:
            return "2 "
        
    def setVariable(self, axis, variable_ID, value):
        """
        write data into serial line.
        """
        
        ser=self.ser
        nodeID = self.getNodeID(axis) 
        print  "{}s r{} {}\n".format(nodeID, variable_ID, str(value))
        return self.getCommandResult("{}s r{} {}\n".format(nodeID, variable_ID, value))
    
    def getVariable(self, axis, variable_ID):
        """
        write data into serial line.
        """
        
        ser=self.ser
        nodeID = self.getNodeID(axis) 
        return self.getCommandResult("{}g r{}\n".format(nodeID, variable_ID))
    
    def moveMotor(self, axis):
        """
        move the axis.
        """
        
        ser=self.ser
        nodeID = self.getNodeID(axis) 
        result = self.getCommandResult("{}t 1\n".format(nodeID))   
        return result
    
    def abortMotor(self, axis):
        """
        move the axis.
        """
        
        ser=self.ser
        nodeID = self.getNodeID(axis) 
        self.getCommandResult("{}r\n".format(nodeID))   
        
    def read(self,n):
        """
        read n size bytes from serial line.
        """
        
        ser= self.ser
        data =ser.read(n)
        print "Read ::", data
        return data
    
    def write(self, data):
        """
        write data into serial line.
        """
        ser=self.ser
        print "Write data::", data
        ser.write(data)
        
class CopleyController(MotorController):

    ctrl_properties = \
        {
         "Port": {Type : str,
                  Description : "Serial Port",
                  DefaultValue : "/dev/ttyS0"},
        }
    AXIS_NAMES = {1: "stepnet01", 2: "stepnet02"}

    STATES = {"ON": State.On, "MOVING": State.Moving}

    def __init__(self, inst, props, *args, **kwargs):
        MotorController.__init__(self,inst, props, *args, **kwargs)
        self.copleyController = SerialObject("/dev/ttyS0")

    def __del__(self):
        del self.copleyController

    def StateOne(self, axis):
        """
        Read the axis state. asix can be 1, 2, 3, 4. One axis is defined as one motor in spock. 
      
        """
        axis_name = self.AXIS_NAMES[axis]
        copleyController = self.copleyController       
        result = copleyController.getVariable(axis, "0xA0")       
        if result == "v 0":
            print "State ON, Motion Stopped"
            state = self.STATES["ON"]
        else:
            print "State MOVING, In Moving"
            state = self.STATES["MOVING"]
        limit_switches = MotorController.NoLimitSwitch
        return state, limit_switches

    def ReadOne(self, axis):
        """
        Read the position of the axis(motor). When "wa" or "wm motor_name"is called in spock, 
        this method is used. 
        """
        axis_name = self.AXIS_NAMES[axis]
        copleyController = self.copleyController
        position_raw = copleyController.getVariable(axis, "0x32")
        position = float(position_raw[2:])
        return position

    def StartOne(self, axis, position):
        """
        Move the axis(motor) to the given position. 
        """
        axis_name = self.AXIS_NAMES[axis]
        copleyController = self.copleyController     
        copleyController.setVariable(axis, "0xca", position)
        ans = copleyController.moveMotor(axis)   
      
    def AbortOne(self, axis):
        """
        Abort the axis(motor).
        """
        copleyController = self.copleyController
        copleyController.abortMotor(axis)

  