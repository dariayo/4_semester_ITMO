#
# Complete the 'interpolate_by_newton' function below.
#
# The function is expected to return a DOUBLE.
# The function accepts following parameters:
#  1. INTEGER f
#  2. DOUBLE a     
#  3. DOUBLE b     
#  4. DOUBLE x
#
def newton_polinom(x, nodes, func):
    func_in_node = [func(node) for node in nodes]  # значение функции в конкретном узле
    for i in range(1, len(func_in_node)):
        for j in range(len(func_in_node) - 1, i - 1, -1):
            func_in_node[j] = (func_in_node[j] - func_in_node[j - 1]) / (nodes[j] - nodes[j - i]) # формула разделенной разности
    value = func_in_node[-1]  # В начале устанавливается начальное значение value равное последнему коэффициенту func_in_node[-1]
    for i in range(len(func_in_node) - 2, -1, -1):
        value = func_in_node[i] + (x - nodes[i]) * value
    return value


def interpolate_by_newton(f, a, b, x):
    node_count = 1
    result = 1000000000
    last_value = 0
    if a > b:
        raise NotImplementedError(f"a must be smaller then b")
    if f == 2 and x == 0:
        return math.nan
    while abs(result - last_value) > 0.01:
        node_count += 1
        nodes = []
        for i in range(1, node_count + 1):
            node = (a + b) / 2 + ((b - a) / 2) * math.cos(math.pi * (2 * i - 1) / 2 / node_count) # формула узла Чебышёва
            nodes.append(node)
        func_value_in_x = newton_polinom(x, nodes, FunctionSet.get_function(f))
        last_value = result
        result = func_value_in_x
        if math.isnan(result) or math.isinf(result):
            return math.nan
    return result
