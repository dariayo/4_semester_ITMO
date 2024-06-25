#include <iostream>
#include <vector>
#include <unordered_map>

bool flag = true;

void dfs_method(int i, bool visit, std::unordered_map<int, bool> &groups, std::vector<std::vector<int>> &lines, std::vector<bool> &vis) {
    vis[i] = true;
    groups[i] = visit;
    for (int j = 0; j < lines[i].size(); j++) {
        int s = lines[i][j];
        if (!vis[s]) {
            dfs_method(s, !visit, groups, lines, vis);
        } else if (groups[s] == visit) {
            flag = false;
            std::cout << "NO" << std::endl;
            exit(0);
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    int left, right;
    std::vector<bool> vis(n+1);
    std::unordered_map<int, bool> groups;
    std::vector<std::vector<int>> lines(n+1);
    for (int i = 0; i < m; i++) {
        std::cin >> left >> right;
        lines[left].push_back(right);
        lines[right].push_back(left);
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs_method(i, true, groups, lines, vis);
        }
    }
    if (flag) {
        std::cout << "YES" << std::endl;
    }
    return 0;
}
