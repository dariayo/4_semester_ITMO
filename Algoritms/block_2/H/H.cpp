#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int count, element = 0;
    std::cin >> count >> element;
    std::vector<int> numbers;
    int num;
    for (int i = 0; i < count; i++) {
        std::cin >> num;
        numbers.push_back(num);
    }
    std::sort(numbers.begin(), numbers.end(), std::greater<>());
    int i = 1;
    int s = 1;
    int result = 0;
    while (i <= numbers.size()) {
        if (i == s * element) {
            numbers[i - 1] = 0;
            s++;
        }
        result += numbers[i - 1];
        i++;
    }
    std::cout << result;
    return 0;
}
