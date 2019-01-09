"""
This program is a copley controller program for sardana system, it should be put in the folder such as "/controllers" and set this folder as the controller path which can be recognized by sardana, then this controller can be recognized by sardana and set the stepnet01 as the axis 1 of the controller and stepnet02 as the axis 2 of the controller. Then we can get the position of the 2 motors and make them move.  
"""

import serial
from time import sleep
from sardana import State, SardanaValue
from sardana.pool.controller import MotorController
from sardana.pool.controller import DefaultValue, Description, FGet, FSet, Type

class SerialObject(object):
    def __init__(self, port):
        self.ser = serial.Serial(port, 9600, timeout=0.5)

    def readPosition1(self):
        """
        read the first motor position.
        """
        ser= self.ser
        result =""
        ser.write("g r0xa0\n")
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

    def readPosition2(self):
        """
        read the second motor position, which has node ID of 2.
        """
        ser= self.ser
        result =""
        ser.write("2 g r0xa0\n")
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

    def readStateVariable1(self):
        """
        read the first motor state variable.
        """
        ser= self.ser
        result =""
        ser.write("g r0x24\n")
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

    def readStateVariable2(self):
        """
        read the second motor state variable.
        """
        ser= self.ser
        result =""
        ser.write("2 g r0x24\n")
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

    def setMotorPosition1(self, position):
        """
        set the position of the first motor.
        """
        ser= self.ser
        result =""
        ser.write("s r0xca {}\n".format(position))

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
        return result

    def setMotorPosition2(self, position):
        """
        set the position of the second motor.
        """
        ser= self.ser
        result =""
        ser.write("2 s r0xca {}\n".format(position))

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
        return result

    def moveMotor2(self):
        """
        move the second motor.
        """
        ser= self.ser
        result =""
        ser.write("2 t 1\n")
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
        return result

    def moveMotor1(self):
        """
        move the first motor.
        """
        ser= self.ser
        result =""
        ser.write("t 1\n")
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
        return result

    def write(self,data):
        """
        write data into serial line.
        """
        ser=self.ser
        print "Write::", data
        ser.write(data)

    def read(self,n):
        """
        read n size bytes from serial line.
        """
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
        self.copleyController = SerialObject("/dev/ttyS0")

    def __del__(self):
        del self.copleyController

    def StateOne(self, axis):
        """
        Read the axis state. asix can be 1, 2, 3, 4. One axis is defined as one motor in spock console. A normal motor controller has 4 axis, which means one motor controller can controll 4 motors. This method is used when "motor1.state()" is called in spock. Before executing the actions like read position or move, the sardana system check the states of the motor. 
        """
        axis_name = self.AXIS_NAMES[axis]
        copleyController = self.copleyController
        if axis_name == "stepnet01":
            result = copleyController.readStateVariable1()
        elif axis_name == "stepnet02":
            result = copleyController.readStateVariable2()
        print result
        if result:
            state = self.STATES["ON"]
        else:
            state = self.STATES["OFF"]
        limit_switches = MotorController.NoLimitSwitch
        return state, limit_switches

    def ReadOne(self, axis):
        """
        Read the position of the axis(motor). When "wa" or "wm motor_name"is called in spock, this method is used. 
        """
        axis_name = self.AXIS_NAMES[axis]
        copleyController = self.copleyController
        if axis_name == "stepnet01":
            position = copleyController.readPosition1()
        elif axis_name =="stepnet02":
            position = copleyController.readPosition2()
        return position

    def StartOne(self, axis, position):
        """
        Move the axis(motor) to the given position. 
        """
        axis_name = self.AXIS_NAMES[axis]
        copleyController = self.copleyController
        if axis_name =="stepnet01":
            a = copleyController.setMotorPosition1(position)
            if a:
                ans = copleyController.moveMotor1()
            else:
                print a

        elif axis_name =="stepnet02":
            a = copleyController.setMotorPosition2(position)
            if a:
                ans = copleyController.moveMotor2()
            else:
                print a

    def AbortOne(self, axis):
        """
        Abort the axis(motor).
        """
        copleyController = self.copleyController
        copleyController.write("r\n 2 r\n")
