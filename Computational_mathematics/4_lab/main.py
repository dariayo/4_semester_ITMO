import math


class Result:
    error_message = ""
    has_discontinuity = False
    eps = 1e-6

    def first_function(x: float):
        return 1 / x

    def second_function(x: float):
        if x == 0:
            return (math.sin(Result.eps) / Result.eps + math.sin(-Result.eps) / -Result.eps) / 2
        return math.sin(x) / x

    def third_function(x: float):
        return x * x + 2

    def fourth_function(x: float):
        return 2 * x + 2

    def five_function(x: float):
        return math.log(x)

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
        elif n == 5:
            return Result.five_function
        else:
            raise NotImplementedError(f"Function {n} not defined.")

    #
    # Complete the 'calculate_integral' function below.
    #
    # The function is expected to return a DOUBLE.
    # The function accepts following parameters:
    #  1. DOUBLE a
    #  2. DOUBLE b
    #  3. INTEGER f
    #  4. DOUBLE epsilon
    #
    def check_discontinuity(f, x):
        if f == 5 and x <= 0:
            return True
        return False

    def calculate_integral(a, b, f, epsilon):
        function = Result.get_function(f)
        if Result.check_discontinuity(f, a) or Result.check_discontinuity(f, b) or (f == 1 and (a == 0 or b == 0)):
            Result.has_discontinuity = True
            Result.error_message = "Integrated function has discontinuity or does not defined in current interval"
            return 0
        summ = (function(a) + function(b))
        n = 1
        previous = 0
        delta = b - a
        result = 0
        check = epsilon + 0.001
        while abs(check - previous) > epsilon:
            previous = result
            h = delta / n
            for i in range(n):
                if Result.check_discontinuity(f, a + i * h):
                    Result.has_discontinuity = True
                    Result.error_message = "Integrated function has discontinuity or does not defined in current interval"
                    return 0
                result += function(a + i * h)
            result += summ / 2
            result *= h
            check = result
            n = 2 * n
        return result


# Write your code here

if __name__ == '__main__':
    a = float(input().strip())

    b = float(input().strip())

    f = int(input().strip())

    epsilon = float(input().strip())

    result = Result.calculate_integral(a, b, f, epsilon)
    if not Result.has_discontinuity:
        print(str(result) + '\n')
    else:
        print(Result.error_message + '\n')
