#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double a, b;
    cout << "Enter a, b for function of Elipse: ";
    cin >> a >> b;

    if (a != 0 && b != 0 && cin && a < 100 && b < 100) {
        for (double y = b; y >= -b; --y) {
            for (double x = -a; x <= a; ++x) {
                if (x * x / a / a + y * y / b / b <= 1.0) {
                    cout << setfill(' ') << "(" << setw(3) << x << "," << setw(3) << y << ")";
                }
                else {
                    cout << "         ";
                }
            }
            cout << endl;
        }
    }
    else {
        cout << "a and b must be numbers that greater than 0 and smaller than 100 ";
    }
    return 0;
}
