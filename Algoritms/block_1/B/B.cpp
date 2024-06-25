#include <iostream>
#include <stack>

int main() {
    std::string str;
    std::cin >> str;

    std::stack<std::pair<char, int>> stack;
    int small = 0;
    int big = 0;
    int array[str.length() / 2];
    for (char current: str) {
        if (!stack.empty() and isupper(current) and islower(stack.top().first) and
            tolower(current) == stack.top().first) {
            array[big] = stack.top().second + 1;
            big += 1;
        } else if (!stack.empty() and isupper(stack.top().first) and islower(current) and
                   current == tolower(stack.top().first)) {
            array[stack.top().second] = small + 1;
            small += 1;
        } else if (stack.empty() or tolower(current) != tolower(stack.top().first) ||
                   ((islower(stack.top().first) and islower(current)) ||
                    isupper(stack.top().first) and isupper(current))) {
            if (isupper(current)) {
                stack.emplace(current, big);
                big += 1;
            } else {
                stack.emplace(current, small);
                small += 1;
            }
            continue;
        }
        stack.pop();
    }
    if (stack.empty()) {
        std::cout << "Possible" << std::endl;
        for (int i = 0; i < str.length() / 2; i++) {
            std::cout << array[i] << " ";
        }
    } else {
        std::cout << "Impossible" << std::endl;
    }
    return 0;
}
