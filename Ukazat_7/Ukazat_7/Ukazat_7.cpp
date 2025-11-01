#include <iostream>
#include<clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const int n = 10;
    int K[n] = { 0 };

    cout << "Введите элементы массива через ПРОБЕЛЫ (10 чисел): ";
    for (int i = 0; i < n; i++) {
        cin >> K[i];
    }

    int newSize = 0;

    for (int i = 0; i < n; i++) {
        bool found = false;

        for (int j = 0; j < newSize; j++) {
            if (K[j] == K[i]) {
                found = true;
                break;
            }
        }

        if (!found) {
            K[newSize] = K[i];
            newSize++;
        }
    }

    cout << "Массив после удаления дубликатов: ";
    for (int i = 0; i < newSize; i++) {
        cout << K[i] << " ";
    }
    cout << endl;

    cout << "Уникальных элементов: " << newSize << endl;

    return 0;
}