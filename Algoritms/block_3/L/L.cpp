#include <iostream>
#include <deque>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    int number;
    std::deque<int> numbers;
    for (int i = 0; i < n; i++) {
        std::cin >> number;
        numbers.push_back(number);
    }
    int min = *std::min_element(numbers.begin(), numbers.begin() + k);
    std::cout << min << " ";

    for (int i = 1; i < n - k + 1; i++) {
        if (numbers[i - 1] != min) {
            min = std::min(min, numbers[i + k - 1]);
        } else {
            min = *std::min_element(numbers.begin() + i, numbers.begin() + i + k);
        }
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout << min << " ";
    }
    return 0;
}
