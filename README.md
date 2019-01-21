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
   
  
Sardana Training
----------------------------------------------------
https://github.com/sardana-org/sardana-training

Tango Control
----------------------------------------------------
https://tango-controls.readthedocs.io/en/latest/tutorials-and-howtos/how-tos/how-to-pytango.html

PyTango 
------------------------------------------------------
https://pytango.readthedocs.io/en/stable/contents.html


copleyControl Tango device Server
-------------------------------------------------------

https://github.com/huilinghe19/sardana_practise/blob/master/jive/serialLine/src/CopleyControl.py


Usge in my computer (all working files are in "/work"): 

open pyserial: "python work/sardana_practise/jive/serialLine/src/PySerial.py test"

open copleyControll: "python work/sardana_practise/jive/serialLine/src/CopleyControl.py test"



Copley Controller in Sardana
---------------------------------------
https://github.com/huilinghe19/sardana_practise/blob/master/copley_controllers/copleyController.py

Usge: put this file "copleyController.py" in "/controller".


