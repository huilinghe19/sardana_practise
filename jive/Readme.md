Jive 

1. How to open jive.
Link: https://tango-controls.readthedocs.io/en/latest/tools-and-extensions/jive/
In console: jive

2. My work: blenderbladescontroll device server(finished). Socket DS(finished). PySerial DS(finished). ManageServer(finished). CopleyControl DS(processing)

PySerial and CopleyControl class:
I habe created a new CopleyControl class, which uses the methods of PySerial class to move the motor.
About the functions in PySerial, it should be changed a little to adjust your own DS, when you want to use the functions of the standard PySerial class. I have changed the write method in PySerial class, to make the motor move. "Move" command uses the raw command "t 1" or "2 t 1", to make the 2 motors move. "SendCommand" command send the command in jive to the motors.

3. Tips: A device server just for one aim.

In the first process, I have used "ManageServer" to controll the device"s/hhl/1". I can write "move top 30" directly to the device "s/hhl/1", and the top blenderblades move to 30. 

In the second process, I add some commands in "ManageServer" device server, to communicate with the PySerial class. I wanted to send the raw command such as "t 1" to the device "/pyserial/hhl/1". It works at the first time without problems. But after I try to change something many times, some communication problems occur, such as SerialPort can be set as "simulation/hhl/1" automatically. But it is not the serial port. After that, I create a new class"CopleyControl", which is just copley control DS.



