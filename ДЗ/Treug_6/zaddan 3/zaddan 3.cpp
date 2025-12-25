#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int kr_in_treug(double a, double r) {
    
    double h = a * sqrt(3) / 2;
    
    double S_treug = (a * a * sqrt(3)) / 4;
    
    double S_krug = 3.14 * r * r;
    
    double delen = S_treug / S_krug;
    return max(1, (int)delen);
}

int main() {
    double a, r;
    cout << "Vvedite Dlin and Rad ";
    cin >> a >> r;

    int result = kr_in_treug(a, r);
    cout << "Storon " << a
        << " kolvo " << result
        << " Rad " << r << endl;

    return 0;
}