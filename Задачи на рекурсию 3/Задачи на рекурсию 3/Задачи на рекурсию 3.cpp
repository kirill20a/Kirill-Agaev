#include <iostream>
using namespace std;

bool equal(int N, int S) {

    if (N == 0) {
        return S == 0;
    }
    int last_digit = N % 10;
    return equal(N / 10, S - last_digit);
}
int main() {
    setlocale(LC_ALL, "Russian");
    int N, S;
    cout << "Введите неотрицательные целые числа " << endl;
    cin >> N >> S;

    if (equal(N, S)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}