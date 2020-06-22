# Sardana practice

Result
---------------------------------------------------------------------------------------------------------------------------------------

   know how sardana works;
   know how to write the programs of controllers, how to set it in sardana and use it to controll motors;
   know the usage of the macros and the GUI like taurus settings.
   know how to create tango server class and use jive to controll the devices 
   know how to use the extra pyserial and socket c++ tango server class and connect it with my own tango server classes in jive. 
  
   As for direct tango control with the instruments, I have implemented tango server classes to controll the blender blades and the real motors. 
   
   As for sardana control with the instruments, I have implemented copley controller into sardana and it can controll the real motors.


Open copleyControl DS 
-------------------------------------------------------
"copleyControl.py" is here:

https://github.com/huilinghe19/sardana_practise/blob/master/jive/serialLine/src/CopleyControl.py

open pyserial: 

     "python work/sardana_practise/jive/serialLine/src/PySerial.py test"

open copleyControll: 

      "python work/sardana_practise/jive/serialLine/src/CopleyControl.py test"




Open HhlServer DS to controll blender blades through Socket. 
------------------------------
 open blenderblades:

    "blenderplayer work/sardana-training/blender_slits/slits.blend"

 open Socket DS:
 
    "DeviceServers/Socket test"
   
  open HhlServer DS:
   
    "python work/sardana_practise/tango_practices/programs/HhlServer.py test"
   
   
   
Copley Controller in Sardana
---------------------------------------
https://github.com/huilinghe19/sardana_practise/blob/master/copley_controllers/copleyController.py

Usge: put this file "copleyController.py" in "/controller".


# Change Python2 files into python3 files:
Tango DS staten:
python3 ~/work/copleyCtrlRepository/CopleyControlProgramsHHL/PySerial.py copleyCtrlSerialLine
python3 ~/work/copleyCtrlRepository/CopleyControlProgramsHHL/CopleyControl.py beamline

Sardana Starten:
Terminal 1: Sardana test

Terminal 2: spock --profile=python3test





