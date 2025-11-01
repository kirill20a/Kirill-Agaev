#include<iostream>
#include<clocale>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
    int Massi_gir[] = { 100, 50, 20, 10, 5, 2, 1 };
    int counts[] = {0};


    int MASSA;
    cout << "Введите массу в граммах: ";
    cin >> MASSA;

    int Vivod = 0;

    for (int i = 0; i < sizeof(Massi_gir) / sizeof(Massi_gir[0]); i++) {
        counts[i] = MASSA / Massi_gir[i];
        MASSA %= Massi_gir[i];
        Vivod += counts[i];
    }

    for (int i = 0; i < sizeof(Massi_gir) / sizeof(Massi_gir[0]); i++) {
        if (counts[i] > 0) {
            cout << counts[i] << " x " << Massi_gir[i] << "г" << endl;
        }
    }
    cout << "Всего: " << Vivod << " гирь" << endl;

    return 0;
}