def func(x):
    return math.log(1 + x ** 2) - math.sin(x)


a = 0
b = math.pi / 4
epsilon = 0.001


def half_method(a, b, epsilon):
    count = 0
    while (b - a) > 2 * epsilon:
        x1 = (a + b - epsilon) / 2
        x2 = (a + b + epsilon) / 2
        y1 = func(x1)
        y2 = func(x2)
        if y1 > y2:
            a = x1
        else:
            b = x2
        count += 1
    xm = (a + b) / 2
    ym = func(xm)
    print(count)

    return [xm, ym]


result = half_method(a, b, epsilon)
print(result)

