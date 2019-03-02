Quanser UVS Lab: QBot 2 (Leader) / QBot 2 (Follower) Demo (v2.1)
================================================================

To run the QBot 2 (Leader) / QBot 2 (Follower) Demo:

0) Position the QBot 2 (Leader) (forward facting towards the operator station) at the origin of the workspace and turn it on. Position the QBot 2 (Follower) (forward facing towards teh operator station) next to the QBot 2 (Leader) and turn it on. Make sure there is enough space for BOTH the Leader and Follower to move for this demo (approximately 2m in each direction from the origin). Notice that the starting position of the Follower should NOT be in the direct path between the Leader (at the origin) and the first Waypoint (default is [ 0.75, 0.75 ], towards the right and closer to the operator side). Otherwise, the Leader might collide with the Follower as the Leader has no information on where the Follower is. Try pinging the IP addresses of BOTH the Leader and the Follower in a command prompt window to make sure communications between the vehicles and the Operator HOST PC are working properly.

1) Open the mission_server_leader_follower_qbot2_qbot2.mdl file. 

2) Specify the appropriate Camera Calibration file (*.cal) and the Trackable Definition file (*.tra) in the "OptiTrack Trackables" block found under the "OptiTrack Measurements" subsystem. Also, make sure the correct Trackable ID is specified. Default is [2 4]: QBall 2 is ID #1 and #3; while QBot 2 is ID #2 and #4 (assuming two different patterns are defined for each vehicle).

3) Compile and Run the mission_server_leader_follower_qbot2_qbot2.mdl file.

4) Open the leader_qbot2.mdl file.

5) Specify the appropriate IP address for the Operator HOST PC in the URI string defined in the "String Constant" block under the "URI Definitions" subsystem. For example, if the HOST PC IP address is 192.168.2.222, then the URI in the "String Constant" block should be "tcpip://192.168.2.222:18006". The port number (18006) should not be changed.

6) Specify the appropriate IP address for the QBot 2 (Leader) in the MEX-file argument for the leader_qbot2.mdl model under Simulation->Model Configuration Parameters->code Generation->Interface. Example MEX-file arguments string (for a QBot 2 IP address of 192.168.2.33) is: 

	'-w -d /tmp -uri %u', 'tcpic://192.168.2.33:17001?nagle=no,keep_alive=1'

7) Compile and Run the leader_qbot2.mdl file.

8) Open the follower_qbot2.mdl file.

9) Specify the appropriate IP addresses for both the Operator HOST PC and the QBot 2 (Leader) in the URI strings defined in the "String Constant" blocks under the "URI Definitions" subsystem.  For example, if the HOST PC IP address is 192.168.2.222, then the URI in the "String Constant" block for the HOST URI should be "tcpip://192.168.2.222:18005". The port number (18005) should not be changed. Similarly, if the Qbot 2 (Leader) IP address is 192.168.2.33, then the URI in the "string Constant" block for the LEADER URI should be "tcpip://192.168.2.33:18007". Again, the port number (18007) should not be changed.

10) Specify the appropriate IP address for the QBot 2 (Follower) in the MEX-file argument for the follower_qbot2.mdl model under Simulation->Model Configuration Parameters->code Generation->Interface. Example MEX-file arguments string (for a QBot 2 IP address of 192.168.2.44) is: 

	'-w -d /tmp -uri %u', 'tcpic://192.168.2.44:17001?nagle=no,keep_alive=1'

11) Compile and Run the follower_qbot2.mdl file.

12) The Leader should not move when the model is first started; the Follower might move slightly towards the Leader and stop at a short distance away from the Leader. To start the demo, go back to the mission_server_leader_follower_qbot2_qbot2.mdl file and TOGGLE the manual switch at the top level (located right below the "Trajectory Generation" block) to change the value of the "start_stop" variable. The trigger is through a value change of the "start_stop" variable, so the actual value is not important in this case.

13) Once the "start_stop" variable is triggered, the QBot 2 (Leader) should start moving towards the first waypoint. As soon as the Leader (QBot 2) is moving the Follower (QBot 2) should start following the Leader (QBot 2) from waypoint to waypoint (while keeping a bit of distance behind). The demo can be stopped at any time by TOGGLING the manual switch again.

14) The demo is completed when the Leader (QBot 2) returns back close to the workspace origin and stops.  The Follower (QBot 2) should stop at a position a short distance away from where the Leader stops.

15) TOGGLE the manual switch again to stop the demo.

16) Stop and close the follower_qbot2.mdl, leader_qbot2.mdl and mission_server_leader_follower_qbot2_qbot2.mdl files in that order.

17) Power off both QBot 2 when finished.
