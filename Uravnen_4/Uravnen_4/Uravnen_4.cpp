#include <iostream>
#include <iomanip>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    double a, b, c;

    cout << "Введите коэффициенты параболы y = ax² + bx + c" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;


    double x0 = -b / (2 * a);
    double y0 = a * x0 * x0 + b * x0 + c;

    cout << fixed << setprecision(3);
    cout << "\nВершина параболы:" << endl;
    cout << "x₀ = " << x0 << endl;
    cout << "y₀ = " << y0 << endl;
    cout << "Координаты: (" << x0 << ", " << y0 << ")" << endl;

    return 0;
}