import serial
from time import sleep
from sardana import State, SardanaValue
from sardana.pool.controller import MotorController
from sardana.pool.controller import DefaultValue, Description, FGet, FSet, Type

class SerialObject(object):
    def __init__(self, port):
        self.ser = serial.Serial(port, 9600, timeout=0.5) 
   
    def readPosition(self):  
        ser= self.ser 
        result =""
        while True:
            data =ser.read(1) 
            print "Read::", data
            if not data:
                break
            if data =="\n":
                break
            if data == "\r":
                continue
            result += data
        print result
        position = result[2:]
        print position
        return float(position)
    
    def readStateVariable(self):  
        ser= self.ser 
        result =""
        while True:
            data =ser.read(1) 
            print "Read::", data
            if not data:
                break
            if data =="\n":
                break
            if data == "\r":
                continue
            result += data
        print result
        state_id = result[2:4]
        print state_id
        return int(state_id)
         
    def write(self,data):
        ser=self.ser
        print "Write::", data 
        ser.write(data)
        
    def writePosition(self,position):
        ser=self.ser
        print "Write motor Position::", position
        ser.write("t 1\n")
        
    def writePosition2(self,position):
        ser=self.ser
        print "Write motor2 Position::", position 
        ser.write("2 t 1\n")
        
    def read(self,n):  
        ser= self.ser         
        data =ser.read(n) 
        print "Read::", data
        return data 
    
class CopleyController(MotorController):
   
    ctrl_properties = \
        {
         "Port": {Type : str,
                  Description : "Serial Port",
                  DefaultValue : "/dev/ttyS0"},
        }
    AXIS_NAMES = {1: "stepnet01", 2: "stepnet02"}

    STATES = {"ON": State.On, "OFF": State.Off}
  
    def __init__(self, inst, props, *args, **kwargs):
        MotorController.__init__(self,inst, props, *args, **kwargs)
        #port = self.Port
        self.copleyController = SerialObject("/dev/ttyS0")
        
    def __del__(self):
        del self.copleyController
        
    def StateOne(self, axis):
        axis_name = self.AXIS_NAMES[axis]
        copleyController = self.copleyController
        if axis_name == "stepnet01":            
            copleyController.write("g r0x24\n")  
        elif axis_name == "stepnet02":          
            copleyController.write("2 g r0x24\n") 
        result = copleyController.readStateVariable()
        print result
        if result:           
            state = self.STATES["ON"]
        else: 
            state = self.STATES["OFF"]
        limit_switches = MotorController.NoLimitSwitch
        return state, limit_switches
    
    def ReadOne(self, axis):
        axis_name = self.AXIS_NAMES[axis]
        copleyController = self.copleyController
        if axis_name == "stepnet01":            
            copleyController.write("g r0xa0\n")     
        if axis_name =="stepnet02":
            copleyController.write("2 g r0xa0\n")        
        position = copleyController.readPosition()
        return position
    
    def StartOne(self, axis, position):   
        axis_name = self.AXIS_NAMES[axis]
        copleyController = self.copleyController
        if axis_name =="stepnet01":
            ans = copleyController.write("s r0xca {0}\n t 1\n".format(str(position)))            
        else:
            ans = copleyController.write("{0} s r0xca {1}\n {2} t 1\n".format(str(axis), str(position), str(axis)))   
           
    def AbortOne(self, axis):
        copleyController = self.copleyController
        copleyController.write("r\n 2 r\n")
