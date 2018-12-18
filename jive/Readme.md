Jive 

1. How to open jive.
Link: https://tango-controls.readthedocs.io/en/latest/tools-and-extensions/jive/
In console: jive

2. My work: blenderbladescontroll device server(finished). Socket DS(finished). PySerial DS(finished). ManageServer(finished). CopleyControl DS(processing)

PySerial and CopleyControl class:
I habe created a new CopleyControl class, which uses the methods of PySerial class to move the motor.
About the functions in PySerial, it should be changed a little to adjust your own DS, when you want to use the functions of the standard PySerial class. I have changed the write method in PySerial class, to make the motor move. "Move" command uses the raw command "t 1" or "2 t 1", to make the 2 motors move. "SendCommand" command send the command in jive to the motors.

In the SendCommand method in jive, we must write the "" symbol. Such as "t 1". Without the symbol the command will not work.


3. Tips: 

In the first process, I have used "ManageServer" to controll the device"s/hhl/1". I can write "move top 30" directly to the device "s/hhl/1", and the top blenderblades move to 30. 

In the second process, I add some commands in "ManageServer" device server, to communicate with the PySerial class. I wanted to send the raw command such as "t 1" to the device "/pyserial/hhl/1". It works at the first time without problems. But after I try to change something many times, some communication problems occur, such as SerialPort can be set as "simulation/hhl/1" automatically. But it is not the serial port. After that, I create a new class"CopleyControl", which is just copley control DS. In addition, I have also changed the ManageServer.

4. 
Some standard Tango device server class code can be found from:
http://svn.code.sf.net/p/tango-ds/code/DeviceClasses/Communication/

using "svn co <link>" on the console, then you can download all the source code.


5.How to use the Socket class c++ source code:

After I have downloaded the code:http://svn.code.sf.net/p/tango-ds/code/DeviceClasses/Communication/Socket/, I use make command in the console, it does not work. 

At first, open pogo, then open the source code "Socket.xmi" in pogo, then click generate, then you can see "Files to be generated". There are some options such as Makefile and Eclipse Project. You should also choose them. Then "ok".

After that, you can find "DeviceServers/Socket" in your home folder. Using "DeviceServers/Socket test", you can open the socket device server. hostname and port can be defined by us. The following steps are like the normal DS.
Actually, the TangoTest DS is also using this method. We use "/usr/lib/tango/TangoTest test" to open the TangoTest DS.

6. How to use the PySerial source code:
I have downloaded the code:http://svn.code.sf.net/p/tango-ds/code/DeviceClasses/Communication/PySerialLine/.

There is a "PySerial.py" file. but no xmi file. So I use "python PySerial.py test" to open the PySerial DS. It works. 

But if I want to change something in the PySerial.py file, I must be careful to use the original format which I think is from the old version of POGO.

I have used the Write and Read method of PySerial class, Read method works but Write method does not work. So i change something in the Write method. Now I can use the new Write method. 


