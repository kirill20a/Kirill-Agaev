#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale>

using namespace std;

const double PI = 3.14159265358979323846;

int main() {
    setlocale(LC_ALL, "Russian");
    double radians;

    cout << "Введите угол в радианах: ";
    cin >> radians;

    double dec_grad = radians * 180.0 / PI;

    int sign = (dec_grad >= 0) ? 1 : -1;
    dec_grad = abs(dec_grad);

    int grad = static_cast<int>(dec_grad);

    double dec_min = (dec_grad - grad) * 60.0;
    int minn = static_cast<int>(dec_min);

    double dec_sec = (dec_min - minn) * 60.0;
    int sec = static_cast<int>(round(dec_sec));

    minn += sec / 60;
    sec %= 60;

    grad += minn / 60;
    minn %= 60;

    grad *= sign;

    cout << "\nРезультат:" << endl;
    cout << fixed << setprecision(10);
    cout << "В радианах: " << radians << endl;
    cout << "В градусах: " << grad << "° " << minn << "' " << sec << "\"" << endl;

    return 0;
}