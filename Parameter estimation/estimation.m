% Load data
load('system_ramp_50.mat')

% Extract time and data
ts=motor_encoder;
t = ts.Time(ts.Time>=0.99)-0.99;                        % Time

datasize = length(t);

y = squeeze(ts.Data(end-datasize+1:end))*2*pi;          % Encoder data [rad]
s = diff(y)*60/(2*pi*0.01);                             %speed [RPM]

order = 6; fc=10; Fs=1/(t(2)-t(1));
[b,a] = butter(order, fc/(Fs/2), 'low');
sf = filtfilt(b,a,s(2:end));
speed=[s(1:2);sf];
% Put in one array
ramp_50_angle = timeseries(y,t);
ramp_50_speed = timeseries(speed,t);
%ramp_50_input=timeseries(linspace(,t);