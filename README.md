# NOTE
Taurus functions are not the same as before. Something is new. such as taurus trend function is diferent. Now it is taurus tpg trend. new command like taurus device sim and so on, we can check those new commands using taurus tool.  Once the taurus functions are used, it is better not to change the device or pool name. Otherweise the old history will remain all the time and may have bad effect such as demo4.

taurus tools: taurus form sim1/position, taurus device sim1, macroexecutor, sequencer can work, but not stable. "taurus qwt5 trend" can not work. The old version "taurus trend" does not exist any more. I habe checked the independencies and installed python3-guiqwt. 

>>> sudo apt install python3 guiqwt

>>> sudo apt install libqwt5-qt4 libqwt5-qt4-dev libqwt5-doc


In spock(python3TangoDS):

>>> wa

    tango://dide17.basisit.de:10000/motor/copleyctrl/1
    User 10000.000000000000000000000000000000000000000000000
    Dial 10000.000000000000000000000000000000000000000000000
                                                       
    tango://dide17.basisit.de:10000/motor/copleyctrl/2
    User 7001.000000000000000000000000000000000000000000000
    Dial 7001.000000000000000000000000000000000000000000000

The positions and the motor names are different as usual. We can rename them in spock with command %renameelem.

1. There are controllers and motors in Sardana, but you can not use them because of the permission problem.

""" 
An error occurred while running wa:
TypeError: must be real number, not NoneType
Hint: in Spock execute `www`to get more details
"""

This message shows that, the controller program can not be used. It happens usually after new start. The permissions of the file should be changed.

2. Do not put different similar controller programs in a Pool. 

Do not change the existing controller with a different controller class name. Once controller program is different, it takes time for sardana(in fact , tango) to adapt to it. That means, when the controller name is fixed, and the motor controller and motors are already in Sardana. Do not change the file name and controller name. You can change the content of the program.   


# Version update

debian9 to debian 10:
https://www.cyberciti.biz/faq/update-upgrade-debian-9-to-debian-10-buster/


java 11 to java 8:
https://linuxize.com/post/install-java-on-debian-10/

remove all taurus version at first. install taurus on debian 10 as follows:
https://taurus-scada.org/users/getting_started.html


install taurus in develop mode
git clone https://github.com/taurus-org/taurus.git

sudo pip3 install -e ./taurus  

install taurus_pyqtgraph in develop mode:
git clone https://github.com/taurus-org/taurus_pyqtgraph.git

sudo pip3 install -e ./taurus_pyqtgraph  

 
install itango3 with python3 :

uninstall all version. install from this way: sudo apt install python3-itango
pkg_resources.DistributionNotFound: The 'PyTango>=9.2.5' distribution was not found and is required by sardana
# Install sardana unter python3
Working directly from Git

If you intend to do changes to Sardana itself, or want to try the latest developments, it is convenient to work directly from the git source in “develop” (aka “editable”) mode, so that you do not need to re-install on each change.

You can clone sardana from the main git repository:

git clone https://github.com/sardana-org/sardana.git sardana

Then, to work in editable mode, just do:

sudo pip3 install -e ./sardana

The other way to install Sardana. see Sardana Doc.

On the diaz07 computer, due to the different ways to install pytango. We need to be careful about path issues. 

On the dide17 computer, before I am used to use huiling@dide17, but oil@dide17 works well. I test something under oil@dide17 in oder to replace all the old things. Both of these are adapt to my git hub repository.  Jupyter-notebook and Git push new things is the same. 


# Sardana practice

Usage of BlenderbladesMotorCtrl in Sardana:

Terminal 1: blenderplayer work/sardana-training/blender_slits/slits.blend

Terminal 2: Sardana Blender

Terminal 3: spock --profile=Blender
 


CopleyControl DS 
-------------------------------------------------------
"copleyControl.py" is here:

https://github.com/huilinghe19/sardana_practise/blob/master/jive/serialLine/src/CopleyControl.py

open pyserial: 

    #"python work/sardana_practise/jive/serialLine/src/PySerial.py test"(python2 version)
    python3 ~/work/copleyCtrlRepository/CopleyControlProgramsHHL/PySerial.py copleyCtrlSerialLine
open copleyControll: 

      "python work/sardana_practise/jive/serialLine/src/CopleyControl.py test"(python2 version)
      python3 ~/work/copleyCtrlRepository/CopleyControlProgramsHHL/CopleyControl.py beamline




Open HhlServer DS to controll blender blades through Socket. 
------------------------------
 open blenderblades:

    "blenderplayer work/sardana-training/blender_slits/slits.blend"

 open Socket DS:
 
    "DeviceServers/Socket test"
   
  open HhlServer DS:
   
    "python work/sardana_practise/tango_practices/programs/HhlServer.py test"
   
   
   sudo apt install libqwt5-qt4 libqwt5-qt4-dev libqwt5-doc
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

>>> deactivateModuleNotFoundError: No module named 'tango'

sudo apt install libqwt5-qt4 libqwt5-qt4-dev libqwt5-doc

# Camera
http://192.168.1.90

# Problem after replacing huiling@dide17 as oil@dide17 on 21.07.2020. 
Green oil is old huiling account. White oil is new oil account. 

After the Buster version update and switch user from huiling@dide17 to oil@dide17. Something is the same, something not. per ssh oil@dide17 or ssh huiling@dide17 is not the same. If I want something, I must use ssh huiling@dide17, although the displayed account is green oil. scp function through these accounts is not the same.

Actually I am always using the old huiling(green oil) account. Sardana works just in this account.


1, check Python version: Python 3 is installed.

2, check Tango things.

mariadb-server, mariadb-server-10.3, mariadb-server-core-10.3 are installed.
Tango-db, tango-starter, tango-test, libtango9,  libtango-dev, libtango-tools, python3-pytango, python3-itango are installed.

Problem: Tango Databank is there, jive works, but “import tango” "import PyTango" in python3 command line does not work. ModuleNotFoundError: No module named 'tango'.    pkg_resources.DistributionNotFound: The 'PyTango>=9.2.5' distribution was not found and is required by sardana.

# Permissions Problem 
Once the file comes from another computer with the scp method, then there will be a problem to change it or use it under oil@dide17. Because the permissions for the file need to be reconsidered. Sardana needs the original huiling permissions.

On the same computer dide17, if the user is not original huiling, then Sardana can not be used. The error message is:  

"pkg_resources.DistributionNotFound: The 'PyTango>=9.2.5' distribution was not found and is required by sardana"

The problem occurs with tango installation. Wenn I install tango at the first time, it is necessary to put "tango", "tango" as user and password for MySQL. Just user "huiling" has the right to import tango. "import tango" does not work when the user is different. Although jive can be opened, but the usage of tango can not be sure.

