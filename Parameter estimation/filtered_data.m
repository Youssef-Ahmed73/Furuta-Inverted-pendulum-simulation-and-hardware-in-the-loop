%% ===== Extract encoder data =====
ts = motor_encoder;

t = ts.Time;                 
y = squeeze(ts.Data);        

encoder_array = [t y];

%% ===== Sampling frequency =====
Ts = mean(diff(t));          
Fs = 1/Ts;                   

%% ===== Design Low-pass filter =====
fc = 5;                      
order = 4;

[b,a] = butter(order, fc/(Fs/2), 'low');

%% ===== Zero-phase filtering =====
y_filt = filtfilt(b,a,y);

encoder_array_filt = [t y_filt];

%% ===== Plot comparison =====
figure
plot(t,y,'r')
hold on
plot(t,y_filt,'b','LineWidth',1.5)
grid on
legend('Raw encoder','Filtered encoder')
xlabel('Time (s)')
ylabel('Encoder output')
title('Encoder Signal Before & After Filtering')