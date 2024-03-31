import math
import time

start = time.time()


def F(x):
    return math.log(1 + x ** 2) - math.sin(x)


def F1(x):
    return 2 * x / (x ** 2 + 1) - math.cos(x)


def F2(x):
    return math.sin(x) - (2 * x ** 2 - 2) / (x ** 4 + 2 * x ** 2 + 1)


def newton_method(a, b, epsilon):
    count = 0
    x0 = (a + b) / 2
    xk = F(x0)
    xk1 = xk - F(xk) / F1(xk)
    while abs(F1(xk)) > epsilon:
        xk = xk1
        xk1 = xk - F1(xk) / F2(xk)
        count += 1
        print(xk)
    f = F(xk)
    print(count)
    return [xk, f]


a = 0
b = math.pi / 4
epsilon = 0.001

result = newton_method(a, b, epsilon)
print(result)
end = time.time()
print(end - start)
