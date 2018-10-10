The process of using sequencer is as follows.
1.	Open blender server, sardana server, spock
2.	Premise: In spock, there are 4 blender blades motors:  top, bottom, right, left, which we have already set before.  ‘net’ is the counter in measurement group ‘mntgrp03’.
3.	Open Taurus Trend in MATE Terminal with the command: 
taurustrend top/position "eval:bool({top/state})" -r 10
4.	Open sequencer in another MATE Terminal with the command: ‘sequencer’
5.	In spock. step1: Configure measurement group: ‘senv ActiveMntGrp mntgrp03’. 
6.	In spock. step2: ‘senv ScanFile test.h5’and ’senv ScanDir /tmp’
7.	In spock. step3: Configure long acceleration and deceleration times: top.acceleration = 2 and top.deceleration = 2
8.	In sequencer. step1: configure with macroserver/demo1/1
9.	In sequencer. step2: add commands such as umv ascan senv 
10.	 In sequencer. step3: set parameters of the  commands in the ‘parameter/value’ windows
11.	 In sequencer. step4: run with the green small arrow. Then the results are shown in the taurus trend and the spock console. The xml file of this execution can be also stored.
12. The image 'sequencer_display.png' shows the results, we can use the commands in sequncer to controll of the top blender motor(of course all motors can be controlled). We can see the movement in blenderplayer and also get the record in the spock and taurus trend.  
