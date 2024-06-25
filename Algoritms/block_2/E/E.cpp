#include <iostream>

int main() {
    int count, count_cows = 0;
    std::cin >> count >> count_cows;
    int numbers[count];
    int num;
    for (int i = 0; i < count; i++) {
        std::cin >> num;
        numbers[i] = num;
    }
    int left = 0;
    int right = numbers[count - 1] + 1;
    int distance;
    while (right - left > 1) {
        int counter = 1;
        distance = (right + left) / 2;
        int prev_left = left;
        left = numbers[0];
        for (int i = 0; i < count; i++) {
            if (numbers[i] - left >= distance) {
                counter++;
                left = numbers[i];
            }
        }
        if (counter >= count_cows) {
            left = distance;
        } else {
            left = prev_left;
            right = distance;
        }
    }
    std::cout << left;
    return 0;


}
