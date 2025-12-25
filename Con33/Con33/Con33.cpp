#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void calculateInvestment() {
    double k, p, s;

    cout << "Стартовый капитал (руб.): ";
    cin >> k;

    cout << "Ежемесячный процент роста: ";
    cin >> p;

    cout << "Целевая сумма (руб.): ";
    cin >> s;

    double Kof = 1 + p / 100;
    double months = log(s / k) / log(Kof);
    double years = months / 12;

    
    cout << "Потребуется: " << years << " лет" << endl;
}

int main() {
    calculateInvestment();
    return 0;
}