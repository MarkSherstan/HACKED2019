s = serial ('/dev/cu.usbmodem14201')
set(s,'BaudRate',9600);
fopen(s);
fprintf(s,'*IDN?');

tic
while toc < 10

    out = fscanf(s)
end

fclose(s)
delete(s)
clear s
