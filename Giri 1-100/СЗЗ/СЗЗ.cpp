#include<iostream>
#include<clocale>
#include <cmath>
#include <fstream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int Mas_giri[] = { 100, 50, 20, 10, 5, 2, 1 };
    int numWeights = 7;

    int Massa;
    cout << "Введите массу тела в граммах(p.s. Просто введите 1): ";
    cin >> Massa;

    int L_Side[] = { 0, 0, 0, 0, 0, 0, 0 };
    int R_Side[] = { 0, 0, 0, 0, 0, 0, 0 };
    int us_Count = 0;

    int VV = Massa;


    for (int i = 0; i < sizeof(Mas_giri) / sizeof(Mas_giri[0]); i++) {
        if (Massa == 0) break;


        if (Massa == Mas_giri[i]) {
            R_Side[i] = 1;
            Massa -= Mas_giri[i];
            us_Count++;
        }

        else if (abs(Massa - Mas_giri[i]) < abs(Massa)) {
            R_Side[i] = 1;
            Massa -= Mas_giri[i];
            us_Count++;
        }
        else if (abs(Massa + Mas_giri[i]) < abs(Massa)) {
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


    cout << "\nСоздание файла с результатами для масс 1-100г..." << endl;

    ofstream file("результаты_гири.txt");
    if (!file) {
        cout << "Ошибка создания файла!" << endl;
        return 1;
    }

    file << "Результаты уравновешивания для масс от 1 до 100 грамм\n";
    file << "Гири: 100, 50, 20, 10, 5, 2, 1 (по одной каждого номинала)\n";
    file << "==================================================\n\n";

    for (int currentMass = 1; currentMass <= 100; currentMass++) {
        int tempL[7] = { 0 };
        int tempR[7] = { 0 };
        int tempCount = 0;
        int tempMassa = currentMass;


        for (int i = 0; i < 7; i++) {
            if (tempMassa == 0) break;

            if (tempMassa == Mas_giri[i]) {
                tempR[i] = 1;
                tempMassa -= Mas_giri[i];
                tempCount++;
            }
            else if (abs(tempMassa - Mas_giri[i]) < abs(tempMassa)) {
                tempR[i] = 1;
                tempMassa -= Mas_giri[i];
                tempCount++;
            }
            else if (abs(tempMassa + Mas_giri[i]) < abs(tempMassa)) {
                tempL[i] = 1;
                tempMassa += Mas_giri[i];
                tempCount++;
            }
        }


        file << currentMass << "г: " << currentMass;

        for (int i = 0; i < 7; i++) {
            if (tempL[i] == 1) {
                file << "+" << Mas_giri[i];
            }
        }

        file << "=";

        bool hasRight = false;
        for (int i = 0; i < 7; i++) {
            if (tempR[i] == 1) {
                if (hasRight) file << "+";
                file << Mas_giri[i];
                hasRight = true;
            }
        }
        if (!hasRight) file << "0";

        file << " (гирь: " << tempCount << ")\n";
    }

    file.close();
    cout << "Файл 'результаты_гири.txt' успешно создан!" << endl;

    return 0;
}