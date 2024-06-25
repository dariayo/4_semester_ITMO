#include <iostream>
#include <string>
#include <deque>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::deque<std::string> numbers;
    std::vector<std::string> data;
    std::string s;
    for (int i = 0; i < n; ++i) {
        std::cin >> s;
        if (s == "+") {
            std::cin >> s;
            numbers.push_back(s);
        } else if (s == "*") {
            std::cin >> s;
            int middle = numbers.size() / 2;
            if (numbers.size() % 2 == 1) {
                middle += 1;
            }
            numbers.insert(numbers.begin() + middle, s);
        } else {
            if (!numbers.empty()) {
                data.push_back(numbers.front());
                numbers.pop_front();
            }
        }
    }
    for (const auto &i: data) {
        std::cout << i << std::endl;
    }
    
    return 0;
}
