#include <iostream>

int main() {
    int count = 0;
    std::cin >> count;
    int number[count];//считываем количество цветов
    for (int i = 0; i < count; i++) {
        std::cin >> number[i]; //считываем каждый цветок
    }
    int maxLength = 1; // максимальная допустимая длина для трех цветков
    int start = 0; //начало
    int length = 1; // текущая длина
    int end = 1; //конец
    int maxCurLen = 2; //максимальная длина из списка
    int minNumber = 0; //начало текущего участка
    for (int i = 1; i < count; i++) {
        if (number[i - 1] == number[i]) {
            maxLength += 1;
        }
        if (maxLength == 3) {
            if (length > maxCurLen) {
                maxCurLen = length;
                start = minNumber;
                end = i - 1;
            }
            maxLength = 2;
            length = 2;
            minNumber = i - 1;
        } else if (number[i - 1] != number[i]) {
            maxLength = 1;
            length++;
        } else {
            length++;
        }
        if (i == count - 1 and length > maxCurLen) {
            start = minNumber;
            end = count - 1;
            length++;

        }
    }
    if (count == 1) {
        start = end = 0;
    }
    if (count == 0) {
        start = end = -1;
    }

    std::cout << start + 1 << " " << end + 1;

    return 0;


}
