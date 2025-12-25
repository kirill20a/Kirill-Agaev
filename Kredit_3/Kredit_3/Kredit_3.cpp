#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    double k, p, s;

    cout << "Введите стартовый капитал (k рублей): ";
    cin >> k;

    cout << "Введите ежемесячный процент роста (p%): ";
    cin >> p;

    cout << "Введите целевую сумму (s рублей): ";
    cin >> s;

    double months = log(s / k) / log(1 + p / 100);

    double years = months / 12;

    int full_years = static_cast<int>(years);
    int remaining_months = static_cast<int>(ceil(months - full_years * 12));

    cout << fixed << setprecision(2);
    cout << "\nРезультат:" << endl;
    cout << "Стартовый капитал: " << k << " руб." << endl;
    cout << "Ежемесячный рост: " << p << "%" << endl;
    cout << "Целевая сумма: " << s << " руб." << endl;
    cout << "Потребуется времени: " << full_years << " лет и " << remaining_months << " месяцев" << endl;

    return 0;
}