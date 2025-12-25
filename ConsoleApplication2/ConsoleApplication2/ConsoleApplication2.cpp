#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(void) {
    double e;
    cout << "Enter the permissible difference: ";
    cin >> e;

    if (cin && e < 1) {
        double res = 0;
        for (double x = 0.5; 1 - res >= e; x /= 2) {
            res = sin(x) / x;
            cout << fixed << "x: " << x << ", resualt: " << res << ", difference: " << 1 - res << endl;
        }
    }
    else cout << "Permissible difference must be a number that less than 1";
    return 0;
}