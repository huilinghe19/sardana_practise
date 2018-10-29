# sardana_practice

Summary: 
After knowing how to controll the blender blades motion and how to write some controllers , I have followed these steps according to the introduction(https://github.com/sardana-org/sardana-training):

Here are the steps to use spock at the beginning:

1. In MATE Terminal: 
  
    Create /controllers directory with: 'mkdir /controllers'. All new controller files are placed in '/controllers'.
  
    Create /macros directory with: 'mkdir /macros'. All new macro files are placed in '/macros'.
  
2. In MATE Terminal:
  
    Start Sardana Server with: 'Sardana demo1 --log-level=debug' 
  
3. In another MATE Terminal: 
  
    Start spock with: 'spock' or 'spock --profile=testprofile'
 
  
4. In the spock console:
   
   Set path of Pool with 'Pool_demo1_1.put_property({"PoolPath":["/controllers"]})'
   
   Set path of Macro Server with '_MACRO_SERVER.put_property({"MacroPath":["/macros", "/usr/lib/python2.7/dist-packages/sardana/macroserver/macros/examples"]})
   
   Set path of recorder with _MACRO_SERVER.put_property({"RecorderPath":["/usr/lib/python2.7/dist-packages/sardana/macroserver/recorders/examples"]})
   
   Using Spock commands to execute operation:'wa', 'lsdef','addctrllib', 'defctrl''lsm', 'lsctrl', 'mv top 20', 'net.value', 'defmeas', 'ct 1'
   
 5. Execution with Taurus widgets is here: https://github.com/huilinghe19/sardana_practise/tree/master/macros_huiling/general_scan
   


-----------------------------------------------------------------------------------------------------------------------------------------
Some tips:


1. After installation, following commands can be used in the terminal to check if the related software works well:

    python -c 'import PyTango; print PyTango.Release.version'

    python -c 'import taurus; print taurus.Release.version'

    python -c 'import lxml.etree; print lxml.etree.LXML_VERSION'
   
    
2. About MacroServer, Pool, Sardana, spock.
    
    MacroServer and Pool are two components of Sardana. In oder to open spock, we need to at first open either Sardana server or both of MacroServer and Pool. Due to the version of my installed PyTango is 9.2.0, so Sardana can be opened directly. If Sardana server is opened, then MacroServer and Pool do not need to be opened. If one has Tango <= 7.2.6 without all patches applied, Sardana server will not work, then he should use Pool and MacroServer.
    
     If something wrong about sardana server happens, use 'jive' command to open jive frame, delete the sardana server, restart or re-create Pool and MacroServer, in oder to make sure Pool and MacroServer has no problem. After checking Pool and MacroServer, then we testen sardana server. Once we have opened sardana server, then we do not use the commands concerning about Pool and MacroServer any more. That means, opening Sardana server has the same function with opening both of the Pool and MacroServer. 
     
    Sometimes we want to restart Sardana, but the sardana server is already running. Then we can use command 'ps uax' to see the process and use command 'kill <process ID>', after that we can restart the Sardana server. 

    During my use of sardana, I found that sometimes when I first booted up after a day or the weekend , the connection to the tango database could not be connected, then sardana or jive can not be opened, but as soon as I restarted again, the problem was solved. 
    
    About Door, it is the entry point to the MacroServer, With different doors we can use different macros. 
    
3. The start-up order of the servers cannot be changed. First, The blender server or other device servers must be started. Then the sardana server can be started, and finally the spock is available. If a new device server has just been started, or the controllers or macros are changed, the sardana server needs to be restarted. In the spock console these changes will be automatically displayed after a few seconds, we do not need to restart spock. The commands 'lsctrl','lsmac' can also be used in the spock to check the controllers and macros.


4. If something wrong about the spock happens, open the folder '/.ipython', some profile with wrong informations should be deleted. Delete all the unnecessary profile or incorrect profile such as file 'profile_default', 'profile_spockdoor', 'spock_tango' and so on. Then we open spock once more, a new profile will be created. Besides, we can also create a new profile in spock using command 'spock --profile=testdoor', the name of 'testdoor' is just an example.

