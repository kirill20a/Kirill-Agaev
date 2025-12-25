
#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int h, m, s;

    cout << "Введите время (часы минуты секунды): ";
    cin >> h >> m >> s;

    int minn = m;
    if (s >= 30) {
        minn++;
    }
    if (minn == 60) {
        minn = 0;
        h++;
    }

    int hours = h;
    if (m >= 30 || (m == 29 && s >= 30)) {
        hours++;
    }
    if (hours == 24) {
        hours = 0;
    }

    cout << "\nИсходное время: " << h << "ч " << m << "мин " << s << "с" << endl;
    cout << "Округлено до минут: " << h << "ч " << minn << "мин" << endl;
    cout << "Округлено до часов: " << hours << "ч" << endl;

    return 0;
}