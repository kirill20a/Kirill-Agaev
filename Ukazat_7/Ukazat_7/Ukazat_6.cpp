#include <iostream>
#include<clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int a[1000] = { 2, 3, 7, 9, 5, 8, 1, 4, 6, 0 }; // пример

    int left = 0, right = 999, firstZero = 1000, checks = 0;


    while (left <= right) {
        checks++;
        int mid = (left + right) / 2;
        a[mid] == 0 ? (firstZero = mid, right = mid - 1) : (left = mid + 1);
    }

    cout << "Ненулевых элементов: " << firstZero << endl;
    cout << "Проверок: " << checks  << endl;

    return 0;
}