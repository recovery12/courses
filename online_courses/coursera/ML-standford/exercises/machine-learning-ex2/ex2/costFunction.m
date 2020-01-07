function [J, grad] = costFunction(theta, X, y)
%COSTFUNCTION Compute cost and gradient for logistic regression
%   J = COSTFUNCTION(theta, X, y) computes the cost of using theta as the
%   parameter for logistic regression and the gradient of the cost
%   w.r.t. to the parameters.

% Initialize some useful values
m = length(y); % number of training examples

% You need to return the following variables correctly 
J = 0;
grad = zeros(size(theta));

% ====================== YOUR CODE HERE ======================
% Instructions: Compute the cost of a particular choice of theta.
%               You should set J to the cost.
%               Compute the partial derivatives and set grad to the partial
%               derivatives of the cost w.r.t. each parameter in theta
%
% Note: grad should have the same dimensions as theta
%

function hx = h(theta, x),
    z = sum(transpose(theta).*x);
    hx = 1/(1+e^(-z));
end;

for i = 1:m,
    hx = h(theta, X(i, :));
    J = J + (-y(i)*log(hx)-(1-y(i))*log(1-hx));
end;
J = J/m;

for i = 1:m,
    hx = h(theta, X(i, :));
    grad(1) = grad(1) + (hx - y(i));
end;
grad(1) = grad(1)/m;

for i = 1:m,
    hx = h(theta, X(i, :));
    grad(2) = grad(2) + (hx - y(i))*X(i, 2);
end;
grad(2) = grad(2)/m;

for i = 1:m,
    hx = h(theta, X(i, :));
    grad(3) = grad(3) + (hx - y(i))*X(i, 3);
end;
grad(3) = grad(3)/m;


% =============================================================

end
