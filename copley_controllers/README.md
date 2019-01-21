#  Copley Controller in Sardana 

Usage of copleyController in sardana:
-------------------------------------------------------------------
1. Open sardana(command "Sardana demo1"), open spock(command "spock"), put the file "copleyController.py" in the folder "/controllers".
2. In spock, use the command "lsctrllib" to check if the copleyController works. 
3. When the copleyController exists, then we can use the command "defctrl CopleyController copleyctrl" to define copleyctrl.
Then the commands "defelem stepnet01 copleyctrl 1", "defelem stepnet02 copleyctrl 2" are to define the motors. Command "wa" can be used to show all motors. The command "stepnet01.state()" can be used to check the state. "mv stepnet01 10000" or "move stepnet01 10000" can be used to move the motors. 
4. In the program of "copleyController.py", the type of the output of each method can be changed automatically within sardana in oder to adjust the instrument controller. For example, int type can be changed into float and when you input the value of a number, such as "mv stepnet 10000" in spock, in the program we want to send the command "s r0xca 10000\n" to the serial line, be aware that, the raw input of 10000 you set can be automatically transfered into 10000.0 in sardana, then you will get "r 0xca 10000.0\n", this command does not work.
