def func(x):
    return math.log(1 + x ** 2) - math.sin(x)


def quadratic_interpolation(x1, dx, e1, e2):
    while True:
        x2 = x1 + dx
        f1 = func(x1)
        f2 = func(x2)
        if f1 > f2:
            x3 = x1 + 2 * dx
        else:
            x3 = x1 - dx
        f3 = func(x3)
        fmin = min(f1, f2, f3)
        if fmin == f1:
            xmin = x1
        elif fmin == f2:
            xmin = x2
        else:
            xmin = x3
        numerator = (x2 ** 2 - x3 ** 2) * f1 + (x3 ** 2 - x1 ** 2) * f2 + (x1 ** 2 - x2 ** 2) * f3
        denominator = (x2 - x3) * f1 + (x3 - x1) * f2 + (x1 - x2) * f3
        if denominator == 0:
            x1 = xmin
            continue
        xw = 0.5 * numerator / denominator
        fw = func(xw)

        if abs((fmin - fw) / fw) < e1 and abs((xmin - xw) / xw) < e2:
            return xw
        if xw < x1 or xw > x3:
            x1 = xw
        else:
            if xmin > xw:
                x1 = xw
            elif xmin < xw:
                x1, x3 = xmin, xw
            else:
                x1, x3 = xw, xmin


x1 = 0
dx = 0.01
e1 = 0.001
e2 = 0.001

result = quadratic_interpolation(x1, dx, e1, e2)
print("Минимум функции:", result)
print("Значение функции в найденной точке:", func(result))
