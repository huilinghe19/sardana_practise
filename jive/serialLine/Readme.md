Copley Control

1. SerialLine 
 
 About the Read method: For example, we write "t 1" into the motors, and the reply should be "ok\r", using dev.read(1) 3 times can we get "o", "k", "\r". The end of the answer of an individual command is always "\r".
 
 About the write method, when we use write method directly, the input has to contain the "\n" at the end. For example, "t 1\n" "s r0x24 31\n 2 t 1\n", otherwise the command does not work. The input can also contain more than one control commands.
 
 2.ReadCheckReply 
 
 This is a method to check if the motor works well. When the answer is not as the same as expected, the answer is "unexpected reply from Copley controller". 

3. Wait 

Once a command in jive is activated, another method is always followed with this method:
In  pyserial/hhl/1 ::always_excuted_hook()
In  pyserial/hhl/1 ::Read()

This function is supported by the always_excuted_hook() method. This can prevent the mutual interference of command transmission. 

If you use many commands in one method in jive such as "ReadCheckReply", the it is not right. Because each method shall be used individually. 

"""
In  copley/hhl/1 ::always_excuted_hook()
In  copley/hhl/1 ::CheckReply()
In  copley/hhl/1 ::ResetMotors()
In  copley/hhl/1 ::SendComand()
"""
It can work, but the result is not stable. So do not use many different things in one command. The function of the command is just a certain function, not a complex function.

4.Commands

Reset: "r"
Check Motion: "g r0xA0" if the answer is "v 0", it means motion stop,
"v ..." means in motion. 
I have used "t 1" in ipython interface to make the motors move, and then I use the commands in jive to test the motion status. The response is true, but there is a small problem. At the first time, sometimes the response is not true. But the results are correct at the second time and afterwards. Because there is still content left in the read, so you must first clear the contents of the read. You cannot use the reset command to clear the rest content in the read. When you use reset command, the motion will be stopped at once. Once you use reset, all things will be back to the initial configuration. Especially the motion steps will not be the value you've set.


