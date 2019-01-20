data1 = csvread('../data/1914_Bourk.csv');
data2 = csvread('../data/2042_Bourk.csv');

RicoTrain = csvread('../data/2353_RicoTrain.csv');
RicoTest = csvread('../data/2414_RicoTest.csv');

Xtrain = normalize(RicoTrain(:, 1:end-1));
Ytrain = RicoTrain(:,end);
Ttrain = [Xtrain, Ytrain];

Xtest = normalize(RicoTest(:, 1:end-1));
Ytest = RicoTest(:,end);
Ttest = [Xtest, Ytest];

yfit = SVMG_RicoTrain.predictFcn(Xtest);
accuracy = sum(yfit == Ytest)/length(Ytest);
disp(accuracy);

totalnew = [Ttrain;Ttest];
