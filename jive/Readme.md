# Jive 

1. Basis of jive.

Link: https://tango-controls.readthedocs.io/en/latest/tools-and-extensions/jive/

Open jive in console: jive


2. My work: blenderbladescontroll device server. Socket DS. PySerial DS. ManageServer. CopleyControl DS

PySerial and CopleyControl class:
I habe created a new CopleyControl class, which uses the methods of PySerial class to move the motor.
About the functions in PySerial, it should be changed a little to adjust your own DS, when you want to use the functions of the standard PySerial class. I have changed the write method in PySerial class, to make the motor move. "Move" command uses the raw command "t 1" or "2 t 1", to make the 2 motors move. "SendCommand" command send the command in jive to the motors.

In the SendCommand method in jive, we must write the "" symbol. Such as "t 1". Without the symbol the command will not work.


3. Interaction:

In the first process, I have used "ManageServer" to controll the device"s/hhl/1". I can write "move top 30" directly to the device "s/hhl/1", and the top blenderblades move to 30. 

In the second process, I add some commands in "ManageServer" device server, to communicate with the PySerial class. I wanted to send the raw command such as "t 1" to the device "/pyserial/hhl/1". It works at the first time without problems. But after I try to change something many times, some communication problems occur, such as SerialPort can be set as "simulation/hhl/1" automatically. But it is not the serial port. After that, I create a new class"CopleyControl", which is just copley control DS. In addition, I have also changed the function of ManageServer.

During my work with the motors, sometimes I send "t 1" to the motor, it does not turn at once, then I send "t 1" once again, the motor turns. This is not because of the program. Even if I am writing instructions directly at the console, this will also happen occasionally. Maybe the motor itself has a hysteresis effect under some conditions.

There is also a problem about the server start and close. When you do not close the server correctly, you close the terminal, and start the server afterwards, the server will also work. But this situation is bad. The server is started many times. You can check it with "ps uax". This will cause the runtimeout problem.


4. Source Code

Some common Tango device server class code can be found from:
http://svn.code.sf.net/p/tango-ds/code/DeviceClasses/Communication/

using "svn co <<link>>" on the console, then you can download all the source code. Some codes are old and not be available, you should change something in it. See the doc: https://pytango.readthedocs.io/en/stable/server_api/index.html


5.How to use the Socket class c++ source code to create Socket Server class:

After I have downloaded the code:http://svn.code.sf.net/p/tango-ds/code/DeviceClasses/Communication/Socket/, I use make command in the console, it does not work. 

At first, open pogo, then open the source code "Socket.xmi" in pogo, then click generate, then you can see "Files to be generated". There are some options such as Makefile and Eclipse Project. You should also choose them. Then "ok".

After that, you can find "DeviceServers/Socket" in your home folder. Using "DeviceServers/Socket test", you can open the socket device server. hostname and port can be defined by us. The following steps are like the normal DS.
Actually, the TangoTest DS is also using this method. We use "/usr/lib/tango/TangoTest test" to open the TangoTest DS.

6. Usage of Socket Server class in jive:
 
We can use the existed commands to check if the socket class runs well, such write the "move top 30" to make the blender blades move to 30.  
When a new device is created by the first time, make sure that the hostname and port are given properly, otherweise the socket device server will stop. The initial value of the hostname and port are not correct.

A point which should be noticed is that, with c++ tango DS class can we get many class properties automatisch 
when we start it at the first time, but with python DS class we need to change them as soon as we start the server at the first time. 

7. How to use the PySerial source code to create PySerial:

I have downloaded the code:http://svn.code.sf.net/p/tango-ds/code/DeviceClasses/Communication/PySerialLine/.

A "PySerial.py" file can be found, but no xmi file exists. So I tried to use "python PySerial.py test" to open the PySerial DS. It did not work at the first time, because this file is created by the old pogo version, so some sentences and structure can not be availble now. Then I have changed something in the old "PySerial.py" and saved the new "PySerial.py". At the end, "python PySerial.py test" worked and the PySerial DS could be available. 

When you want to change something in the old "PySerial.py" file, you must be careful to use the original format which I think is from the old version of POGO. The symbol such as "------->" in front of each sentence must be kept.  "PyTango.Device_3Impl"  can not be used, "PyTango.Device_4Impl" is the newest version. "PyTango.PyDeviceClass" should be changed as "PyTango.DeviceClass".

I have also used the Write and Read method of PySerial class, Read method works but Write method did not work. So I have changed something in the Write method. Now the new Write method is available. But it is not like the original write method. Now I write command string into serial,  it works. But from the old code of write method, the input type is not string, but chararray. So I try to figure out this problem.



7.Usage of PySerial.

We can use "Write" method to send the commands. "Read" and "ReadLine" commands are used to read the result. One point is that, you can only "Read"/"ReadLine" after "Write". After "Read"/"ReadLine", "Read"/"ReadLine" can also work but the answer is always 0, because you have not "Write" somthing but already finished "Read"/"ReadLine".

In jive interface,the input type of Write method of PySerial is strict. "t 1" is a string and it can make the motor 0 move. 't 1' is signed 8 bits and can not make the Motor 0 work.

8.Copley Control 

At first, wine should be downloaded. The copley software should be downladed and installed by the help of wine. The install method is under the "~/.wine", use the command "wine start /unix "$HOME/Desktop/TronSetup.exe", then the "CME 2" is installed. 

The following steps are used by Lutz to create the /dev/ttyS0 port: 

"cd .wine/dosdevices"
"ls -al"
"ln -s /dev/ttyS0 com1:"
"ls -al"
"mv com1\: com1"
"ls -al"
"cat /dev/ttyS0"
"id"
"ls -al /dev/ttyS0"

Usage of the copley control commands:

The format of the message is in the page 12 of "ASCII_ProgrmmersGuide.pdf". "Programmed Position Mode" is in the page 29. These are the important content.

Due to the memory capacity of the motor, the written value will be saved, so only the move command can be used to detect whether the motor can be used: "t 1". "t 1\n" should be written into the serial port. Some other init commands such as "s r0x24 31" "s r0xc8 257" can be used to initialize the motor mode. A long string such as "s r0x24\n s r0xc8 257\r\n" can be also used to set something in motor mode at a time. "\n" can not be ignored, "\r" can be ignored by the write method. 

There are 2 Motors. The node ID is used to distinguish the different motors. The node ID of the first one is 0, the node ID of the second one is 2. 2 should be at the beginning of all the commands, when the second motor is used. "2 t 1\n" is used to move the second motor. 

9,Questions:

In the document of the serial port, the data is transmitted bit by bit. In the old "PySerial.py" file, the input of the write method is also chararray. But it does not work. I have also tried it in the ipython console, and the message is: "ValueError: string must be of size 1". So I change the input type as String. Have I done right?

