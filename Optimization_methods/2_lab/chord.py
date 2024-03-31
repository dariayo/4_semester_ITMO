import math
import time

start = time.time()


def func(x):
    return math.log(1 + x ** 2) - math.sin(x)


def funcSec(x):
    return 2 * x / (x ** 2 + 1) - math.cos(x)


def method_chord(a, b, epsilon):
    fA = funcSec(a)
    fB = funcSec(b)
    xWave = a - fA / (fA - fB) * (a - b)
    fSec = funcSec(xWave)
    count = 0
    while abs(fSec) > epsilon:
        xWave = a - fA / (fA - fB) * (a - b)
        fSec = funcSec(xWave)
        if fSec > 0:
            b = xWave
            fB = fSec
        else:
            a = xWave
            fA = fSec
        count += 1
    x2 = xWave
    f = func(xWave)
    print(count)
    return [x2, f]


a = 0
b = math.pi / 4
eps = 0.001

result = method_chord(a, b, eps)
print(result)
end = time.time()
print(end-start)