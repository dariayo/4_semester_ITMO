#include <iostream>
#include <map>
#include <list>
#include <vector>

int main() {
    int n, k, p;
    std::cin >> n >> k >> p;
    int cars[p];
    std::map<int, int> floor;
    std::vector<std::list<int>> last(n + 1);
    int result = 0;
    for (int i = 0; i < p; i++) {
        std::cin >> cars[i];
        last[cars[i]].push_front(i);
    }
    for (int i = 0; i < p; i++) {
        int car = cars[i];
        if (floor.find(last[car].back()) == floor.end()) {
            if (static_cast<int>(floor.size()) != k) {
                result++;
            } else {
                auto iterator = floor.end();
                iterator--;
                floor.erase(iterator);
                result++;
            }
        } else {
            auto delete_car = floor.find(last[car].back());
            floor.erase(delete_car);
        }
        if (last[car].size() != 1) {
            last[car].pop_back();
            floor[last[car].back()] = car;
        } else {
            last[car].pop_back();
        }
    }
    std::cout << result;

    return 0;
}
