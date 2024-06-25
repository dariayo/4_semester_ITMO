#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <string>
#include <algorithm>

struct Cell {
    int x, y, dist;

    Cell(int x, int y, int dist = 0) : x(x), y(y), dist(dist) {}
};

struct CompareDist {
    bool operator()(const Cell &a, const Cell &b) {
        return a.dist > b.dist;
    }
};

bool isValid(int x, int y, int N, int M) {
    return (x >= 0 && x < N && y >= 0 && y < M);
}

void
processCell(std::priority_queue<Cell, std::vector<Cell>, CompareDist> &queue, std::vector<std::vector<int>> &distance,
            std::vector<std::string> &lines, int n, int m) {
    auto cell = queue.top();
    queue.pop();

    std::vector<int> dx = {-1, 0, 1, 0};
    std::vector<int> dy = {0, 1, 0, -1};

    for (int i = 0; i < 4; ++i) {
        int new_x = cell.x + dx[i];
        int new_y = cell.y + dy[i];
        if (isValid(new_x, new_y, n, m) && lines[new_x][new_y] != '#') {
            int new_distance = cell.dist + (lines[new_x][new_y] == '.' ? 1 : 2);
            if (new_distance < distance[new_x][new_y]) {
                distance[new_x][new_y] = new_distance;
                queue.emplace(new_x, new_y, new_distance);
            }
        }
    }
}

std::string findPath(std::vector<std::vector<int>> &distance, std::vector<std::string> &lines, int x_start, int y_start,
                     int x_finish, int y_finish, int n, int m) {
    std::string result;
    int x = x_finish, y = y_finish;
    std::vector<int> dx = {-1, 0, 1, 0};
    std::vector<int> dy = {0, 1, 0, -1};
    std::string direction = "NESW";

    while (x != x_start || y != y_start) {
        for (int i = 0; i < 4; i++) {
            int previous_x = x - dx[i];
            int previous_y = y - dy[i];
            if (isValid(previous_x, previous_y, n, m) &&
                distance[previous_x][previous_y] + (lines[x][y] == '.' ? 1 : 2) == distance[x][y]) {
                result += direction[i];
                x = previous_x;
                y = previous_y;
                break;
            }
        }
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    int n, m, x_start, y_start, x_finish, y_finish;
    std::cin >> n >> m >> x_start >> y_start >> x_finish >> y_finish;
    --x_start;
    --y_start;
    --x_finish;
    --y_finish;

    std::vector<std::string> lines(n);
    for (int i = 0; i < n; i++) {
        std::cin >> lines[i];
    }

    std::vector<std::vector<int>> distance(n, std::vector<int>(m, INT_MAX));
    distance[x_start][y_start] = 0;

    std::priority_queue<Cell, std::vector<Cell>, CompareDist> queue;
    queue.emplace(x_start, y_start);

    while (!queue.empty()) {
        processCell(queue, distance, lines, n, m);
    }

    if (distance[x_finish][y_finish] == INT_MAX) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << distance[x_finish][y_finish] << std::endl;
        std::string result = findPath(distance, lines, x_start, y_start, x_finish, y_finish, n, m);
        std::cout << result << std::endl;
    }

    return 0;
}
