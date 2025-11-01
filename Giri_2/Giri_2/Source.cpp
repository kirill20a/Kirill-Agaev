#include<iostream>
#include<clocale>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int Mas_giri[] = { 100, 50, 20, 10, 5, 2, 1 };
    int numWeights = 7;

    int Massa;
    cout << "Введите массу тела в граммах: ";
    cin >> Massa;


    int L_Side[] = { 0, 0, 0, 0, 0, 0, 0 };
    int R_Side[] = { 0, 0, 0, 0, 0, 0, 0 };
    int us_Count = 0;

    int VV = Massa;

    for (int i = 0; i < sizeof(Mas_giri) / sizeof(Mas_giri[0]); i++) {
        if (Massa == 0) break;


        if (abs(Massa - Mas_giri[i]) <= abs(Massa)) {
            R_Side[i] = 1;
            Massa -= Mas_giri[i];
            us_Count++;
        }

        else if (abs(Massa + Mas_giri[i]) <= abs(Massa)) {
            L_Side[i] = 1;
            Massa += Mas_giri[i];
            us_Count++;
        }
    }
    cout << "Уравновешивание: ";


    cout << VV;
    for (int i = 0; i < sizeof(Mas_giri) / sizeof(Mas_giri[0]); i++) {
        if (L_Side[i] == 1) {
            cout << " + " << Mas_giri[i];
        }
    }

    cout << " = ";

    bool first = true;
    for (int i = 0; i < sizeof(Mas_giri) / sizeof(Mas_giri[0]); i++) {
        if (R_Side[i] == 1) {
            if (!first) cout << " + ";
            cout << Mas_giri[i];
            first = false;
        }
    }

    if (first) cout << "0";

    cout << endl;



    cout << "\n\nВсего использовано гирь: " << us_Count << endl;

    return 0;
}