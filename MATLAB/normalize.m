function [Xnorm] = normalize(X)
    Xnorm = (X - mean(X,2))./(max(X,[],2)-min(X,[],2));
end