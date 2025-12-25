#include <iostream>
#include <cmath>
#include <numbers>
using namespace std;

double dmsToRadians(int degrees, int minutes = 0, int seconds = 0) {
    double totalDegrees = abs(degrees) + minutes / 60.0 + seconds / 3600.0;
    if (degrees < 0) totalDegrees = -totalDegrees;
    return totalDegrees * numbers::pi / 180;
}

int main() {
    cout.precision(12);

    cout << "45°30'15\" = " << dmsToRadians(45, 30, 15) << " rad" << endl;
    cout << "225°45'30\" = " << dmsToRadians(225, 45, 30) << " rad" << endl;
    cout << "-120°15'45\" = " << dmsToRadians(-120, 15, 45) << " rad" << endl;

    return 0;
}