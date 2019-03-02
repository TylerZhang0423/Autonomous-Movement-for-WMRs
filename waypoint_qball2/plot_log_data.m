%
% Plots various saved data signals from a QBall 2.
% Before running this script, you must first load a saved data MAT file.
%
t                       = qball_data(1,:);
motors                  = qball_data(2:5,:);
gyros                   = qball_data(6:8,:);
accel                   = qball_data(9:11,:);
accel_x                 = qball_data(9,:);
accel_y                 = qball_data(10,:);
accel_z                 = qball_data(11,:);

sonar                   = qball_data(12,:);
batt                    = qball_data(13,:);
h_cmd                   = qball_data(14,:);
height_rate_estimate    = qball_data(15,:);
u_height_d              = qball_data(16,:);
u_height_i              = qball_data(17,:);
roll                    = qball_data(18,:);
pitch                   = qball_data(19,:);
roll_cmd                = qball_data(20,:);
pitch_cmd               = qball_data(21,:);

roll_accel              = qball_data(22,:);
pitch_accel             = qball_data(23,:);
heading                 = qball_data(24,:);
heading_Kalman          = qball_data(25,:);
joy_t                   = qball_data(26,:);
x_cmd                   = qball_data(27,:);
z_cmd                   = qball_data(28,:);
height_cmd              = qball_data(29,:);
x                       = qball_data(30,:);
y                       = qball_data(31,:);

z                       = qball_data(32,:);
optitrack_tracking      = qball_data(33,:);
new                     = qball_data(34,:);
height_kalman           = qball_data(35,:);
height_above_ground     = qball_data(36,:);
timeout                 = qball_data(37,:);
optitrack_timeout       = qball_data(38,:);
%sonar                   = qball_data(39,:);
land                    = qball_data(40,:);
throttle_cmd            = qball_data(41,:);
u_height                = qball_data(41,:);

%height_mode             = qball_data(42:44,:);
control_mode            = qball_data(42,:);
takeoff                 = qball_data(43,:);
armed                   = qball_data(44,:);
u_roll                  = qball_data(45,:);
u_pitch                 = qball_data(46,:);
u_yaw                   = qball_data(47,:);
optitrack_roll          = qball_data(48,:);
optitrack_pitch         = qball_data(49,:);
yaw_optitrack           = qball_data(50,:);
sample_time             = qball_data(51,:);

roll_cmd_p              = qball_data(52,:);
roll_cmd_d              = qball_data(53,:);
roll_comp               = qball_data(54,:);
pitch_comp              = qball_data(55,:);
gyro_x                  = qball_data(56,:);
gyro_y                  = qball_data(57,:);
motor_cmd               = qball_data(58:61,:);

u_roll_p                = qball_data(62,:);
u_roll_d                = qball_data(63,:);
u_roll_i                = qball_data(64,:);
x_ref_from_host         = qball_data(65,:);
z_ref_from_host         = qball_data(66,:);
%gyro_y                  = qball_data(67,:);
%motor_cmd               = qball_data(68:71,:);
y_ref_from_host         = qball_data(67,:);
yaw_ref_from_host       = qball_data(68,:);
yaw_joystick            = qball_data(69,:);
roll_joystick           = qball_data(70,:);
pitch_joystick          = qball_data(71,:);



% Reconstruct individual motor commands
u1 = u_height + u_yaw  + u_pitch;
u2 = u_height + u_yaw  - u_pitch;
u3 = u_height + u_roll - u_yaw;
u4 = u_height - u_roll - u_yaw;


close all;


% Motor Command Check

figure;
plot(t, motors);
grid on; hold on;
legend('Back', 'Front', 'Left', 'Right');
title('PWM output');

figure;
plot(t,u_height);
hold on; grid on;
title('Height (Throttle) Command');

figure;
plot(t,u_roll);
hold on; grid on;
plot(t,u_pitch,'r'); 
plot(t,u_yaw,'k')
title('Roll, Pitch and Yaw Command');
legend('uRoll', 'uPitch', 'uYaw');

figure;
plot(t,u1,'g');
hold on; grid on;
plot(t,u2,'k');
plot(t,u3,'r');
plot(t,u4);
title('Desired Motor Commands - Prior to Saturation');
legend('u1', 'u2', 'u3', 'u4');



% Tracking Check

figure;
plot(t, x_cmd, t, x);
hold on; grid on;
title('X position command and estimate (m)'); 
legend('Ref', 'Estimated');

figure; 
plot(t, z_cmd, t, z); 
hold on; grid on;
title('Z position command and estimate (m)');
legend('Ref', 'Estimated');

figure; 
plot(x_cmd,-z_cmd,'r');
hold on; grid on;
plot(x,-z); 
title('Horizontal (X-Z) Tracking');
legend('Ref', 'Estimated');
xlabel('X (m)');
ylabel('-Z (m)');

figure; 
plot(t,h_cmd,'c'); 
hold on; grid on;  
plot(t,height_above_ground,'k'); 
plot(t,sonar,'r'); 
plot(t,y-OFFSET_HEIGHT,'g'); 
title('Height (Y) Tracking (m)');
legend('Ref', 'Estimated', 'Sonar', 'OptiTrack');


figure;
plot(t, heading_Kalman*180/pi,'r'); 
hold on; grid on;
plot(t,yaw_optitrack*180/pi);
title('Heading (deg)');
legend('Estimated', 'OptiTrack' );

figure;
plot(t, roll_cmd*180/pi);
hold on; grid on;
plot(t, roll*180/pi, 'r');
plot(t, optitrack_roll*180/pi,'k-.');
title('Roll Tracking (deg)');
legend('Ref', 'Estimated', 'OptiTrack');

figure;
plot(t, pitch_cmd*180/pi);
hold on; grid on;
plot(t, pitch*180/pi, 'r');
plot(t, optitrack_pitch*180/pi, 'k-.');
title('Pitch Tracking (deg)');
legend('Ref', 'Estimated', 'OptiTrack');



% Operational State

figure;
plot(t, batt);
hold on; grid on;
title('Battery voltage');

figure;
plot(t,optitrack_tracking,'r','MarkerSize',10);
hold on; grid on;
title('OptiTrack Tracking');

figure;
plot(t,joy_t,'g');
hold on; grid on;
title('Joystick Trigger (Throttle)');


% Raw sensor

%figure;
%plot(t, accel_x);
%hold on; grid on;
%plot(t, accel_y, 'r');
%plot(t, accel_z, 'k-.');
%title('Accelerometer (m/s^2)');
%legend('ax','ay','az');

%figure;
%plot(t, gyros(1,:));
%hold on; grid on;
%plot(t, gyros(2,:), 'r');
%plot(t, gyros(3,:), 'k-.');
%title('Gyro (rad/s)');
%legend('x','y','z');


