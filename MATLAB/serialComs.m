try

    fclose('all');
    s = serial ('COM6');
    set(s,'BaudRate',115200);
    fopen(s);
    fprintf(s,'*IDN?');
    load('SVMG_RicoTrain');
    pause(3);
    tic
    while toc < 10

        fprintf(s, "a");
%         out = fscanf(s);
        out = fscanf(s, '%40s\n');
        split = strsplit(out, ',');
        split = strrep(split, 'NaN', '0');
        force = str2double(split(1:end-1));
        y = SVMG_Mark.predictFcn(force);
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
