#include <iostream>
#include <map>
#include <algorithm>
#include <string.h>
#include <vector>

int main() {
    std::string str;
    std::cin >> str;
    std::string middle = str;
    int number[26];
    std::map<char, int> map;
    std::map<char, int> count;
    std::string firstPart;
    std::string back;
    std::string center;
    std::vector<char> vector;
    for (int &i: number) {
        std::cin >> i;
    }
    std::string letter;
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    for (int i = str.size() - 1; i >= 0; --i) {
        char *size = strchr(letters, str[i]);
        map[str[i]] = number[size - letters];
        count[str[i]]++;

    }
    std::sort(middle.begin(), middle.end(), [map, count](char &x, char &y) -> bool {
        if (count.at(x) > 1 && count.at(y) > 1) {
            return map.at(x) > map.at(y);
        } else if (count.at(x) == 1 && count.at(y) == 1) {
            return map.at(x) > map.at(y);
        } else {
            return count.at(x) > count.at(y);
        }
    });
    for (char &an: middle) {
        if (!std::count(vector.begin(), vector.end(), an)) {
            vector.push_back(an);
        }
    }
    for (char &i: vector) {
        if (count[i] > 1) {
            firstPart += i;
            count[i] -= 2;
        }
    }
    back = firstPart;
    reverse(back.begin(), back.end());

    for (char &i: vector) {
        for (int j = 0; j < count[i]; j++) {
            center += i;
        }
    }

    std::cout << firstPart << center << back << std::endl;
    return 0;


}
