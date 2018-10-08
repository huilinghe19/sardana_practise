# sardana_practise
1. In MATE Terminal:
  Start Sardana Server with: 'Sardana demo1 --log-level=debug'
2. In another MATE Terminal: 
  Start spock with: 'spock'
3. In MATE Terminal: 
  Create /controllers directory with: 'mkdir /controllers'
4. All controller files are placed in '/controllers'
5. In the spock:
   set path with 'Pool_demo1_1.put_property({"PoolPath":["/controllers"]})'
6. Restart the Sardana server
7. Usage of the Spock commands:'wa', 'lsdef','addctrllib', 'defctrl''lsm', 'lsctrl', 'mv top 20', 'net.value', 'defmeas', 'ct 1'
8. The start-up order cannot be changed. First, The blender server must be started. Then the sardana server is started, and finally the spock is available. Once the controller class is changed, the sardana server needs to be restarted. The command '%relctrlcls' can also be used in the spock to reloads the new controller class.
9. If something wrong about sardana server happens, use 'jive' command to open jive frame, delete the sardana server, restart or re-create Pool and MacroServer, in oder to make sardana server run correctly. When we open sardana server correctly, then we do not use the commands concerning about Pool and MacroServer any more. Before we start spock, opening Sardana server has the same function with opening both of the Pool and MacroServer. That means, we should open either sardana server or both of Pool and MacroServer.      
10. If something wrong about the spock happens, open the folder '/.ipython', some profile with wrong informations should be deleted. Delete the unnecessary profile or incorrect profile such as file 'profile_spockdoor' and create new profile in spock using command 'spock --profile=testdoor', then the problem should be solved. The name of 'testdoor' is just an example.

