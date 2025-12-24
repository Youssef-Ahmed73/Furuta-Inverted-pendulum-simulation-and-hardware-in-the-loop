% Load data
load('system_sine_15rad.mat')

% Extract time and data
ts=motor_encoder;
t = ts.Time;                        % Time
y = squeeze(ts.Data)*2*pi;          % Encoder data [rad]
s = diff(y)*60/(2*pi*0.01);                             %speed [RPM]

order = 15; fc=5; Fs=1/(t(2)-t(1));
[b,a] = butter(order, fc/(Fs/2), 'low');
sf = filtfilt(b,a,s(2:end));
speed=[s(1:2);sf];
% Put in one array
sine_15rad_angle = timeseries(y,t);
sine_15rad_speed = timeseries(speed,t);

x=0:length(t);
sine_15rad_input=timeseries(255*abs(sind(x(1:end-1)*15)),t);
plot(sine_15rad_input)
hold on
plot(t(1:end-1),s)
plot(sine_15rad_speed)