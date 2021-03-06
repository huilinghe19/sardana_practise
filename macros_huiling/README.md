# Usage of macros: 

1. Set path of macros in Spock:

Method 1: 
          
            _MACRO_SERVER.put_property({"MacroPath":["/macros", "/usr/lib/python2.7/dist-packages/sardana/macroserver/macros/example", "/usr/lib/python2.7/dist-packages/sardana/macroserver/macros"]}),
           
  "/macros" is the path of the new custom macros, which are created by users. The default macros are in "/usr/lib/python3/dist-packages/sardana/src/sardana/macroserver/macros/". After we add the /macros as marco path, we can see this property in jive immediately. Restart sardana, then the new macros will be shown.

Method 2: 
In jive, we can set the path of macro server directly in the Property name and the Value. 

Tips: The order of the macro paths determines the priority. If there are 2 same macro names in different macro classes, then the practical function in spock is determined by the first macros. Others can be covered. In the above configuration, "/macros" has more privilege than the other 2 directories. 


2. Image Problem is solved by new installation: image can not shown in spock. Hinweis:'TypeError: 'figure' is an unknown keyword argument
(For more detailed information type: python_error)' has been solved. In the new debian system and after the correction for expconf, the macro random_image works well. The program is proved to be right. But the usage of random.random((32,32)) is not normal. In the documentation: 
    

    random.random()

    Return the next random floating point number in the range [0.0, 1.0).
    
    
 'plotting_huiling.py' in the folder 'plot_macro' works well. I habe imported matplotlib directly and changed the commands in the method 'random_image'. random_image macro is from: https://github.com/sardana-org/sardana/blob/develop/src/sardana/macroserver/macros/examples/plotting.py.

3.  Some small changes should be made. In oder to make both the commands 'tauruspanel' and 'taurusform' in the terminal and the command 'expconf' in spock run well at the same time, we need to change something in the file "/usr/lib/python2.7/dist-packages/taurus/qt/qtgui/tree/qtree.py", createViewWidget() method can not work well all the time, use following commands instead of h.setResizeMode(0, Qt.QHeaderView.Stretch) is the solution.  


    
        try:
    
         h.setResizeMode(0, Qt.QHeaderView.Stretch)
         
        except:
     
         h.setSectionResizeMode(0, Qt.QHeaderView.Stretch)
         
 
4. How to write new macros:(my example)

    1. Create a module 'salute.py' under the '/macros'. In the file there is a new macro, which is called 'hello_world'. Change the right and the owner of the file, to make sure spock can use it. 

    2. In spock console or jive, add the '/macros' as the MacroPath, use the command 'edmac hello_world salute', edmac is the edit command, hello_world is the macro name, salute is the module name. Then we can use it in spock. 
    
   3.  A macro can be a function or a class.  so in the "salute.py" module, we can define a function directly or write a class containing the function. Whether a function or a class is just up to you. If you are writing a sequencial procedure to run an experiment then you are probably better of writing a python function which does the job plain and simple. If you want to extend the behaviour of the mv macro, it is better to write a macro class. In this case, probably you would want to extend the existing macro by writing your own macro class which inherits from the original macro and this way benefit from most of the functionallity already existing in the original macro.

   
   
   The simplest macro class that you can write MUST obey the following rules:

        Inherit from Macro
        Implement the run() method

52 parameter types are defined in MacroServer e.g. Float, String, Motor, MeasurementGroup, etc. A parameter is characterized by: name, type, default value and description.
Parameters are defined either as argument of the macro decorator for the macro function or as param_def class member for the macro class.
Example 1:

    @macro([["moveable", Type.Moveable, None, "moveable to get position"]])
    def fixed_ascan(self, moveable):
        """This does an ascan starting at 0 ending at 100, in 10 intervals
        with integration time of 0.1s"""
        self.ascan(moveable, 0, 100, 10, 0.1)


Example 2:

    from sardana.macroserver.macro import Macro, Type, Optional
    class count(Macro):

        param_def = [
            ['itime', Type.Float, 1, 'integration time'],
            ['mntgrp', Type.MeasurementGroup, Optional, 'MntGrp to use']
        ]

        def run(self, itime, mntgrp):
            bkp_active_mntgrp = None
            try:
                if mntgrp is not None:
                    bkp_active_mntgrp = self.getEnv('ActiveMntGrp')
                    mntgrp_name = mntgrp.name
                    self.setEnv('ActiveMntGrp', mntgrp_name)
                self.info('Use "{0}" measurement group'.format(mntgrp_name))
                self.ct(itime)
            finally:
                if bkp_active_mntgrp is not None:
                    self.setEnv('ActiveMntGrp', bkp_active_mntgrp)

   
   
