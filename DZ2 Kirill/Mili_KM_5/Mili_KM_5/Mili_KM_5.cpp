#include <iostream>
#include <iomanip>
#include <clocale>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const double mils_km = 1.609344;
    const double km_mils = 1.0 / mils_km;

    double max_k;
    cout << "Введите максимальное расстояние в километрах (k): ";
    cin >> max_k;

    vector<pair<double, double>> table;

    table.push_back({ 1.0 * km_mils, 1.0 });
    table.push_back({ 1.0, 1.0 * mils_km });

    double km = 2.0;
    while (km <= max_k) {
        double miles = km * km_mils;
        table.push_back({ miles, km });
        km += 1.0;
    }

    double miles = 2.0;
    while (miles * mils_km <= max_k) {
        double km_value = miles * mils_km;
        table.push_back({ miles, km_value });
        miles += 1.0;
    }

    sort(table.begin(), table.end());

    cout << "\nмили\t\tкм" << endl;
    cout << fixed << setprecision(4);

    for (const auto& row : table) {
        if (row.second <= max_k) {
            cout << row.first << "\t\t" << row.second << endl;
        }
    }

    return 0;
}