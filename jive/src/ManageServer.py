#!/usr/bin/env python
# -*- coding:utf-8 -*-


# ############################################################################
#  license :
# ============================================================================
#
#  File :        ManageServer.py
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
#  $Author :      sdd$
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

__all__ = ["ManageServer", "ManageServerClass", "main"]

__docformat__ = 'restructuredtext'

import PyTango
import sys
# Add additional import
#----- PROTECTED REGION ID(ManageServer.additionnal_import) ENABLED START -----#

#----- PROTECTED REGION END -----#	//	ManageServer.additionnal_import

# Device States Description
# No states for this device


class ManageServer (PyTango.Device_4Impl):
    """"""
    
    # -------- Add you global variables here --------------------------
    #----- PROTECTED REGION ID(ManageServer.global_variables) ENABLED START -----#
    
    #----- PROTECTED REGION END -----#	//	ManageServer.global_variables

    def __init__(self, cl, name):
        PyTango.Device_4Impl.__init__(self,cl,name)
        self.debug_stream("In __init__()")
        ManageServer.init_device(self)
        #----- PROTECTED REGION ID(ManageServer.__init__) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	ManageServer.__init__
        
    def delete_device(self):
        self.debug_stream("In delete_device()")
        #----- PROTECTED REGION ID(ManageServer.delete_device) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	ManageServer.delete_device

    def init_device(self):
        self.debug_stream("In init_device()")
        self.get_device_properties(self.get_device_class())
        #----- PROTECTED REGION ID(ManageServer.init_device) ENABLED START -----#
        self.dev = PyTango.DeviceProxy("s/hhl/1")
        #self.dev = PyTango.DeviceProxy("serial/hhl/1")
        #----- PROTECTED REGION END -----#	//	ManageServer.init_device

    def always_executed_hook(self):
        self.debug_stream("In always_excuted_hook()")
        #----- PROTECTED REGION ID(ManageServer.always_executed_hook) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	ManageServer.always_executed_hook

    # -------------------------------------------------------------------------
    #    ManageServer read/write attribute methods
    # -------------------------------------------------------------------------
    
    
    
            
    def read_attr_hardware(self, data):
        self.debug_stream("In read_attr_hardware()")
        #----- PROTECTED REGION ID(ManageServer.read_attr_hardware) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	ManageServer.read_attr_hardware


    # -------------------------------------------------------------------------
    #    ManageServer command methods
    # -------------------------------------------------------------------------
    
    def dev_state(self):
        """ This command gets the device state (stored in its device_state data member) and returns it to the caller.
        :return: Device state
        :rtype: PyTango.CmdArgType.DevState
        """
        self.debug_stream("In dev_state()")
        argout = PyTango.DevState.UNKNOWN
        #----- PROTECTED REGION ID(ManageServer.State) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	ManageServer.State
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
        #----- PROTECTED REGION ID(ManageServer.Status) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	ManageServer.Status
        self.set_status(self.argout)
        self.__status = PyTango.Device_4Impl.dev_status(self)
        return self.__status
        
    def Write(self, argin):
        """ 
        :param argin: 
        :type argin: PyTango.DevString
        """
        self.debug_stream("In Write()")
        #----- PROTECTED REGION ID(ManageServer.Write) ENABLED START -----#        
        dev = self.dev     
        dev.Write(argin)
        #----- PROTECTED REGION END -----#	//	ManageServer.Write
        
    def ConnectInstrument(self):
        """ 
        """
        self.debug_stream("In ConnectInstrument()")
        #----- PROTECTED REGION ID(ManageServer.ConnectInstrument) ENABLED START -----#
        dev = self.dev
        dev.Init()
        #dev.Open()
        #----- PROTECTED REGION END -----#	//	ManageServer.ConnectInstrument
        

    #----- PROTECTED REGION ID(ManageServer.programmer_methods) ENABLED START -----#
    
    #----- PROTECTED REGION END -----#	//	ManageServer.programmer_methods

class ManageServerClass(PyTango.DeviceClass):
    # -------- Add you global class variables here --------------------------
    #----- PROTECTED REGION ID(ManageServer.global_class_variables) ENABLED START -----#
    
    #----- PROTECTED REGION END -----#	//	ManageServer.global_class_variables


    #    Class Properties
    class_property_list = {
        }


    #    Device Properties
    device_property_list = {
        }


    #    Command definitions
    cmd_list = {
        'Write':
            [[PyTango.DevString, "none"],
            [PyTango.DevVoid, "none"]],
        'ConnectInstrument':
            [[PyTango.DevVoid, "none"],
            [PyTango.DevVoid, "none"]],
        }


    #    Attribute definitions
    attr_list = {
        }


def main():
    try:
        py = PyTango.Util(sys.argv)
        py.add_class(ManageServerClass, ManageServer, 'ManageServer')
        #----- PROTECTED REGION ID(ManageServer.add_classes) ENABLED START -----#
        
        #----- PROTECTED REGION END -----#	//	ManageServer.add_classes

        U = PyTango.Util.instance()
        U.server_init()
        U.server_run()

    except PyTango.DevFailed as e:
        print ('-------> Received a DevFailed exception:', e)
    except Exception as e:
        print ('-------> An unforeseen exception occured....', e)

if __name__ == '__main__':
    main()
