#include <iostream>
#include<clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "=== Подсчет чисел с одинаковым количеством единиц в 2-й и 8-й системах ===" << endl;

    const int MAX_N = 10000000;
    int count = 0;

    // Массив для первых 20 примеров
    int Massiv[20];
    int Schet_massiv = 0;

    for (int i = 0; i <= MAX_N; i++) {
        int binaryOnes = 0;
        int octalOnes = 0;


        int temp = i;
        while (temp > 0) {
            binaryOnes += (temp & 1);
            temp >>= 1;
        }

        
        temp = i;
        while (temp > 0) {
            if (temp % 8 == 1) {
                octalOnes++;
            }
            temp /= 8;
        }


        if (binaryOnes == octalOnes) {
            count++;
            if (Schet_massiv < 20) {
                Massiv[Schet_massiv] = i;
                Schet_massiv++;
            }
        }
    }

    cout << "Результаты:" << endl;
    cout << "Количество чисел до " << MAX_N << " с одинаковым количеством единиц: " << count << endl;

    cout << "\nПервые 20 таких чисел:" << endl;
    for (int i = 0; i < Schet_massiv; i++) {
        cout << Massiv[i];
        if (i < Schet_massiv - 1) cout << ", ";
        if ((i + 1) % 5 == 0 && i < Schet_massiv - 1) cout << endl;
    }
    cout << endl;

    return 0;
}