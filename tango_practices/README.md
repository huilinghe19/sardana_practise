When I use the function of taurusform, the functions about sardana and spock work well. But some device servers do not work well, such as tango test, and tango starter. 
I have spent lots of time to check the problem, why tango test and tango starter can not work. During this time, I have learned somthing about tango control,  how to operate the tango device servers or devices in jive, and also astor.  
Process:
in jive, add server and device. Now these can not work well. 
in spock, use the commands shown in the image "tango_test_problem.png" to determine the functions of tango test. 
In MATE console, use '/usr/lib/tango/TangoTest Test', then 'ready to accecpt request' occurs.  
In jive, server registeration. 

My mistake is that, I am used to start the service with the command 'sudo systemctl start TangoTest.service'. And this result is always 'active(exited)'. I am trying to fix this, which is a waste of time. In fact, we do not use this to start tango test. 
