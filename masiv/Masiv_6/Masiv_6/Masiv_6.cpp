#include <iostream>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int* A = new int[n];

    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }




    int R_L = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] != 0) {
            A[R_L] = A[i];
            R_L++;
        }
    }


    for (int i = R_L; i < n; i++) {
        A[i] = 0;
    }

    cout << "Результат: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    delete[] A;
    return 0;
}