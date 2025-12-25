#include<iostream>
#include<fstream>
#include<cmath>
#include<clocale>
using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    if (n % 3 == 0) return n == 3;

    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream file("e2mil.txt");
    char ch;
    bool afterDot = false;
    bool FNumber = false;
    int digitCount = 0;
    const int Chisl_SIZE = 10;
    int digits[Chisl_SIZE] = { 0 };
    int pos = 0;
    bool ChisloFilled = false;
    long long tenDigits = 0;

    while (file.get(ch)) {
        if (ch == '.') {
            afterDot = true;
            FNumber = true;
            continue;
        }
        if (!afterDot) {
            continue;
        }
        if (isdigit(ch)) {
            int digit = ch - '0';
            digits[pos] = digit;
            pos = (pos + 1) % Chisl_SIZE;
            if (!ChisloFilled && digitCount >= Chisl_SIZE - 1) {
                ChisloFilled = true;
            }

            digitCount++;
            if (ChisloFilled) {
                tenDigits = 0;
                for (int i = 0; i < Chisl_SIZE; i++) {
                    int idx = (pos + i) % Chisl_SIZE;
                    tenDigits = tenDigits * 10 + digits[idx];
                }
                if (isPrime(tenDigits)) {
                    cout << "Первое десятизначное простое число: " << tenDigits << endl;
                    file.close();
                    return 0;
                }
            }
        }
    }
        return 0;
}