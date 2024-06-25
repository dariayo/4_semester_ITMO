import math


class Result:

    def first_function(x: float, y: float):
        return math.sin(x)

    def second_function(x: float, y: float):
        return (x * y) / 2

    def third_function(x: float, y: float):
        return y - (2 * x) / y

    def fourth_function(x: float, y: float):
        return x + y

    def default_function(x: float, y: float):
        return 0.0

        # How to use this function:

    # func = Result.get_function(4)
    # func(0.01)
    def get_function(n: int):
        if n == 1:
            return Result.first_function
        elif n == 2:
            return Result.second_function
        elif n == 3:
            return Result.third_function
        elif n == 4:
            return Result.fourth_function
        else:
            return Result.default_function


    def solveByAdams(f, epsilon, a, y_a, b):
        try:
            step_count = int((b - a) / epsilon)
            function = Result.get_function(f)
            x = []
            for i in range(step_count + 1):
                x.append(a + i * epsilon)
            y = [y_a] * (step_count + 1)
            while a < b:
                for i in range(3):
                    k1 = epsilon * function(x[i], y[i])
                    k2 = epsilon * function(x[i] + epsilon / 2, y[i] + k1 / 2)
                    k3 = epsilon * function(x[i] + epsilon / 2, y[i] + k2 / 2)
                    k4 = epsilon * function(x[i] + epsilon, y[i] + k3)
                    y[i + 1] = y[i] + (k1 + 2 * k2 + 2 * k3 + k4) / 6
                    a += epsilon
                for j in range(4, step_count):
                    y[j + 1] = y[j] + (epsilon / 12) * (
                                23 * function(x[j], y[j]) - 16 * function(x[j - 1], y[j - 1]) + 5 * function(x[j - 2],
                                                                                                             y[j - 2]))
            return y[step_count]
        except:
            None


if __name__ == '__main__':
    f = int(input().strip())
    epsilon = float(input().strip())
    a = float(input().strip())
    y_a = float(input().strip())
    b = float(input().strip())

    result = Result.solveByAdams(f, epsilon, a, y_a, b)
    print(str(result) + '\n')  # Output the result
