# Sardana practice

Usage of BlenderbladesMotorCtrl:

Terminal 1: blenderplayer work/sardana-training/blender_slits/slits.blend

Terminal 2: Sardana Blender

Terminal 3: spock --profile=Blender
 


CopleyControl DS 
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


Terminal 1: Sardana python3TangoDS


Terminal 2: spock --profile=python3TangoDS


Note: when we run "sar_demo" in spock interface, there are already many sample devices. So I have deleted all related devices, the sar_demo works. That means, the same name for controllers and motors can not be used twice. 

# PyCharm starten
Using PyCharm we can change the program easily.

>>> /snap/pycharm-community/197/bin/pycharm.sh

# virtual environment aktivate/deactivate
>>> python3 -m venv tutorial-env

>>> source tutorial-env/bin/activate

>>> pip install requests
>>> pip install wheel

>>> pip list

>>> pip freeze > requirements.txt

>>> cat requirements.txt

>>> pip install -r requirements.txt

>>> deactivate


# Camera
http://192.168.1.90

