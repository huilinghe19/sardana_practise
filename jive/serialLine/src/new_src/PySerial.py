#!/usr/bin/env python
# -*- coding:utf-8 -*-


# ############################################################################
#  license :
# ============================================================================
#
#  File :        PySerial.py
#
#  Project :     TANGO Device Server
#
# This file is part of Tango device class.
# 
# Tango is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# Tango is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with Tango.  If not, see <http://www.gnu.org/licenses/>.
# 
#
#  $Author :      null$
#
#  $Revision :    $
#
#  $Date :        $
#
#  $HeadUrl :     $
# ============================================================================
#            This file is generated by POGO
#     (Program Obviously used to Generate tango Object)
# ############################################################################

__all__ = ["PySerial", "PySerialClass", "main"]

__docformat__ = 'restructuredtext'

import PyTango
import sys
# Add additional import
#----- PROTECTED REGION ID(PySerial.additionnal_import) ENABLED START -----#
import serial
import array

#----- PROTECTED REGION END -----#	//	PySerial.additionnal_import

# Device States Description
# ON : Serial Port Open
# FAULT : 
# OFF : 


class PySerial (PyTango.Device_4Impl):
    """Python Serial Line device server for  windows and linux"""
    
    # -------- Add you global variables here --------------------------
    #----- PROTECTED REGION ID(PySerial.global_variables) ENABLED START -----#
    PARITIES = ["none", "odd" , "even"]
    FLOWCONTROL = ["none" , "software", "hardware", "sw/hw"]
    TERMINATOR = ["LF/CR", "CR/LF", "CR", "LF", "NONE"]
    TERMINATORCHAR = ["\n\r", "\r\n", "\r", "\n", ""]

    #----- PROTECTED REGION END -----#	//	PySerial.global_variables

    def __init__(self, cl, name):
        PyTango.Device_4Impl.__init__(self,cl,name)
        self.debug_stream("In __init__()")
        PySerial.init_device(self)
        #----- PROTECTED REGION ID(PySerial.__init__) ENABLED START -----#
        self.configure = True
        self.serial = serial.Serial()

        self.baudrate = 9600
        self.serial.baudrate = self.baudrate

        self.port = "/dev/ttyS0"
        self.serial.port =  self.port

        self.bytesize = 8
        self.serial.bytesize = self.bytesize

        self.parity = PySerial.PARITIES[0]
        self.current_parity = self.parity
        self.serial.parity = serial.PARITY_NONE
        self.stopbits = 1
        self.serial.stopbits = self.stopbits

        self.timeout = 0
        self.serial.timeout = self.timeout

        self.flowcontrol = PySerial.FLOWCONTROL[0]
        self.current_flowcontrol = self.flowcontrol
        self.serial.xonxoff = 0
        self.serial.rtscts = 0

        self.terminator = PySerial.TERMINATOR[0]
        self.terminatorchar = PySerial.TERMINATORCHAR[0]
        #----- PROTECTED REGION END -----#	//	PySerial.__init__
        
    def delete_device(self):
        self.debug_stream("In delete_device()")
        #----- PROTECTED REGION ID(PySerial.delete_device) ENABLED START -----#
        print "[Device delete_device method] for device",self.get_name()
        #----- PROTECTED REGION END -----#	//	PySerial.delete_device

    def init_device(self):
        self.debug_stream("In init_device()")
        self.get_device_properties(self.get_device_class())
        self.attr_Port_read = ""
        self.attr_Baudrate_read = 0
        self.attr_DataBits_read = 0
        self.attr_StopBits_read = 0
        self.attr_Terminator_read = ""
        self.attr_FlowControl_read = ""
        self.attr_Timeout_read = 0
        self.attr_Parity_read = ""
        self.attr_InputBuffer_read = 0
        #----- PROTECTED REGION ID(PySerial.init_device) ENABLED START -----#
        self.set_state(PyTango.DevState.OFF)
        print "In ", self.get_name(), "::init_device()"

        #----- PROTECTED REGION END -----#	//	PySerial.init_device

    def always_executed_hook(self):
        self.debug_stream("In always_excuted_hook()")
        #----- PROTECTED REGION ID(PySerial.always_executed_hook) ENABLED START -----#
        print "In ", self.get_name(), "::always_excuted_hook()"
        #----- PROTECTED REGION END -----#	//	PySerial.always_executed_hook
    
    # -------------------------------------------------------------------------
    #    PySerial read/write attribute methods
    # -------------------------------------------------------------------------
    
    def read_Port(self, attr):
        self.debug_stream("In read_Port()")
        #----- PROTECTED REGION ID(PySerial.Port_read) ENABLED START -----#
        attr_Port_read = self.serial.port
        attr.set_value(attr_Port_read)


        #----- PROTECTED REGION END -----#	//	PySerial.Port_read
        
    def write_Port(self, attr):
        self.debug_stream("In write_Port()")
        #data = attr.get_write_value()
        #----- PROTECTED REGION ID(PySerial.Port_write) ENABLED START -----#
        print "In ", self.get_name(), "::write_Port()"
        
       
 
        attr.get_write_value(data)
      
        
        self.configure = True


        #----- PROTECTED REGION END -----#	//	PySerial.Port_write
        
    def read_Baudrate(self, attr):
        self.debug_stream("In read_Baudrate()")
        #----- PROTECTED REGION ID(PySerial.Baudrate_read) ENABLED START -----#
        attr.set_value(self.attr_Baudrate_read)
        
        #----- PROTECTED REGION END -----#	//	PySerial.Baudrate_read
        
    def write_Baudrate(self, attr):
        self.debug_stream("In write_Baudrate()")
        data = attr.get_write_value()
        #----- PROTECTED REGION ID(PySerial.Baudrate_write) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	PySerial.Baudrate_write
        
    def read_DataBits(self, attr):
        self.debug_stream("In read_DataBits()")
        #----- PROTECTED REGION ID(PySerial.DataBits_read) ENABLED START -----#
        attr.set_value(self.attr_DataBits_read)
        
        #----- PROTECTED REGION END -----#	//	PySerial.DataBits_read
        
    def write_DataBits(self, attr):
        self.debug_stream("In write_DataBits()")
        data = attr.get_write_value()
        #----- PROTECTED REGION ID(PySerial.DataBits_write) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	PySerial.DataBits_write
        
    def read_StopBits(self, attr):
        self.debug_stream("In read_StopBits()")
        #----- PROTECTED REGION ID(PySerial.StopBits_read) ENABLED START -----#
        attr.set_value(self.attr_StopBits_read)
        
        #----- PROTECTED REGION END -----#	//	PySerial.StopBits_read
        
    def write_StopBits(self, attr):
        self.debug_stream("In write_StopBits()")
        data = attr.get_write_value()
        #----- PROTECTED REGION ID(PySerial.StopBits_write) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	PySerial.StopBits_write
        
    def read_Terminator(self, attr):
        self.debug_stream("In read_Terminator()")
        #----- PROTECTED REGION ID(PySerial.Terminator_read) ENABLED START -----#
        attr.set_value(self.attr_Terminator_read)
        
        #----- PROTECTED REGION END -----#	//	PySerial.Terminator_read
        
    def write_Terminator(self, attr):
        self.debug_stream("In write_Terminator()")
        data = attr.get_write_value()
        #----- PROTECTED REGION ID(PySerial.Terminator_write) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	PySerial.Terminator_write
        
    def read_FlowControl(self, attr):
        self.debug_stream("In read_FlowControl()")
        #----- PROTECTED REGION ID(PySerial.FlowControl_read) ENABLED START -----#
        attr.set_value(self.attr_FlowControl_read)
        
        #----- PROTECTED REGION END -----#	//	PySerial.FlowControl_read
        
    def write_FlowControl(self, attr):
        self.debug_stream("In write_FlowControl()")
        data = attr.get_write_value()
        #----- PROTECTED REGION ID(PySerial.FlowControl_write) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	PySerial.FlowControl_write
        
    def read_Timeout(self, attr):
        self.debug_stream("In read_Timeout()")
        #----- PROTECTED REGION ID(PySerial.Timeout_read) ENABLED START -----#
        attr.set_value(self.attr_Timeout_read)
        
        #----- PROTECTED REGION END -----#	//	PySerial.Timeout_read
        
    def write_Timeout(self, attr):
        self.debug_stream("In write_Timeout()")
        data = attr.get_write_value()
        #----- PROTECTED REGION ID(PySerial.Timeout_write) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	PySerial.Timeout_write
        
    def read_Parity(self, attr):
        self.debug_stream("In read_Parity()")
        #----- PROTECTED REGION ID(PySerial.Parity_read) ENABLED START -----#
        attr.set_value(self.attr_Parity_read)
        
        #----- PROTECTED REGION END -----#	//	PySerial.Parity_read
        
    def write_Parity(self, attr):
        self.debug_stream("In write_Parity()")
        data = attr.get_write_value()
        #----- PROTECTED REGION ID(PySerial.Parity_write) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	PySerial.Parity_write
        
    def read_InputBuffer(self, attr):
        self.debug_stream("In read_InputBuffer()")
        #----- PROTECTED REGION ID(PySerial.InputBuffer_read) ENABLED START -----#
        attr.set_value(self.attr_InputBuffer_read)
        
        #----- PROTECTED REGION END -----#	//	PySerial.InputBuffer_read
        
    def is_InputBuffer_allowed(self, attr):
        self.debug_stream("In is_InputBuffer_allowed()")
        if attr==PyTango.AttReqType.READ_REQ:
            state_ok = not(self.get_state() in [PyTango.DevState.FAULT,
                PyTango.DevState.OFF])
        else:
            state_ok = not(self.get_state() in [])
        #----- PROTECTED REGION ID(PySerial.is_InputBuffer_allowed) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	PySerial.is_InputBuffer_allowed
        return state_ok
        
    
    
            
    def read_attr_hardware(self, data):
        self.debug_stream("In read_attr_hardware()")
        #----- PROTECTED REGION ID(PySerial.read_attr_hardware) ENABLED START -----#
        print "In ", self.get_name(), "::read_attr_hardware()"
        #----- PROTECTED REGION END -----#	//	PySerial.read_attr_hardware


    # -------------------------------------------------------------------------
    #    PySerial command methods
    # -------------------------------------------------------------------------
    
    def Open(self):
        """ Open serial port
        """
        self.debug_stream("In Open()")
        #----- PROTECTED REGION ID(PySerial.Open) ENABLED START -----#
        print "In ", self.get_name(), "::Open()"

     
        # configure port
        if self.configure:
            self.serial.baudrate = self.baudrate
            self.serial.port = self.port
            self.serial.bytesize = self.bytesize
            self.serial.stopbits = self.stopbits

            self.serial.timeout = self.timeout
            self.current_flowcontrol = self.flowcontrol
            if self.current_flowcontrol == "none":
                self.serial.xonxoff = 0
                self.serial.rtscts = 0
            elif self.current_flowcontrol == "software":
                self.serial.xonxoff = 1
                self.serial.rtscts = 0
            elif self.current_flowcontrol == "hardware":
                self.serial.xonxoff = 0
                self.serial.rtscts = 1
            elif self.current_flowcontrol == "sw/hw":
                self.serial.xonxoff = 1
                self.serial.rtscts = 1

            self.current_parity = self.parity
            if self.current_parity == PySerial.PARITIES[0]:
                self.serial.parity = serial.PARITY_NONE
            elif dself.current_parity == PySerial.PARITIES[1]:
                self.serial.parity = serial.PARITY_ODD
            elif self.current_parity == PySerial.PARITIES[1]:
                self.serial.parity = serial.PARITY_EVEN


        self.serial.open()
        self.set_state(PyTango.DevState.ON)
        self.configure = False

        #----- PROTECTED REGION END -----#	//	PySerial.Open
        
    def is_Open_allowed(self):
        self.debug_stream("In is_Open_allowed()")
        state_ok = not(self.get_state() in [PyTango.DevState.ON,
            PyTango.DevState.FAULT])
        #----- PROTECTED REGION ID(PySerial.is_Open_allowed) ENABLED START -----#
        return True
        #----- PROTECTED REGION END -----#	//	PySerial.is_Open_allowed
        return state_ok
        
    def Close(self):
        """ Close serial line
        """
        self.debug_stream("In Close()")
        #----- PROTECTED REGION ID(PySerial.Close) ENABLED START -----#
        try:
            self.serial.close()
            self.set_state(PyTango.DevState.OFF)
        except:
            pass

        #----- PROTECTED REGION END -----#	//	PySerial.Close
        
    def is_Close_allowed(self):
        self.debug_stream("In is_Close_allowed()")
        state_ok = not(self.get_state() in [PyTango.DevState.OFF])
        #----- PROTECTED REGION ID(PySerial.is_Close_allowed) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	PySerial.is_Close_allowed
        return state_ok
        
    def FlushInput(self):
        """ 
        """
        self.debug_stream("In FlushInput()")
        #----- PROTECTED REGION ID(PySerial.FlushInput) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	PySerial.FlushInput
        
    def is_FlushInput_allowed(self):
        self.debug_stream("In is_FlushInput_allowed()")
        state_ok = not(self.get_state() in [PyTango.DevState.FAULT,
            PyTango.DevState.OFF])
        #----- PROTECTED REGION ID(PySerial.is_FlushInput_allowed) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	PySerial.is_FlushInput_allowed
        return state_ok
        
    def FlushOutput(self):
        """ 
        """
        self.debug_stream("In FlushOutput()")
        #----- PROTECTED REGION ID(PySerial.FlushOutput) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	PySerial.FlushOutput
        
    def is_FlushOutput_allowed(self):
        self.debug_stream("In is_FlushOutput_allowed()")
        state_ok = not(self.get_state() in [PyTango.DevState.FAULT,
            PyTango.DevState.OFF])
        #----- PROTECTED REGION ID(PySerial.is_FlushOutput_allowed) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	PySerial.is_FlushOutput_allowed
        return state_ok
        
    def Write(self, argin):
        """ Write the string to the serial line
        :param argin: 
        :type argin: PyTango.DevString
        """
        self.debug_stream("In Write()")
        #----- PROTECTED REGION ID(PySerial.Write) ENABLED START -----#
        print "In ", self.get_name(), "::Write()"
        #	Add your own code here
        print "char array ", argin
        #s = array.array('B', argin).tostring()
        #value = s + self.terminatorchar
        #print "string " ,value
        self.serial.write(argin+"\n")
        #----- PROTECTED REGION END -----#	//	PySerial.Write
        
    def is_Write_allowed(self):
        self.debug_stream("In is_Write_allowed()")
        state_ok = not(self.get_state() in [PyTango.DevState.FAULT,
            PyTango.DevState.OFF])
        #----- PROTECTED REGION ID(PySerial.is_Write_allowed) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	PySerial.is_Write_allowed
        return state_ok
        
    def Read(self, argin):
        """ 
        :param argin: Characters to read
        :type argin: PyTango.DevUShort
        :return: Characters readed
        :rtype: PyTango.DevString
        """
        self.debug_stream("In Read()")
        argout = ""
        #----- PROTECTED REGION ID(PySerial.Read) ENABLED START -----#
        
        argout =  []
        s = self.serial.read(argin)
        print s
        b = array.array('B', s)
        argout = b.tolist()
       
        return argout
        #----- PROTECTED REGION END -----#	//	PySerial.Read
        return argout
        
    def is_Read_allowed(self):
        self.debug_stream("In is_Read_allowed()")
        state_ok = not(self.get_state() in [PyTango.DevState.FAULT,
            PyTango.DevState.OFF])
        #----- PROTECTED REGION ID(PySerial.is_Read_allowed) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	PySerial.is_Read_allowed
        return state_ok
        
    def ReadLine(self):
        """ 
        :return: Characters readed
        :rtype: PyTango.DevVarCharArray
        """
        self.debug_stream("In ReadLine()")
        argout = [0]
        #----- PROTECTED REGION ID(PySerial.ReadLine) ENABLED START -----#
        argout =  []
        s = self.serial.readline(eol=self.terminatorchar)
        print s
        b = array.array('B', s)
        argout = b.tolist()
        return argout
    
        #----- PROTECTED REGION END -----#	//	PySerial.ReadLine
        return argout
        
    def is_ReadLine_allowed(self):
        self.debug_stream("In is_ReadLine_allowed()")
        state_ok = not(self.get_state() in [PyTango.DevState.FAULT,
            PyTango.DevState.OFF])
        #----- PROTECTED REGION ID(PySerial.is_ReadLine_allowed) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	PySerial.is_ReadLine_allowed
        return state_ok
        

    #----- PROTECTED REGION ID(PySerial.programmer_methods) ENABLED START -----#
   
    #----- PROTECTED REGION END -----#	//	PySerial.programmer_methods

class PySerialClass(PyTango.DeviceClass):
    # -------- Add you global class variables here --------------------------
    #----- PROTECTED REGION ID(PySerial.global_class_variables) ENABLED START -----#
    
    #----- PROTECTED REGION END -----#	//	PySerial.global_class_variables


    #    Class Properties
    class_property_list = {
        }


    #    Device Properties
    device_property_list = {
        }


    #    Command definitions
    cmd_list = {
        'Open':
            [[PyTango.DevVoid, "none"],
            [PyTango.DevVoid, "none"]],
        'Close':
            [[PyTango.DevVoid, "none"],
            [PyTango.DevVoid, "none"]],
        'FlushInput':
            [[PyTango.DevVoid, "none"],
            [PyTango.DevVoid, "none"]],
        'FlushOutput':
            [[PyTango.DevVoid, "none"],
            [PyTango.DevVoid, "none"]],
        'Write':
            [[PyTango.DevString, "none"],
            [PyTango.DevVoid, "none"]],
        'Read':
            [[PyTango.DevUShort, "Characters to read"],
            [PyTango.DevString, "Characters readed"]],
        'ReadLine':
            [[PyTango.DevVoid, "none"],
            [PyTango.DevVarCharArray, "Characters readed"]],
        }


    #    Attribute definitions
    attr_list = {
        'Port':
            [[PyTango.DevString,
            PyTango.SCALAR,
            PyTango.READ_WRITE],
            {
                'Memorized':"true"
            } ],
        'Baudrate':
            [[PyTango.DevShort,
            PyTango.SCALAR,
            PyTango.READ_WRITE],
            {
                'label': "Baudrate",
                'Memorized':"true"
            } ],
        'DataBits':
            [[PyTango.DevShort,
            PyTango.SCALAR,
            PyTango.READ_WRITE],
            {
                'label': "DataBits",
                'max value': "8",
                'min value': "5",
                'Memorized':"true"
            } ],
        'StopBits':
            [[PyTango.DevShort,
            PyTango.SCALAR,
            PyTango.READ_WRITE],
            {
                'label': "StopBits",
                'max value': "2",
                'min value': "1",
                'description': "1\n2\n",
                'Memorized':"true"
            } ],
        'Terminator':
            [[PyTango.DevString,
            PyTango.SCALAR,
            PyTango.READ_WRITE],
            {
                'description': "CR\nLF\nCR/LF\nNONE",
                'Memorized':"true"
            } ],
        'FlowControl':
            [[PyTango.DevString,
            PyTango.SCALAR,
            PyTango.READ_WRITE],
            {
                'label': "FlowControl",
                'description': "none\nhardware\nsoftware",
                'Memorized':"true"
            } ],
        'Timeout':
            [[PyTango.DevShort,
            PyTango.SCALAR,
            PyTango.READ_WRITE],
            {
                'label': "Timeout",
                'min value': "0",
                'description': "timeout=None            #wait forever\ntimeout=0               #non-blocking mode (return immediately on read)\ntimeout=x               #set timeout to x miliseconds (float allowed)",
                'Memorized':"true"
            } ],
        'Parity':
            [[PyTango.DevString,
            PyTango.SCALAR,
            PyTango.READ_WRITE],
            {
                'description': "none\nodd\neven",
                'Memorized':"true"
            } ],
        'InputBuffer':
            [[PyTango.DevLong,
            PyTango.SCALAR,
            PyTango.READ]],
        }


def main():
    try:
        py = PyTango.Util(sys.argv)
        py.add_class(PySerialClass, PySerial, 'PySerial')
        #----- PROTECTED REGION ID(PySerial.add_classes) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	PySerial.add_classes

        U = PyTango.Util.instance()
        U.server_init()
        U.server_run()

    except PyTango.DevFailed as e:
        print ('-------> Received a DevFailed exception:', e)
    except Exception as e:
        print ('-------> An unforeseen exception occured....', e)

if __name__ == '__main__':
    main()