Quanser UVS Lab: QBall 2 Waypoint Demo (v2.1)
=============================================

To run the QBall 2 Waypoint Demo:

0) Position the QBall 2 at the origin of the workspace (tail pointing towards the operator station) and turn it on. Make sure there is enough space for the QBall 2 to move for this demo (approximately 2m in each direction from the origin). Try pinging the QBall 2 IP address in a command prompt window to make sure communication between the QBall 2 and Operator HOST PC is working properly.

1) Open the mission_server_waypoint_qball2.mdl file. 

2) Specify the appropriate Camera Calibration file (*.cal) and the Trackable Definition file (*.tra) in the "OptiTrack Trackables" block found under the "OptiTrack Measurements" subsystem. Also, make sure the correct Trackable ID is specified.

3) Compile and Run the mission_server_waypoint_qball2.mdl file.

4) Open the leader_qball2.mdl file.

5) Specify the appropriate IP address for the Operator HOST PC in the URI string defined in the "String Constant" block under the "URI Definitions" subsystem. For example, if the HOST PC IP address is 192.168.2.222, then the URI in the "String Constant" block should be "tcpip://192.168.2.222:18006". The port number (18006) should not be changed.

6) Specify the appropriate IP address for the QBall 2 in the MEX-file argument for the leader_qball2.mdl model under Simulation->Model Configuration Parameters->code Generation->Interface. Example MEX-file arguments string (for a QBall 2 IP address of 192.168.2.33) is: 

	'-w -d /tmp -uri %u', 'tcpic://192.168.2.33:17001?nagle=no,keep_alive=1'

7) Compile and Run the leader_qball2.mdl file.

8) The QBall 2 should not move when the model is first started. To start the demo, go back to the mission_server_waypoint_qball2.mdl file and TOGGLE the manual switch at the top level (located right below the "Waypoint Scheduler" block) to change the value of the "start_stop" variable. The trigger is through a value change of the "start_stop" variable, so the actual value is not important in this case.

9) The QBall 2 will then take-off and start flying from waypoint to waypoint. The QBall 2 can be commanded to land at any time by TOGGLING the manual switch again.

10) The demo is completed when the QBall 2 returns back close to the workspace origin and hovers.

11) TOGGLE the manual switch again to land the QBall 2.

12) Stop and close the leader_qball2.mdl and mission_server_waypoint_qball2.mdl files in that order.

13) Power off the QBall 2 when finished.
