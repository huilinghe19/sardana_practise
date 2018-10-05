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
7. spock commands:'wa''lsdef''addctrllib''lsm''lsctrl''mv top 20''net.value''ct'
