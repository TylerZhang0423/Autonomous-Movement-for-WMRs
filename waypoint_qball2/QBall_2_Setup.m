%
% This file runs the calibration and initialization files for the QBall 2.
% This file is run automatically when the model is loaded or can be run
% manually.

% Joystick Control Range Mapping
% Joystick input range [0:1] maps to the following range for increased
% control sensitivity.
joystick_range_min = 0.5;
joystick_range_max = 0.8;

% Loads controller parameters for QBall 2
QBall_2_Controller_Design;
