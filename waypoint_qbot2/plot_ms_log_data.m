%
% Plot various saved data signals from the Mission Server model
% Before running this script, the associated mission server saved MAT data 
% file must be loaded first.
%

ms_t                = mission_data(1,:);
ms_StartStop        = mission_data(2,:);
ms_LeadTracking     = mission_data(3,:);
ms_FollowTracking   = mission_data(4,:);

ms_xref             = mission_data(12,:);   % Desired CMD
ms_zref             = mission_data(13,:);
ms_xref_cmd         = mission_data(14,:);   % Actual CMD
ms_zref_cmd         = mission_data(15,:);
ms_lead_x           = mission_data(16,:);
ms_lead_y           = mission_data(17,:);
ms_lead_z           = mission_data(18,:);
ms_lead_roll        = mission_data(19,:);
ms_lead_pitch       = mission_data(20,:);
ms_lead_yaw         = mission_data(21,:);

ms_follow_x         = mission_data(22,:);
ms_follow_y         = mission_data(23,:);
ms_follow_z         = mission_data(24,:);
ms_follow_roll      = mission_data(25,:);
ms_follow_pitch     = mission_data(26,:);
ms_follow_yaw       = mission_data(27,:);

% Tracking performance
set(0,'defaultfigurecolor','w');
figure;
plot(ms_t, ms_xref);
hold on; grid on;
plot(ms_t, ms_xref_cmd, 'r');
title('Waypoint - X')
legend('Desired', 'Commanded');

figure;
plot(ms_t, ms_zref);
hold on; grid on;
plot(ms_t, ms_zref_cmd, 'r');
title('Waypoint - Z')
legend('Desired', 'Commanded');

figure;
plot(ms_xref_cmd, -ms_zref_cmd);
hold on; grid on;
plot(ms_lead_x, -ms_lead_z, 'r');
plot(ms_follow_x,-ms_follow_z, 'k-.');
title('Horizontal (x-Z) Trajectory')
legend('Ref', 'robot1');
xlabel('X (m)');
ylabel('Negative Z (m)');


figure;
plot(ms_t, ms_xref_cmd);
hold on; grid on;
plot(ms_t, ms_lead_x, 'r');
plot(ms_t, ms_follow_x, 'k-.');
title('Tracking - X (m)');
legend('Ref', 'robot1');

figure;
plot(ms_t, ms_zref_cmd);
hold on; grid on;
plot(ms_t, ms_lead_z, 'r');
plot(ms_t, ms_follow_z, 'k-.');
title('Tracking - Z (m)');
legend('Ref', 'robot1');

figure;
plot(ms_t, ms_LeadTracking);
hold on; grid on;
plot(ms_t, ms_FollowTracking,'r');
title('OptiTrack Tracking Status');
legend('Leader', 'Follower');

