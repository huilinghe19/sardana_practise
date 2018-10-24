When I use the function of taurusform, the functions about sardana and spock work well. But some device servers do not work well, such as tango test, and tango starter. 
I have spent lots of time to check the problem, why tango test and tango starter can not work. During this time, I have learned somthing about tango control,  how to operate the tango device servers or devices in jive, and also astor.  Up to now, tango test and starter work. 

Process:

In jive, add server and device. At this point, these can not work well. 

In spock, use the commands shown in the image "tango_test_problem.png" to determine the functions of tango test. 

In MATE console, for starting tango test, we use '/usr/lib/tango/TangoTest Test', then 'ready to accecpt request' occurs in the console.

For starting Starter, we use " /usr/lib/tango/Starter debian sys/starter/dide17", then the following result occurs in the console. If the result is not good, you should try once more. 


"""Starter::Starter() init device sys/starter/dide17
UseEvents  = False
interStartupLevelWait  = 1
serverStartupTimeout   = 1
fireFromDbase  = 1
logFileHome    = /var/tmp
StartServersAtStartup = 1
AutoRestartDuration   = 0
---->  starter_log_file  = /var/tmp/ds.log/Starter.log
---->  starter_stat_file = /var/tmp/ds.log/Starter.stat
Starter::dev_start_all(): entering for level 1... !
Starter::dev_start_all(): entering for level 2... !
Starter::dev_start_all(): entering for level 3... !
Starter::dev_start_all(): entering for level 4... !
Starter::dev_start_all(): entering for level 5... !
Ready to accept request"""





At the same time , we should also configure the device and server in jive, namely, we should add server and device using 'Tools/Server Wizard', then we do server registeration. Some server name, instance name and device name are also used in the command in the console. 

My mistake was that, I was used to start the service with the command 'sudo systemctl start TangoTest.service'. And this result was always 'active(exited)'. I was always trying to fix this, which is a waste of time. In fact, we do not use systemctl to start tango test.

If I use the command "/usr/lib/tango/tango_admin --server-list", then the result is as follows.

" /usr/lib/tango/tango_admin --server-list
DataBaseds Sardana Starter TangoAccessControl TangoTest "

