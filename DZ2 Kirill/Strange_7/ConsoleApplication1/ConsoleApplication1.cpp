#include <iostream>
#include <cmath>
#include <iomanip>
#include  <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    double ep;

    cout << "Введите значение погрешности epsilon: ";
    cin >> ep;
    double x = 1.0;
    int iteration = 1;
    cout << "\nПроверка первого замечательного предела:" << endl;
    cout << "lim(sin(x)/x) = 1 при x->0" << endl;
    cout << "Заданная погрешность: " << ep << endl << endl;
    cout << fixed << setprecision(8);
    cout << "№\tx\t\tsin(x)/x\t\t|sin(x)/x - 1|" << endl;
    cout << "--------------------------------------------------------" << endl;
    while (true) {
        double r = sin(x) / x;
        double diff = fabs(r - 1.0);
        cout << iteration << "\t" << x << "\t" << r << "\t" << diff << endl;
        if (diff < ep) {
            cout << "При x = " << x << " разность составляет " << diff << endl;
            break;
        }
        x = x / 2.0;
        iteration++;
        if (x < 1e-15 || iteration > 100) {
            cout << "\nДостигнут предел точности вычислений" << endl;
            break;
        }
    }
    return 0;
}