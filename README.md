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

Besides two functions: docker and pseudo counter and trigger/gate, I have reached to Macros2 and Marcos3. I have finished the content of 'MACROGUI - MACROEXECUTOR' and 'MACROGUI - SEQUENCER' in Macros2. Due to the problem of the macro random_image(The problem is shown in the image 'problem_with_macro(random_image).png'), I have looked for a solution. Maybe it is caused by the path of macro server, maybe it is caused by the matplotlib library. Now I am reading the content of this page (https://github.com/sardana-org/sardana-training/tree/master/xyzDummyStage). There is a module called 'matplotlibrandom.py' on this page.


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
   set path of Pool with 'Pool_demo1_1.put_property({"PoolPath":["/controllers"]})'
   set path of Macro Server with '_MACRO_SERVER.put_property({"MacroPath":["/macros", "/usr/local/lib/python2.7/dist-packages/sardana/macroserver/macros/examples"]})
   set path of recorder with _MACRO_SERVER.put_property({"RecorderPath":["/usr/local/lib/python2.7/dist-packages/sardana-2.3.3a0-py2.7.egg/sardana/macroserver/recorders/examples"]})
   Using Spock commands to execute operation:'wa', 'lsdef','addctrllib', 'defctrl''lsm', 'lsctrl', 'mv top 20', 'net.value', 'defmeas', 'ct 1'
   
 5. Execution with Taurus widgets is here: https://github.com/huilinghe19/sardana_practise/tree/master/macros_huiling/general_scan
   


-----------------------------------------------------------------------------------------------------------------------------------------
Some tips:

1. The start-up order cannot be changed. First, The blender server must be started. Then the sardana server is started, and finally the spock is available. Once the controller class is changed, the sardana server needs to be restarted. The command '%relctrlcls' can also be used in the spock to reloads the new controller class.
2. If something wrong about sardana server happens, use 'jive' command to open jive frame, delete the sardana server, restart or re-create Pool and MacroServer, in oder to make sardana server run correctly. When we open sardana server correctly, then we do not use the commands concerning about Pool and MacroServer any more. Before we start spock, opening Sardana server has the same function with opening both of the Pool and MacroServer. That means, we should open either sardana server or both of Pool and MacroServer.      
3. If something wrong about the spock happens, open the folder '/.ipython', some profile with wrong informations should be deleted. Delete the unnecessary profile or incorrect profile such as file 'profile_spockdoor' and create new profile in spock using command 'spock --profile=testdoor', then the problem should be solved. The name of 'testdoor' is just an example.

