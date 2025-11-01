#include <iostream>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Четырехзначные натуральные числа без повторяющихся цифр:" << endl;
    int K = 0;

    for (int n = 1000; n <= 9999; n++) {
        int digits[10] = { 0 }; 
        int temp = n;
        bool Duplik = false;


        while (temp > 0) {
            int digit = temp % 10;
            if (digits[digit] > 0) {
                Duplik = true;
                break;
            }
            digits[digit]++;
            temp /= 10;
        }

        if (!Duplik) {
            cout << n << " ";
            K++;

            if (K % 10 == 0) {
                cout << endl;
            }
        }
    }

    cout << endl << "Всего чисел: " << K << endl;
    return 0;
}