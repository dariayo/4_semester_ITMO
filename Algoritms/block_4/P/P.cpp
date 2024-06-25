#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    int result = 0;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));
    int val;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> val;
            graph[i][j] = val;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int new_val = std::max(graph[i][k], graph[k][j]);
                graph[i][j] = std::min(graph[i][j], new_val);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result = std::max(result, graph[i][j]);
        }
    }

    std::cout << result;

    return 0;
}
