1. set path of macros in Spock: _MACRO_SERVER.put_property({"MacroPath":["/hone/huiling/sardana/src/sardana/macroserver/macros/examples"]})
2. Problem: image can not shown in spock. Hinweis:'TypeError: 'figure' is an unknown keyword argument
(For more detailed information type: python_error)'
3. 'Plotting_huiling.py' works well. It is from: https://github.com/sardana-org/sardana/blob/develop/src/sardana/macroserver/macros/examples/plotting.py , which is verbunden with the macro 'random_image'. I habe imported matplotlib directly. That means, the python module 'plotting.py' has no problem. The problem is in the macro module or in the spock configuration. 
