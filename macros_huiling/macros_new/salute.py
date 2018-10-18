from sardana.macroserver.macro import Macro, macro, Type

@macro()
def hello_world(self):
    self.output('Running hello_world...')
