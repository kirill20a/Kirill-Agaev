#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

int main(void) {
    setlocale(LC_ALL, "Russian");

    double x, m;
    cout << "Введите x и m for (1+x)**m: ";
    cin >> x >> m;

    if (cin) {
        double in = 1.0;
        double out = in;

        for (int i = 0; i < m; i++) {
            in *= (m - i) / (i + 1) * x;
            out += in;
        }

        cout << "Результат: " << out;
    }
    else cout << "x и m долны быть числа (m >= 0)";

    return 0;
}