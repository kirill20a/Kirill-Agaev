#include <iostream>
#include <iomanip>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    double a, b;
    cout << "Введите а и б для создания Эллипса: ";
    cin >> a >> b;

    if (a != 0 && b != 0 && cin && a < 100 && b < 100) {
        for (double y = b; y >= -b; --y) {
            for (double x = -a; x <= a; ++x) {
                if (x * x / a / a + y * y / b / b <= 1.0) {
                    cout << setfill(' ') << "(" << setw(3) << x << "," << setw(3) << y << ")";
                }
                else {
                    cout << "         ";
                }
            }
            cout << endl;
        }
    }
    else {
        cout << "a и b должны быть числа больше 0 и меньше 100 ";
    }
    return 0;
}
