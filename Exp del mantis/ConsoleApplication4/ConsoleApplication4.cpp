#include <iostream>
#include <cstdint>
#include<clocale>
using namespace std;
using ulli = unsigned long long int;

int main() {
    setlocale(LC_ALL, "Russian");
    double d = 128.25; 
    ulli n = *(ulli*)&d;
    cout << hex << "n = " << n << endl;

    ulli m = n & 0xFFFFFFFFFFFFF;
    cout << hex << "m = " << m << endl;


    m |= 0x10000000000000;
    cout << hex << "m = " << m << endl;


    ulli e = ((n >> 52) & 0x7FF) - 1023;
    cout << dec << "e = " << e << endl;
    cout << hex << "e (hex) = " << e << endl;

    ulli one = 1;

    if (m != 0) {
        double result = static_cast<double>(e) / static_cast<double>(m);
        cout << dec << "e / m = " << result << endl;
    }
    else {
        cout << "Деление на ноль!" << endl;
    }

    return 0;
}