#include <iostream>
#include <vector>

void dfs_method(int i, std::vector<int> &vis, std::vector<std::vector<int>> &lines) {
    for (int j = 0; j < lines[i].size(); j++) {
        int s = lines[i][j];
        if (!vis[s]) {
			vis[s] = true;
            dfs_method(s, vis, lines);
        }
    }
}

int main() {
    int line;
    int n;
    std::cin >> n;
    std::vector<int> vis(n + 1, false);
    std::vector<std::vector<int>> lines(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> line;
        lines[i].push_back(line);
        lines[line].push_back(i);
    }
    int result = 0;
    for (int i = 0; i <= n; i++) {
        if (!vis[i]) {
            result++;
            dfs_method(i, vis, lines);
        }
    }
    std::cout << result - 1;


    return 0;
}
