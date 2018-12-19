#!/usr/bin/env python
# -*- coding:utf-8 -*-


# ############################################################################
#  license :
# ============================================================================
#
#  File :        CopleyControl.py
#
#  Project :     
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

__all__ = ["CopleyControl", "CopleyControlClass", "main"]

__docformat__ = 'restructuredtext'

import PyTango
import sys
# Add additional import
#----- PROTECTED REGION ID(CopleyControl.additionnal_import) ENABLED START -----#

#----- PROTECTED REGION END -----#	//	CopleyControl.additionnal_import

# Device States Description
# No states for this device


class CopleyControl (PyTango.Device_4Impl):
    """"""
    
    # -------- Add you global variables here --------------------------
    #----- PROTECTED REGION ID(CopleyControl.global_variables) ENABLED START -----#
    
    #----- PROTECTED REGION END -----#	//	CopleyControl.global_variables

    def __init__(self, cl, name):
        PyTango.Device_4Impl.__init__(self,cl,name)
        self.debug_stream("In __init__()")
        CopleyControl.init_device(self)
        #----- PROTECTED REGION ID(CopleyControl.__init__) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	CopleyControl.__init__
        
    def delete_device(self):
        self.debug_stream("In delete_device()")
        #----- PROTECTED REGION ID(CopleyControl.delete_device) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	CopleyControl.delete_device

    def init_device(self):
        self.debug_stream("In init_device()")
        self.get_device_properties(self.get_device_class())
        #----- PROTECTED REGION ID(CopleyControl.init_device) ENABLED START -----#
        self.dev= PyTango.DeviceProxy("pyserial/hhl/1")
        #----- PROTECTED REGION END -----#	//	CopleyControl.init_device

    def always_executed_hook(self):
        self.debug_stream("In always_excuted_hook()")
        #----- PROTECTED REGION ID(CopleyControl.always_executed_hook) ENABLED START -----#
        print "In ", self.get_name(), "::always_excuted_hook()"
        #----- PROTECTED REGION END -----#	//	CopleyControl.always_executed_hook

    # -------------------------------------------------------------------------
    #    CopleyControl read/write attribute methods
    # -------------------------------------------------------------------------
    
    
    
            
    def read_attr_hardware(self, data):
        self.debug_stream("In read_attr_hardware()")
        #----- PROTECTED REGION ID(CopleyControl.read_attr_hardware) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	CopleyControl.read_attr_hardware


    # -------------------------------------------------------------------------
    #    CopleyControl command methods
    # -------------------------------------------------------------------------
    
    def dev_state(self):
        """ This command gets the device state (stored in its device_state data member) and returns it to the caller.
        :return: Device state
        :rtype: PyTango.CmdArgType.DevState
        """
        self.debug_stream("In dev_state()")
        argout = PyTango.DevState.UNKNOWN
        #----- PROTECTED REGION ID(CopleyControl.State) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	CopleyControl.State
        if argout != PyTango.DevState.ALARM:
            PyTango.Device_4Impl.dev_state(self)
        return self.get_state()
        
    def dev_status(self):
        """ This command gets the device status (stored in its device_status data member) and returns it to the caller.
        :return: Device status
        :rtype: PyTango.ConstDevString
        """
        self.debug_stream("In dev_status()")
        argout = ""
        #----- PROTECTED REGION ID(CopleyControl.Status) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	CopleyControl.Status
        self.set_status(self.argout)
        self.__status = PyTango.Device_4Impl.dev_status(self)
        return self.__status
        
    def MoveMotor0(self):
        """ 
        """
        self.debug_stream("In MoveMotor0()")
        #----- PROTECTED REGION ID(CopleyControl.MoveMotor0) ENABLED START -----#
        print "In ", self.get_name(), "::Move()"
        dev = self.dev
        dev.Write('t 1')
        #----- PROTECTED REGION END -----#	//	CopleyControl.MoveMotor0
        
    def SendCommand(self, argin):
        """ 
        :param argin: 
        :type argin: PyTango.DevString
        :rtype: PyTango.DevString
        """
        self.debug_stream("In SendCommand()")
        argout = ""
        #----- PROTECTED REGION ID(CopleyControl.SendCommand) ENABLED START -----#
        print "In ", self.get_name(), "::SendComand()"
        dev = self.dev
        argout = str(dev.Write(argin))
        #argout = dev.Write(argin)
        print argout
        #----- PROTECTED REGION END -----#	//	CopleyControl.SendCommand
        return argout
        
    def ReadLine(self):
        """ 
        :rtype: PyTango.DevVarCharArray
        """
        self.debug_stream("In ReadLine()")
        argout = [0]
        #----- PROTECTED REGION ID(CopleyControl.ReadLine) ENABLED START -----#
        print "In ", self.get_name(), "::ReadLine()"
        dev = self.dev
        argout = dev.ReadLine()
        print argout
        #----- PROTECTED REGION END -----#	//	CopleyControl.ReadLine
        return argout
        
    def Read(self):
        """ 
        :rtype: PyTango.DevString
        """
        self.debug_stream("In Read()")
        argout = ""
        #----- PROTECTED REGION ID(CopleyControl.Read) ENABLED START -----#
        print "In ", self.get_name(), "::Read()"
        dev = self.dev
        argout = dev.Read(16) 
        print argout
        #----- PROTECTED REGION END -----#	//	CopleyControl.Read
        return argout
        
    def MoveMotor2(self):
        """ 
        """
        self.debug_stream("In MoveMotor2()")
        #----- PROTECTED REGION ID(CopleyControl.MoveMotor2) ENABLED START -----#
        print "In ", self.get_name(), "::Move()"
        dev = self.dev
        dev.Write('2 t 1')
        #----- PROTECTED REGION END -----#	//	CopleyControl.MoveMotor2
        
    def InitMotor0(self):
        """ 
        """
        self.debug_stream("In InitMotor0()")
        #----- PROTECTED REGION ID(CopleyControl.InitMotor0) ENABLED START -----#
        print "In ", self.get_name(), "::SetProgrammedPositionMode()"
        dev = self.dev
        dev.Write('s r0x24 31\n s r0xC8 257')
    
        
        #----- PROTECTED REGION END -----#	//	CopleyControl.InitMotor0
        
    def InitMotor2(self):
        """ 
        """
        self.debug_stream("In InitMotor2()")
        #----- PROTECTED REGION ID(CopleyControl.InitMotor2) ENABLED START -----#
        print "In ", self.get_name(), "::SetTrajectoryProfileMode()"
        dev = self.dev
        dev.Write('2 s r0x24 31\n 2 s r0xC8 257')
        #----- PROTECTED REGION END -----#	//	CopleyControl.InitMotor2
        
    def Write(self, argin):
        """ 
        :param argin: 
        :type argin: PyTango.DevString
        """
        self.debug_stream("In Write()")
        #----- PROTECTED REGION ID(CopleyControl.Write) ENABLED START -----#
        print "In ", self.get_name(), "::Write()"
        dev = self.dev
        dev.Write(argin)
        #----- PROTECTED REGION END -----#	//	CopleyControl.Write
        

    #----- PROTECTED REGION ID(CopleyControl.programmer_methods) ENABLED START -----#
    
    #----- PROTECTED REGION END -----#	//	CopleyControl.programmer_methods

class CopleyControlClass(PyTango.DeviceClass):
    # -------- Add you global class variables here --------------------------
    #----- PROTECTED REGION ID(CopleyControl.global_class_variables) ENABLED START -----#
    
    #----- PROTECTED REGION END -----#	//	CopleyControl.global_class_variables


    #    Class Properties
    class_property_list = {
        }


    #    Device Properties
    device_property_list = {
        }


    #    Command definitions
    cmd_list = {
        'MoveMotor0':
            [[PyTango.DevVoid, "none"],
            [PyTango.DevVoid, "none"]],
        'SendCommand':
            [[PyTango.DevString, "none"],
            [PyTango.DevString, "none"]],
        'ReadLine':
            [[PyTango.DevVoid, "none"],
            [PyTango.DevVarCharArray, "none"]],
        'Read':
            [[PyTango.DevVoid, "none"],
            [PyTango.DevString, "none"]],
        'MoveMotor2':
            [[PyTango.DevVoid, "none"],
            [PyTango.DevVoid, "none"]],
        'InitMotor0':
            [[PyTango.DevVoid, "none"],
            [PyTango.DevVoid, "none"]],
        'InitMotor2':
            [[PyTango.DevVoid, "none"],
            [PyTango.DevVoid, "none"]],
        'Write':
            [[PyTango.DevString, "none"],
            [PyTango.DevVoid, "none"]],
        }


    #    Attribute definitions
    attr_list = {
        }


def main():
    try:
        py = PyTango.Util(sys.argv)
        py.add_class(CopleyControlClass, CopleyControl, 'CopleyControl')
        #----- PROTECTED REGION ID(CopleyControl.add_classes) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	CopleyControl.add_classes

        U = PyTango.Util.instance()
        U.server_init()
        U.server_run()

    except PyTango.DevFailed as e:
        print ('-------> Received a DevFailed exception:', e)
    except Exception as e:
        print ('-------> An unforeseen exception occured....', e)

if __name__ == '__main__':
    main()
