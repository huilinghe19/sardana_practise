


-----------------------------------------------------------------------------------------------------------------------------------------
My work : Sardana practice
-----------------------------------------------------------------------------------------------------------------------------------------

   know how sardana works;
   know how to write the programs of controllers, how to set it in sardana and use it to controll motors;
   know the usage of the macros and the GUI like taurus settings.
   know how to create tango server class and use jive to controll the devices 
   know how to use the extra pyserial and socket c++ tango server class and connect it with my own tango server classes in jive. 
  
   I have implemented new tango server classes in jive to controll the blender blades and the real motors. 
   
   I have implemented new copley controller into sardana and it can controll the real motors.
   
  
  ----------------------------------------------------------------------------------------------------------------------------------------- 
 Install Sardana
-----------------------------------------------------------------------------------------------------------------------------------------
There are different methods to install sardana. My method is
In console: "sudo apt install python-sardana"

I wanted to use pip to install it, because this is simple to install things with pip. but I have used "apt install" to install some other things, when I use pip to install something, there is a conflict. So I have removed pip and anaconda(for the same reason) things, keep using apt install to install sardana. 

The sardana version is 2.2.2, and some error occurs when we open sardana:


          """
MainThread     WARNING  2019-01-11 11:01:28,744 TaurusRootLogger: /usr/lib/python2.7/dist-packages/sardana/macroserver/msmacromanager.py:45: DeprecationWarning: taurus.external.ordereddict is deprecated since 4.0. Use ordereddict instead
  from taurus.external.ordereddict import OrderedDict

/usr/lib/python2.7/dist-packages/sardana/pool/poolcontrollers/HklPseudoMotorController.py:52: PyGIWarning: Hkl was imported without specifying a version first. Use gi.require_version('Hkl', '5.0') before import to ensure that the right version gets loaded.
  from gi.repository import Hkl
MainThread     WARNING  2019-01-11 11:01:29,171 debian.local:10000.Pool_demo1_1: Received elements error event Pool was shutdown or is inacessible
TaurusTP.W001  WARNING  2019-01-11 11:01:29,172 TaurusRootLogger: /usr/lib/python2.7/dist-packages/sardana/taurus/core/tango/sardana/pool.py:1688: DeprecationWarning: _get_value is deprecated since 4.0. Use .rvalue instead
  elems = CodecFactory().decode(evt_value.value, ensure_ascii=True)
           """

This does not cause problems during this time, and I have not changed anything. Except once, during the taurus practices, I have changed something to adapt the taurus. Now the sardana is complete new without any change. 


Steps to use sardana and spock at the beginning
-----------------------------------------------------------------------------------------------------------------------------------------

1. In MATE Terminal:
  
    After installing Sardana and sardana training (https://sardana-controls.org/users/getting_started/installing.html) using git method. We can start Sardana Server with 'Sardana demo1' or 'Sardana demo1 --log-level=debug'.
    If sardana can not be opened after the computer is just started, then do not check other things, restart the computer again, then the problem should be solved. Sometimes tango database can not run properly at once. 
  
2. Open spock console: 
  
    Start spock with: 'spock' or 'spock --profile=testprofile' in another terminal.
    
3. In another MATE Terminal: 
  
    Create /controllers directory with: 'mkdir /controllers'. All new controller files are placed in '/controllers'.
  
    Create /macros directory with: 'mkdir /macros'. All new macro files are placed in '/macros'. 
  
4. Settings in spock console with debian 9 system:
   
   Set path of Pool with 'Pool_demo1_1.put_property({"PoolPath":["/controllers"]})'
   
   Set path of Macro Server with '_MACRO_SERVER.put_property({"MacroPath":["/macros", "/usr/lib/python2.7/dist-packages/sardana/macroserver/macros/examples"]})
   
   Set path of recorder with _MACRO_SERVER.put_property({"RecorderPath":["/usr/lib/python2.7/dist-packages/sardana/macroserver/recorders/examples"]})
   
   Using Spock commands to execute operation: 'wa', 'lsdef','addctrllib', 'defctrl''lsm', 'lsctrllib', 'mv top 20', 'net.value', 'defmeas', 'ct 1',
   
 5. Execution with Taurus widgets is here: https://github.com/huilinghe19/sardana_practise/tree/master/macros_huiling/general_scan
   


-----------------------------------------------------------------------------------------------------------------------------------------
Some tips
-----------------------------------------------------------------------------------------------------------------------------------------


1. After installation, following commands can be used in the terminal to check if the related software works well:

    python -c 'import PyTango; print PyTango.Release.version'

    python -c 'import taurus; print taurus.Release.version'

    python -c 'import lxml.etree; print lxml.etree.LXML_VERSION'
   
    
2. About MacroServer, Pool, Sardana, spock.
    
    MacroServer and Pool are two components of Sardana. In oder to open spock, we need to at first open either Sardana server or both of MacroServer and Pool. Due to the version of my installed PyTango is 9.2.0, so Sardana can be opened directly. If Sardana server is opened, then MacroServer and Pool do not need to be opened. If one has Tango <= 7.2.6 without all patches applied, Sardana server will not work, then he should use Pool and MacroServer.
    
     If something wrong about sardana server happens, use 'jive' command to open jive frame, delete the sardana server, restart or re-create Pool and MacroServer, in oder to make sure Pool and MacroServer has no problem. After checking Pool and MacroServer, then we testen sardana server. Once we have opened sardana server, then we do not use the commands concerning about Pool and MacroServer any more. That means, opening Sardana server has the same function with opening both of the Pool and MacroServer. 
     
    Sometimes we want to restart Sardana, but the sardana server is already running. Then we can use command 'ps uax' to see the process and use command 'kill <process ID>', after that we can restart the Sardana server. 

    During my use of sardana, I found that sometimes when I first booted up after a day or the weekend , the connection to the tango database could not be connected, then sardana or jive can not be opened, but as soon as I restarted again, the problem was solved. 
    
    About Door, it is the entry point to the MacroServer, with different doors we can use different macros. you can see which door you have used in spock.
    
    When you open spock, see each line in the spock move down, some error appears always, which means, there is a problem inside sardana, either macroserver or pool or Door. 
    Check Pool: examine the connected door name in front of the spock console line, "Door/demo1/1" or maybe "Door/demo1/2", open jive, check the Door name and the Pool inside sardana, if the used door is the right.
    Check MacroServer: examine the connected macroserver, "MacroServer/demo1/1" or "MacroServer/demo1/2". In your spock console, it shows you which macroserver you have choosed when something is wrong. When everything about macroserver is right, it shows nothing about macroserver. 
    
    There is a point need to be known, when you use "Pool demo1" and "MacroServer demo1" to check these device server, you may create some doors or macroservers, these doors or macroservers are seperate ones, which are not the same with the things you use in sardana. Then you should be more careful with the door name and macro server name you have choosed in sardana. Because when "Door/demo1/1" is already created through Pool, then you use "Sardana demo1", "Door/demo1/2" will be created automatically, when you open the spock, the spock is connected with a specific door, if this door is "Door/demo1/1" , then there is a problem. Because in sardana, the door is "Door/demo1/1". Now you can delete the device servers macroserver and pool, and change all the door devices as "Door/demo1/1" and macrosercer device as "MacroServer/demo1/1".
    
    Actually, in jive we can see, sardana is just the combination of some device servers such as Pool, Door, MacroServer. When you open sardana at the first time, you can only see Pool, Door, MacroServer. When you add something like controller and Motors in the future, then you can see more things in sardana.
    
    
3. The start-up order of the servers cannot be changed. First, The blender server or other device servers must be started. Then the sardana server can be started, and finally the spock is available. If a new device server has just been started, or the controllers or macros are changed, the sardana server needs to be restarted. In the spock console these changes will be automatically displayed after a few seconds, we do not need to restart spock. The commands 'lsctrl','lsmac' can also be used in the spock to check the controllers and macros.


4. If something wrong about the spock happens, open the folder '/.ipython', some profile with wrong informations should be deleted. Delete all the unnecessary profile or incorrect profile such as file 'profile_default', 'profile_spockdoor', 'spock_tango' and so on. Then we open spock once more, a new profile will be created. Besides, we can also create a new profile in spock using command 'spock --profile=testdoor', the name of 'testdoor' is just an example.



Usage of copleyController in sardana:
-------------------------------------------------------------------
1. Open sardana(command "Sardana demo1"), open spock(command "spock"), put the file "copleyController.py" in the folder "/controllers".
2. In spock, use the command "lsctrllib" to check if the copleyController works. 
3. When the copleyController exists, then we can use the command "defctrl CopleyController copleyctrl" to define copleyctrl.
Then the commands "defelem stepnet01 copleyctrl 1", "defelem stepnet02 copleyctrl 2" are to define the motors. Command "wa" can be used to show all motors. The command "stepnet01.state()" can be used to check the state. "mv stepnet01 10000" or "move stepnet01 10000" can be used to move the motors. 
 
