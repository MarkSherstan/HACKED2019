model = load('SVMG_RicoTrain');
data = csvread('../data/2353_RicoTrain.csv');

Xtest = normalize(data(:, 1:end-1));
Ytest = data(:,end);
Ttest = [Xtest, Ytest];

yfit = SVMG_RicoTrain.predictFcn(Xtest);
accuracy = sum(yfit == Ytest)/length(Ytest);
disp(accuracy);