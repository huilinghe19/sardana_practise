from sardana.macroserver.macro import Macro, macro, Type

@macro()
def hello_world(self):
    self.output('Running hello_world...')


@macro()
def hello_world2(self):
    """This is an hello world macro"""
    print("Hello, World!")

    
class HelloWorld(Macro):
    """Hello, World! macro"""

    def run(self):
        print "Hello, World!"

