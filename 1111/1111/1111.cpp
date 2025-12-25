#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b;

    cout << "Введите a и b для эллипса x²/a² + y²/b² < 1: ";
    cin >> a >> b;

    // Корректная инициализация границ
    int max_x = (int)a;
    int max_y = (int)b;

    cout << "\nЭллипс и точки (масштабированно):\n";

    // Рисуем ASCII-графику
    for (int y = max_y; y >= -max_y; y--) {
        for (int x = -max_x; x <= max_x; x++) {
            double value = (x * x) / (a * a) + (y * y) / (b * b);

            if (abs(value - 1.0) < 0.3) {
                cout << "*"; // Граница эллипса
            }
            else if (value < 1.0) {
                // Проверяем целочисленные координаты
                bool is_integer_point = false;
                for (int ix = -max_x; ix <= max_x; ix++) {
                    for (int iy = -max_y; iy <= max_y; iy++) {
                        if (ix == x && iy == y &&
                            (ix * ix) / (a * a) + (iy * iy) / (b * b) < 1.0) {
                            is_integer_point = true;
                            break;
                        }
                    }
                    if (is_integer_point) break;
                }

                if (is_integer_point) {
                    cout << "○"; // Целочисленная точка
                }
                else {
                    cout << "."; // Внутренняя область
                }
            }
            else {
                cout << " "; // Внешняя область
            }
        }
        cout << endl;
    }

    // Вывод найденных точек
    cout << "\nЦелочисленные точки внутри эллипса:\n";
    int count = 0;
    for (int x = -max_x; x <= max_x; x++) {
        for (int y = -max_y; y <= max_y; y++) {
            if ((x * x) / (a * a) + (y * y) / (b * b) < 1.0) {
                cout << "(" << x << "," << y << ") ";
                count++;
            }
        }
    }
    cout << "\nВсего: " << count << " точек\n";

    return 0;
}