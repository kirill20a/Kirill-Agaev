#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale>


using namespace std;

const double PI = 3.14159265358979323846;

int main() {
    setlocale(LC_ALL, "Russian");
    int grad, minn, sec;

    cout << "Введите угол в формате градусы минуты секунды: ";
    cin >> grad >> minn >> sec;

    // Определяем знак угла (1 для положительного, -1 для отрицательного)
    int sign = 1 - 2 * ((grad < 0) || (minn < 0) || (sec < 0));


    int abs_grad = abs(grad);
    int abs_minn = abs(minn);
    int abs_sec = abs(sec);

    // Переводим в десятичные градусы
    double decimal_grad = abs_grad + abs_minn / 60.0 + abs_sec / 3600.0;

    // Учитываем знак
    decimal_grad *= sign;

    // Переводим градусы в радианы
    double rad = decimal_grad * PI / 180.0;

    // Выводим результат
    cout << fixed << setprecision(10);
    cout << "\nРезультат:" << endl;
    cout << "Угол: " << grad << "° " << minn << "' " << sec << "\"" << endl;
    cout << "В радианах: " << rad << endl;

    return 0;
}