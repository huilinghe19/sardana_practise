import serial
from time import sleep
from sardana import State, SardanaValue
from sardana.pool.controller import MotorController
from sardana.pool.controller import DefaultValue, Description, FGet, FSet, Type

class SerialObject(object):
    def __init__(self, port, baudrate, readTimeout):
        self.ser = serial.Serial(port, baudrate, timeout=readTimeout)
    
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
        return self.getCommandResult("{}s r{} {}\n".format(nodeID, variable_ID, str(int(value))))
    
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
         "Device": {Type : str,
                  Description : "device name",
                  DefaultValue : "/dev/ttyS0"},
            
            "Baudrate": {Type : int,
                  Description : "baud rate",
                  DefaultValue : 9600},
            
            "Timeout": {Type : float,
                  Description : "read timeout",
                  DefaultValue : 0.5},
        }
    AXIS_NAMES = {1: "stepnet01", 2: "stepnet02"}

    STATES = {"ON": State.On, "MOVING": State.Moving}

    def __init__(self, inst, props, *args, **kwargs):
        #MotorController.__init__(self,inst, props, *args, **kwargs)
        super_class = super(CopleyController, self)
        super_class.__init__(inst, props, *args, **kwargs)
        device_name = self.Device
        baudrate = self.Baudrate
        readTimeout = self.Timeout
        self.copleyController = SerialObject(device_name,baudrate, readTimeout)

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
        position_raw = copleyController.getVariable(axis, "0xca")
        position = float(position_raw[2:])
        return position
    
    def DefinePosition(self, axis, position):
        axis_name = self.AXIS_NAMES[axis]
        copleyController = self.copleyController     
        copleyController.setVariable(axis, "0xca", position)

    def StartOne(self, axis, position):
        """
        Move the axis(motor) to the given position. 
        """
        axis_name = self.AXIS_NAMES[axis]
        copleyController = self.copleyController     
        self.DefinePosition(axis, position)
        copleyController.moveMotor(axis)   
        
    def GetAxisPar(self, axis, name):
        axis_name = self.AXIS_NAMES[axis]
        copleyController = self.copleyController    
        name = name.lower()
        if name == "acceleration":
            ans = copleyController.getVariable(axis, "0xcc")           
            acc_raw = ans[2:]
            v = float(acc_raw)
        elif name == "deceleration":
            ans = copleyController.getVariable(axis, "0xcd")           
            dec_raw = ans[2:]
            v = float(dec_raw)
        elif name == "velocity":
            ans = copleyController.getVariable(axis, "0xcb") 
            vel_raw = ans[2:]
            v = float(vel_raw)        

        return v
    
    def SetAxisPar(self, axis, name, value):
        axis_name = self.AXIS_NAMES[axis]
        copleyController = self.copleyController    
        name = name.lower()
        if name == "acceleration":
            copleyController.setVariable(axis, "0xcc", value)           
            
        elif name == "deceleration":
            copleyController.setVariable(axis, "0xcd", value)           
           
        elif name == "velocity":
            copleyController.setVariable(axis, "0xcb", value) 
            
       
    
    def AbortOne(self, axis):
        """
        Abort the axis(motor).
        """
        copleyController = self.copleyController
        copleyController.abortMotor(axis)

