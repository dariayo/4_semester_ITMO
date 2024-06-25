import math

from scipy.optimize import minimize_scalar


def function(x):
    return x[0] ** 4 + x[1] ** 4 - 4 * x[0] * x[1]


def compute_gradient(x):
    return [4 * x[0] ** 3 - 4 * x[1], -4 * x[0] + 4 * x[1] ** 3]


def compute_norm(vector):
    return math.sqrt(sum([element ** 2 for element in vector]))


epsilon = 0.05
x_old = [0.01, 0.01]


def gradient():
    x = x_old
    while True:
        gradient_value = compute_gradient(x)
        gradient_norm = compute_norm(gradient_value)
        if gradient_norm < epsilon:
            return x, function(x)
        s = []
        for i in range(len(x)):
            s.append(gradient_value[i])

        result = minimize_scalar(lambda step: function([x[i] - step * s[i] for i in range(len(x))]))
        x[0] = x[0] - result.x * s[0]
        x[1] = x[1] - result.x * s[1]


optimal_solution = gradient()

print(optimal_solution)
