#include <iostream>

int main() {
    int a, b, c, d, k;
    std::cin >> a >> b >> c >> d >> k;
    for (int i = 0; i < k; i++) {
        if (a * b <= c) {
            a = 0;
            break;
        }
        if (a * b - c == a) {
            break;
        }
        a = a * b - c;
        if (a >= d) {
            a = d;
            break;
        }
    }
    std::cout << a;
    return 0;
}
