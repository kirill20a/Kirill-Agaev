#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int* m;
    int n;
    int temp;

    cin >> n;
    m = new int[n + 1](); // Инициализация нулями

    // Ввод с проверкой
    for (int i = 0; i < n; i++) {
        cin >> temp;
        while (temp != 0 && temp != 1) {
            cout << "Ошибка! Введите 0 или 1: ";
            cin >> temp;
        }
        m[i] = temp;
    }

    int carry = 1;
    for (int i = n - 1; i >= 0; i--) {
        int sum = m[i] + carry;
        m[i] = sum % 2;
        carry = sum / 2;
        if (carry == 0) break;
    }

    if (carry > 0) {
        m[n] = 1;
    }

    bool foundFirstOne = false;
    for (int i = 0; i < n + 1; i++) {
        if (!foundFirstOne && m[i] == 1) {
            foundFirstOne = true;
        }
        if (foundFirstOne) {
            cout << m[i];
        }
    }

    if (!foundFirstOne) {
        cout << "0";
    }
    cout << "__Последний ноль не учитываем";
    cout << endl;

    delete[] m;
    return 0;
}