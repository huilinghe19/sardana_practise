Usage of macros: 

1. Set path of macros in Spock: _MACRO_SERVER.put_property({"MacroPath":["/macros", "/usr/lib/python2.7/dist-packages/sardana/macroserver/macros/examples"]}), "/macros" is the path of the new custom macros, which we define by ourselves.


2. The Problem: image can not shown in spock. Hinweis:'TypeError: 'figure' is an unknown keyword argument
(For more detailed information type: python_error)' has been solved. In the new debian system and after the correction for expconf, the macro random_image works well. The program is proved to be right. But the usage of random.random((32,32)) is not normal. In the documentation: 
    

    random.random()

    Return the next random floating point number in the range [0.0, 1.0).
    

3. 'plotting_huiling.py' in the folder 'plot_macro' works well. I habe imported matplotlib directly and changed the commands in the method 'random_image'. random_image macro is from: https://github.com/sardana-org/sardana/blob/develop/src/sardana/macroserver/macros/examples/plotting.py.

4.  We need to change something in the file "/usr/lib/python2.7/dist-packages/taurus/qt/qtgui/tree/qtree.py", in oder to make both the commands 'tauruspanel' and 'taurusform' in the terminal and the command 'expconf' in spock run well at the same time. createViewWidget() method can not work well all the time, use following commands instead of h.setResizeMode(0, Qt.QHeaderView.Stretch) is the solution.  


    try:
         h.setResizeMode(0, Qt.QHeaderView.Stretch)
     except:
         h.setSectionResizeMode(0, Qt.QHeaderView.Stretch)
