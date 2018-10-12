# sardana_practice

Summary: 
After knowing how to controll the blender blades motion and how to write some controllers , I have followed these steps according to the introduction(https://github.com/sardana-org/sardana-training/tree/master/users):

    Introduction (finished)
    Overview (finished)
    Sardana from scratch (finished)
    Pool (finished)
    Controllers (finished)
    Macros1 (finished)
    Macros2 (processing)
    Macros3 (processing)
    Taurusgui
    Tauruscore1
    Tauruscore2

Besides two functions: docker and pseudo counter and trigger/gate, I have reached to Macros2 and Marcos3. I have finished the content of 'MACROGUI - MACROEXECUTOR' and 'MACROGUI - SEQUENCER' in Macros2. 

----------------------------------------------------------------------------------------------------------------------------------------

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
   
   Set path of Macro Server with '_MACRO_SERVER.put_property({"MacroPath":["/macros", "/usr/local/lib/python2.7/dist-packages/sardana/macroserver/macros/examples"]})
   
   Set path of recorder with _MACRO_SERVER.put_property({"RecorderPath":["/usr/local/lib/python2.7/dist-packages/sardana-2.3.3a0-py2.7.egg/sardana/macroserver/recorders/examples"]})
   
   Using Spock commands to execute operation:'wa', 'lsdef','addctrllib', 'defctrl''lsm', 'lsctrl', 'mv top 20', 'net.value', 'defmeas', 'ct 1'
   
 5. Execution with Taurus widgets is here: https://github.com/huilinghe19/sardana_practise/tree/master/macros_huiling/general_scan
   


-----------------------------------------------------------------------------------------------------------------------------------------
Some tips:


1. After installation, following commands can be used in the terminal to check if the related software work well:

    python -c 'import PyTango; print PyTango.Release.version'

    python -c 'import taurus; print taurus.Release.version'

    python -c 'import lxml.etree; print lxml.etree.LXML_VERSION'
   
    
2. About MacroServer, Pool, Sardana, spock.
    
    MacroServer and Pool are two components of Sardana. In oder to open spock, we need to at first open either Sardana server or both of MacroServer and Pool. Due to the version of my installed PyTango is 9.2.0, so Sardana can be opened directly. If Sardana server is opened, then MacroServer and Pool do not need to be opened. If one has Tango <= 7.2.6 without all patches applied, Sardana server will not work, then he should use Pool and MacroServer.
    
     If something wrong about sardana server happens, use 'jive' command to open jive frame, delete the sardana server, restart or re-create Pool and MacroServer, in oder to make sure Pool and MacroServer has no problem at first. After checking Pool and MacroServer, then we testen sardana server. When we open sardana server correctly, then we do not use the commands concerning about Pool and MacroServer any more. Before we start spock, opening Sardana server has the same function with opening both of the Pool and MacroServer. 
     
    Sometimes we want to restart Sardana, but the sardana server is already running. Then we can use command 'ps uax' to see the process and use command 'kill ', then we can restart the Sardana server. 


3. The start-up order of the servers cannot be changed. First, The blender server or other device servers must be started. Then the sardana server can be started, and finally the spock is available. Once the controllers or macros are changed, the sardana server needs to be restarted. The command '%relctrlcls' can also be used in the spock to reloads the new controller class.


4. If something wrong about the spock happens, open the folder '/.ipython', some profile with wrong informations should be deleted. Delete all the unnecessary profile or incorrect profile such as file 'profile_default', 'profile_spockdoor', 'spock_tango' and so on. Then we open spock once more, then a new profile will be created. Of course, we can also create new profile in spock using command 'spock --profile=testdoor', the name of 'testdoor' is just an example.

