import math
import time

start = time.time()


def func(x):
    return math.log(1 + x ** 2) - math.sin(x)


def gold_method(a, b, epsilon):
    x1 = a + 0.382 * (b - a)
    x2 = a + 0.618 * (b - a)
    y1 = func(x1)
    y2 = func(x2)
    count = 0
    while (b - a) > 2 * epsilon:
        if y1 <= y2:
            b = x2
            x2 = x1
            y2 = y1
            x1 = a + 0.382 * (x2 - a)
            y1 = func(x1)
        else:
            a = x1
            x1 = x2
            y1 = y2
            x2 = a + 0.618 * (b - x1)
            y2 = func(x2)
        count += 1
    xm = (a + b) / 2
    f = func(xm)
    print(count)
    return [xm, f]


a = 0
b = math.pi / 4
epsilon = 0.001

result = gold_method(a, b, epsilon)
print(result)
end = time.time()
print(end-start)