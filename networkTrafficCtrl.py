import os
import time

from sardana import State
from sardana.pool.controller import CounterTimerController, Type,\
    Description, DefaultValue
import readnetworkcounter

class NetworkTrafficCounterTimerController(CounterTimerController):

    ctrl_properties = \
        {'interface': {Type : str,
                       Description : 'network interface to count packages',
                       DefaultValue : 'eno1'},
        }

    def __init__(self, inst, props, *args, **kwargs):
        CounterTimerController.__init__(self,inst,props, *args, **kwargs)
        self.acq_time = 1.
        self.acq_end_time = time.time()
        self.start_counts = 0
	self.interface='eno1'
    def LoadOne(self, axis, value):
        self.acq_time = value

    def StateOne(self, axis):
        state = State.On
        if time.time() < self.acq_end_time:
            state = State.Moving
        status_string = 'My custom status info'
        return state, status_string

    def StartOne(self, axis, _):
        self.acq_end_time = time.time() + self.acq_time
        self.start_counts = readnetworkcounter.read_network_counts(self.interface)

    def StartAll(self):
        pass

    def ReadOne(self, axis):
        counts = readnetworkcounter.read_network_counts(self.interface)
        return counts - self.start_counts

    def AbortOne(self, axis):
	self.acq_end_time = time.time()
