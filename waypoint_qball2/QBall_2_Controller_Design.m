%
% Controller Design for QBall 2
%


% Loading QBall 2 System Paramters
QBall_2_System_Parameters;



% Set global control limits - safety
LIMIT_MAX_HEIGHT    =   2;          % (m) - Maximum CG Height set point 
LIMIT_MIN_HEIGHT    =   0.3;        % (m) - Minimum CG Height set point
LIMIT_MAX_X         =   1;          % (m) - Maximum CG X set point 
LIMIT_MIN_X         =   -1;         % (m) - Minimum CG X set point
LIMIT_MAX_Z         =   1;          % (m) - Maximum CG Z set point 
LIMIT_MIN_Z         =   -1;         % (m) - Minimum CG Z set point
LIMIT_MAX_YAW       = 170*pi/180;   % (rad) - Maximum CG Yaw set point 
LIMIT_MIN_YAW       =-170*pi/180;   % (rad) - Minimum CG Yaw set point
LIMIT_RATE_HEIGHT   =   0.05;       % (m/s) - Maximum CG Climb Reference Rate
LIMIT_RATE_X        =   0.15;       % (m/s) - Maximum CG X Reference Rate
LIMIT_RATE_Z        =   0.15;       % (m/s) - Maximum CG Z Reference Rate
LIMIT_RATE_YAW      = 15*pi/180;    % (rad/s) - Maximum CG Yaw Reference Rate

% Individual Control Channel Limits
LIMIT_uCMD_HEIGHT   = 0.5;          % 1 = 100% of rotor command
LIMIT_uCMD_ROLL     = 0.5;          % 1 = 100% of rotor command
LIMIT_uCMD_PITCH    = 0.5;          % 1 = 100% of rotor command
LIMIT_uCMD_YAW      = 0.5;          % 1 = 100% of rotor command

% Individual Rotor Control Command Limit
LIMIT_CMD_U         = 1;            % 1 = 100% of rotor command

% Outer Loop Roll/Pitch Command (For Horizontal Travel) Limit
LIMIT_CMD_ROLL      = 5*pi/180;     % (rad)
LIMIT_CMD_PITCH     = 5*pi/180;     % (rad)


% TRIM Values
TRIM_THROTTLE       = M*g/(4*K);    % 1 = 100% of rotor command
TRIM_U_ROLL         = -0.0065;      % 1 = 100% of rotor command
TRIM_U_PITCH        =  0.009;       % 1 = 100% of rotor command

TRIM_HEIGHT         = 0.7;          % (m) - Nominal Hover Height
TRIM_ROLL           = 0;            % (rad) - Nominal Hover Roll
TRIM_PITCH          = 0;            % (rad) - Nominal Hover Pitch



%
% PID Controller for QBall 2
%

%
% Battery UP/TOP Configuration
%

% Roll Controller
KpROLL_UP = 0.5;
KdROLL_UP = 0.1;
KiROLL_UP = 0.08;

% Pitch Controller
KpPITCH_UP = 0.5;
KdPITCH_UP = 0.1;
KiPITCH_UP = 0.08;

% Yaw Controller
KpYAW_UP = 0.45;
KdYAW_UP = 0.32;
KiYAW_UP = 0.0;

% Height Controller
KpHEIGHT_UP = 0.5;
KdHEIGHT_UP = 0.15;
KiHEIGHT_UP = 0.35;

% Outer Loop (Sideway) Controller
KpOUTER_ROLL_UP = 0.3; 
KdOUTER_ROLL_UP = 0.4;
KiOUTER_ROLL_UP = 0.08;

% Outer Loop (Forward/Backward) Controller
KpOUTER_PITCH_UP = 0.3;  
KdOUTER_PITCH_UP = 0.6;
KiOUTER_PITCH_UP = 0.08;


%
% Battery DOWN/BOTTOM Configuration
%

% Roll Controller
KpROLL_DOWN = 0.5;
KdROLL_DOWN = 0.1;
KiROLL_DOWN = 0.08;

% Pitch Controller
KpPITCH_DOWN = 0.5;
KdPITCH_DOWN = 0.1;
KiPITCH_DOWN = 0.08;

% Yaw Controller
KpYAW_DOWN = 0.45;
KdYAW_DOWN = 0.32;
KiYAW_DOWN = 0.0;

% Height Controller
KpHEIGHT_DOWN = 0.5;
KdHEIGHT_DOWN = 0.15;
KiHEIGHT_DOWN = 0.35;

% Outer Loop (Sideway) Controller
KpOUTER_ROLL_DOWN = 0.3; 
KdOUTER_ROLL_DOWN = 0.4;
KiOUTER_ROLL_DOWN = 0.08;
 
% Outer Loop (Forward/Backward) Controller
KpOUTER_PITCH_DOWN = 0.3;  
KdOUTER_PITCH_DOWN = 0.4;
KiOUTER_PITCH_DOWN = 0.08;


fprintf( '\n' );
fprintf( '************************************************** \n' );
fprintf( ' PID Controller - Battery UP/TOP Configuration\n' );
fprintf( '************************************************** \n' );
fprintf( '\n' );
fprintf( 'Channel         Kp      Kd      Ki \n' );
fprintf( '************************************************** \n' );
fprintf( 'Roll        : %6.4f, %6.4f, %6.4f\n', KpROLL_UP, KdROLL_UP, KiROLL_UP );
fprintf( 'Pitch       : %6.4f, %6.4f, %6.4f\n', KpPITCH_UP, KdPITCH_UP, KiPITCH_UP );
fprintf( 'Yaw         : %6.4f, %6.4f, %6.4f\n', KpYAW_UP, KdYAW_UP, KiYAW_UP );
fprintf( 'Height      : %6.4f, %6.4f, %6.4f\n', KpHEIGHT_UP, KdHEIGHT_UP, KiHEIGHT_UP );
fprintf( 'Outer Roll  : %6.4f, %6.4f, %6.4f\n', KpOUTER_ROLL_UP, KdOUTER_ROLL_UP, KiOUTER_ROLL_UP );
fprintf( 'Outer Pitch : %6.4f, %6.4f, %6.4f\n', KpOUTER_PITCH_UP, KdOUTER_PITCH_UP, KiOUTER_PITCH_UP );
fprintf( '************************************************** \n' );


fprintf( '\n' );
fprintf( '\n' );
fprintf( '************************************************** \n' );
fprintf( ' PID Controller - Battery DOWN/BOTTOM Configuration\n' );
fprintf( '************************************************** \n' );
fprintf( '\n' );
fprintf( 'Channel         Kp      Kd      Ki \n' );
fprintf( '************************************************** \n' );
fprintf( 'Roll        : %6.4f, %6.4f, %6.4f\n', KpROLL_DOWN, KdROLL_DOWN, KiROLL_DOWN );
fprintf( 'Pitch       : %6.4f, %6.4f, %6.4f\n', KpPITCH_DOWN, KdPITCH_DOWN, KiPITCH_DOWN );
fprintf( 'Yaw         : %6.4f, %6.4f, %6.4f\n', KpYAW_DOWN, KdYAW_DOWN, KiYAW_DOWN );
fprintf( 'Height      : %6.4f, %6.4f, %6.4f\n', KpHEIGHT_DOWN, KdHEIGHT_DOWN, KiHEIGHT_DOWN );
fprintf( 'Outer Roll  : %6.4f, %6.4f, %6.4f\n', KpOUTER_ROLL_DOWN, KdOUTER_ROLL_DOWN, KiOUTER_ROLL_DOWN );
fprintf( 'Outer Pitch : %6.4f, %6.4f, %6.4f\n', KpOUTER_PITCH_DOWN, KdOUTER_PITCH_DOWN, KiOUTER_PITCH_DOWN );
fprintf( '************************************************** \n' );


fprintf( '\n' );
