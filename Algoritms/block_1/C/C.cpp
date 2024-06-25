#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <regex>
#include <unordered_map>

bool isNumber(const std::string &str) {
    for (char ch: str) {
        if (std::isdigit(ch)) {
            return true;
        }
    }
    return false;
}

int main() {
    std::vector<std::string> lines;
    std::string line;
    std::smatch match;
    std::map<std::string, std::vector<int>> mapOld;

    std::regex pattern2("(.+?)=");
    std::vector<std::string> keys;

    // Считываем строки с ввода
    while (std::getline(std::cin, line)) {
        if (line == "\0") {
            break;
        }
        lines.push_back(line);
    }
    int countBlocks = 0;
    int countCloseBlocks = 0;
    std::string before;
    std::string after;
    std::vector<std::string> arr;
    std::unordered_map<int, std::vector<std::string>> newArr;
    for (const auto &str: lines) {
        if (str == "{") { //если встретили {
            countBlocks++;
        } else if (str == "}") {
            for (const std::string &key: newArr[countBlocks]) {
                keys.push_back(key);

            }

            for (const std::string &key: keys) {
                if (!mapOld[key].empty()) {
                    mapOld[key].pop_back();
                } else {
                    mapOld[key].push_back(0);
                }
            }
            newArr.erase(countBlocks);
            keys.clear();
            countCloseBlocks -= 1;
            countBlocks -= 1;
        } else {
            std::regex_search(str, match, pattern2);
            before = match.str(1); // символ до равно
            before.erase(remove_if(before.begin(), before.end(), ::isspace), before.end());
            size_t found = str.find("=");
            if (found != std::string::npos) { // символ после равно
                after = str.substr(found + 1);
                after.erase(remove_if(after.begin(), after.end(), ::isspace), after.end());
                if (isNumber(after)) { // если после равно стоит число
                    if (countBlocks == 0) { // если количество { равно 0 то записываем просто
                        int a = std::stoi(after);
                        mapOld[before].push_back(a);
                    } else {
//                        keys.push_back(before);
                        int a = std::stoi(after);
                        mapOld[before].push_back(a);
                    }
                } else { // если числа нет после равно
                    if (mapOld.count(after) > 0) { // если значение уже есть
                        int a = mapOld[after].back();
                        mapOld[before].push_back(a);
                        std::cout << mapOld[after].back();
                        std::cout << std::endl;
                    } else { // если значения нет
                        mapOld[before].push_back(0);
                        std::cout << "0";
                        std::cout << std::endl;
                    }

                }
            }
            if (countBlocks > 0) {
                newArr[countBlocks].push_back(before);
            }
        }


    }

    return 0;


}
