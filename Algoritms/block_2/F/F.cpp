#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

bool max(std::basic_string<char> x, std::basic_string<char> y) {
    if (x[0] == y[0]) {
        return x + y > y + x;
    }
    return x[0] > y[0];
}

int main() {

    std::vector<std::string> numbers;
    std::string number;

    while (std::cin >> number) {
        numbers.push_back(number);
    }

    std::sort(numbers.begin(), numbers.end(), max);

    for (const std::basic_string<char> &num: numbers) {
        std::cout << num;
    }

    return 0;
}
