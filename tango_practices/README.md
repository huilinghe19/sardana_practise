When I use the function of taurusform, the functions about sardana and spock work well. But some device servers do not work well, such as tango test, and tango starter. 
I have spent lots of time to check the problem, why tango test and tango starter can not work. During this time, I have learned somthing about tango control,  how to operate the tango device servers or devices in jive, and also astor.  Up to now, tango test works but Starter and tango admin do not work. 

Process to make the tango test work:

In jive, add server and device. Now these can not work well. 

In spock, use the commands shown in the image "tango_test_problem.png" to determine the functions of tango test. 

In MATE console, use '/usr/lib/tango/TangoTest Test', then 'ready to accecpt request' occurs.  

In jive, server registeration. 

My mistake was that, I was used to start the service with the command 'sudo systemctl start TangoTest.service'. And this result was always 'active(exited)'. I was always trying to fix this, which is a waste of time. In fact, we do not use systemctl to start tango test.


