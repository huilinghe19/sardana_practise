How to write a motor controller:

1. Some libraries are imported from sadana. Some exceptions can be passed.

    from sardana import State
    from sardana.pool.controller import MotorController, Type, Description, DefaultValue
    
    class CommunicationError(Exception):
    pass
    
2. Constructor. If some extra initialization code is used, then we should use the method signature: __init__(self, inst, props, *args, **kwargs) and always call the super class constructor. (https://sardana-controls.org/devel/howto_controllers/howto_controller.html)
For example; we need add host = self.Host,  port = self.Port and self.blender_blades = BlenderBlades(host, port) into the initialization. 
  
  class BlenderBladesMotorController(MotorController):

      def __init__(self, inst, props, *args, **kwargs):
          super_class = super(BlenderBladesMotorController, self)
          super_class.__init__(inst, props, *args, **kwargs)
          host = self.Host
          port = self.Port
          self.blender_blades = BlenderBlades(host, port)
          
   If there is nothing extra to be initialized, then we can just use the __init__, for example, 
   
   class BlenderSlit(PseudoMotorController):
  
    pseudo_motor_roles = "gap01", "offset01"
    motor_roles = "top", "bottom"

    GAP = 1
    OFFSET = 2
    TOP = 1
    BOTTOM = 2

    def __init__(self, inst, props, *args, **kwargs):
        PseudoMotorController.__init__(self, inst, props, *args, **kwargs)
  
  
        
  3. The common API to all low level controllers includes the set of methods to:

        construct the controller
        add/delete a controller element [1]
        obtain the state of controller element(s) [2]
        define, set and get extra axis attributes
        define, set and get extra controller attributes
        define, set and get extra controller properties
        
 Extra axis attributes, controller attributes and controller properties can be defined at the first place. For example: 

axis_attributes = {
        "CloseLoop" : {
                Type         : bool,
                Description  : "(de)activates the motor close loop algorithm",
                DefaultValue : False,
            },
    }
    
    ctrl_attributes = {
        "ReflectionMatrix" : {
                Type         : ( (float,), ),
                Description  : "The reflection matrix",
                Access : DataAccess.ReadOnly,
            },
    }


    ctrl_properties = \
    {
        "host" : {
                Type : str,
                Description : "host name"
            },
        "port" : {
                Type : int,
                Description : "port number",
                DefaultValue: springfieldlib.SpringfieldMotorHW.DefaultPort
           },
    }
    
 4. Some important methods are:  
 
    def AddDevice(self, axis):
        self._motor[axis] = dict(step_per_unit=1.0)

    def ReadOne(self, axis):
        step_per_unit = self._motor[axis]["step_per_unit"]
        position = self.springfield.getPosition(axis)
        return position / step_per_unit

    def GetAxisPar(self, axis, name):
        springfield = self.springfield
    
    def SetAxisPar(self, axis, name, value):
        springfield = self.springfield
        name = name.lower()
        
    def StartOne(self, axis, position):
        # store information about this axis motion
        motion_info = axis, position
        self._moveable_info.append(motion_info)
        
    def StopOne(self, axis):
        self.springfield.stop(axis)

    def AbortOne(self, axis):
        self.springfield.abort(axis)
        
    def PreStartAll(self):
        # clear the local motion information dictionary
        self._moveable_info = []

    def StartAll(self):
        self.springfield.moveMultiple(self._moveable_info)
        
    def PreReadAll(self):
        # clear the local position information dictionary
        self._position_info = []

    def PreReadOne(self, axis):
        self._position_info.append(axis)

    def ReadAll(self):
        self._positions = self.springfield.getMultiplePosition(self._position_info)
        
   
5. About the copleyController:


I have written the controller script and put it in the "/controller" and it works.
I have configured the motors "stepnet01" and "stepnet02" for the first and second motor in sardana. We can get the positions and states of the two motors, We can move the first motor. But the second motor does not work. The commands are different.

For the first motor, the execution oder is: set the position using "s r0xca 10000\n" and then triger the motion using "t 1\n", the the first motor moves.
For the second motor, the execution oder is: set the position using "2 s r0xca 10000" and the triger the motion using "2 t 1\n", then the second motor moves.



The problem is: using a combined command "s r0xca 10000\n t 1\n" we can make the first motor move.
But using command "2 s r0xca 10000\n 2 t 1\n" the second motor can not be moved. This command works not in the second motor controller. That means, in the method StartOne(self,axis,position), we can not write a single command to make the second motor move. It is the main problem to be solved. 
How can we write the position and make the motor move with only one command in the method?

6. When you have problems with the spock commands and the motors, you can first check the motor state, when the state is fault, then check the controllers in sardana using "lsctrllib", if there is no this controller script, it means the program of the controller is wrong, you should correct the program. 
