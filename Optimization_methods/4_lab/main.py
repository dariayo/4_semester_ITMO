import math


def f(x1, x2):
    return x1 ** 4 + x2 ** 4 - 4 * x1 * x2


def compute_gradient(x):
    return [4 * x[0] ** 3 - 4 * x[1], -4 * x[0] + 4 * x[1] ** 3]

def gradient_module(x):
    dx1, dx2 = compute_gradient(x)
    return (dx1 ** 2 + dx2 ** 2) ** 0.5


x = [0.01, 0.01]
step_value = 0.5
accuracy = 0.05


def gradient():
    count = 0
    while True:
        f_current = f(x[0], x[1])
        l = step_value
        if gradient_module(x) <= accuracy:
            break
        while True:
            count += 1
            dx1,dx2 = compute_gradient(x)
            x1_new = x[0] - l * dx1
            x2_new = x[1] - l * dx2
            f_new = f(x1_new, x2_new)
            print(f_new)
            if f_new < f_current:
                break
            l /= 2
        x[0] = x1_new
        x[1] = x2_new
    return x[0], x[1], f(x[0], x[1])


result = gradient()
print(result)
