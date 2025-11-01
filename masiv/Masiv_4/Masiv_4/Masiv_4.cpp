#include <iostream>

#include<clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    cout << "Введите числа";
    int* L = new int[n];
    for (int i = 0; i < n; i++) 
    {
        cin >> L[i];
    }
    int ML = 0;
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (L[i] == 0) {
            k++;
            if (k > ML) {
                ML = k;
            }
        }
        else {
            k = 0;
        }
    }
    cout << "Длина самой длинной последовательности нулей: " << ML << endl;
    return 0;
}