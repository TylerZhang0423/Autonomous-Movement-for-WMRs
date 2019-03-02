%
% System Parameters for QBall 2
%


%
% Actuator Parameters
%

% Rotor bandwidth
omega   = 15;   % rad/s


% Rotor Force and Torque Constant (per normalized input)
K   = 12;       % N
Ky  = 0.4;      % N*m

% Rotor horizontal offset from C.G.
L = 0.2;        % m


%
% Inertial Properties
%

% Mass
M = 1.79;       % kg

% Roll/Pitch Moment of Inertia
J = 0.03;       % kg*m/s^2

% Yaw Moment of Inertia
Jyaw = 0.04;    % kg*m/s^2

% Gravitational Acceleration
g = 9.81;       % m/s^2


%
% Geometric Parameters
%

% QBall 2 Body Fixed Reference Vertical Offset from ground 
% (height on ground)
OFFSET_HEIGHT = 0.3;    % m

% Sonar Vertical Offset from QBall 2 Body Fixed Reference
OFFSET_SONAR = 0.28;    % m

% Sonar Distance Limit - Based on hardware spec
% Model: XL-MaxSonar-EZ3
LIMIT_MIN_SONAR = 0.2;      % m
LIMIT_MAX_SONAR = 7.65;     % m
% Safety limit for indoor operation
LIMIT_MAX_SONAR_SAFETY = LIMIT_MAX_SONAR*0.4;   % m

%
% Signal Conditioning
%

% Various Timeout
TIMEOUT_INIT_MOTOR = 3;     % (s) - Motor initial timeout
TIMEOUT_HOST = 1;           % (s) - Host connection timeout
TIMEOUT_OPTITRACK = 1;      % (s) - OptiTrack Tracking timeout
TIMEOUT_CALIB = 1;          % (s) - Sensor Calibration timeout/period

% Second order filter parameters for generating rate data
OMEGA_DIFF = 60;    % (rad/s) - For generating rate data
OMEGA_FILTER = 60;  % (rad/s) - For smoothing data


