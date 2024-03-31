class Solution:
    errorMessage = "The system has no roots of equations or has an infinite set of them."
    isSolutionExists = True

    @staticmethod
    def solveByGauss(n, matrix):
        coefficientB = [0] * n
        result = [0] * n
        matrixColumns = n + 1
        initialMatrix = [row[:] for row in matrix]
        for i in range(n):
            if len(matrix[i]) != n + 1:
                Solution.isSolutionExists = False
                return []
        for i in range(n):
            coefficientB[i] = matrix[i][n]
        for i in range(n):
            if matrix[i][i] == 0:
                Solution.isSolutionExists = False
                return
            firstRowElement = matrix[i][i]
            for j in range(matrixColumns):
                matrix[i][j] /= firstRowElement
            for j in range(i + 1, n):
                firstInThisRow = matrix[j][i]
                firstElement = matrix[i][i]
                previousRow = i
                for k in range(matrixColumns):
                    matrix[j][k] -= matrix[previousRow][k] * firstInThisRow / firstElement
        for i in range(n - 1, -1, -1):
            result[i] = matrix[i][n]
            for j in range(i + 1, n):
                result[i] -= result[j] * matrix[i][j]
        for i in range(n):
            sumLeft = 0
            for j in range(n):
                sumLeft += initialMatrix[i][j] * result[j]
            result.append(coefficientB[i] - sumLeft)

        return result


if __name__ == '__main__':
    n = int(input().strip())

    matrix_rows = n
    matrix_columns = n + 1

    matrix = []

    for _ in range(matrix_rows):
        matrix.append(list(map(float, input().rstrip().split())))

    result = Solution.solveByGauss(n, matrix)
    if Solution.isSolutionExists:
        print('\n'.join(map(str, result)))
    else:
        print(f"{Solution.errorMessage}")
