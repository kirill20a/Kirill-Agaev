#include <iostream>
using namespace std;

int divs(int N, int divisor = 2) {
   
    if (divisor >= N) {
        return 0;
    }

    if (N % divisor == 0) {
        return 1 + divs(N, divisor + 1);
    }
    else {
        return divs(N, divisor + 1);
    }
}

int main() {
    int N;
    cin >> N;
    cout << divs(N) << endl;
    return 0;
}