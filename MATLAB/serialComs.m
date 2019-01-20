try

    fclose('all');
    % s = serial ('/dev/cu.usbmodem14201');
    s = serial ('COM6');
    set(s,'BaudRate',115200);
    fopen(s);
    fprintf(s,'*IDN?');
    load SVM6_Eric.mat;
    pause(3);
    tic
    while toc < 15
        toc
        fprintf(s, "a");
        out = fscanf(s, '%40s\n');
        split = strsplit(out, ',');
        split = strrep(split, 'NaN', '0');
        force = str2double(split(1:end-1));
        y = SVM6_Eric.predictFcn(force);
%         y = round(y);
        fprintf(s, "s%i\n", y);
        pause(0.01);
        fprintf("%d\n",y);
    end

    fclose(s);
    delete(s)
    clear s
catch ME
    disp(ME);
    fclose(s);
    delete(s)
    clear s
end
