#include <iostream>
#include<string>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    double k, p, godov; 

    cout << "Размер кред. (руб.): ";
    cin >> k;

    cout << "Процент годовых (%): ";
    cin >> p;

    cout << "Годовая прибыль (руб.): ";
    cin >> godov;

    double dt = k;
    int years = 0;
    int max_years = 100;

    cout << "Кредит: " << k << " руб." << endl;
    cout << "Процент: " << p << "% годовых" << endl;
    cout << "Прибыль: " << godov << " руб. в год" << endl;
    cout << "----------------" << endl;
    while (dt > 0 && years < max_years) {
        years++;
        dt = dt * (1 + p / 100); 
        dt = dt - godov;           

        if (dt <= 0) {
            cout << "Сможет погасить через " << years << " лет." << endl;
            return 0;
        }
    }
    cout << "Не сможет погасить кредит." << endl;
    cout << "Остаток долга: " << dt << " руб." << endl;
    return 0;
}