Copley Control

1. SerialLine 
 
 About the Read method: For example, we write "t 1" into the motors, and the reply should be "ok\r", using dev.read(1) 3 times can we get "o", "k", "\r". The end of the answer of an individual command is always "\r".
 
 About the write method, when we use write method directly, the input has to contain the "\n" at the end. For example, "t 1\n" "s r0x24 31\n 2 t 1\n", otherwise the command does not work. The input can also contain more than one control commands.
 
 2.ReadCheckReply 
 
 This is a method to check if the motor works well. When the answer is not as the same as expected, the answer is "unexpected reply from Copley controller". 
