#include <iostream>
#include <clocale>
using namespace std;

int* createFIB() {
    const int SIZE = 1000;
    int* fib = new int[SIZE];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < SIZE; i++) {

        if (fib[i - 1] > ((1 << 31)- 1)- fib[i - 2]) {
            cout << "Переполнение на шаге " << i << "!" << endl;
            return fib;
        }
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int* fibonacciArray = createFIB();


    cout << "Числа Фибоначчи (до переполнения):" << endl;
    for (int i = 0; i < 1000; i++) {

        if (i > 1 && fibonacciArray[i] < 0) {
            break;
        }
        cout << "F(" << i << ") = " << fibonacciArray[i] << endl;
    }

    delete[] fibonacciArray;
    return 0;
}