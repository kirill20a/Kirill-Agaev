#include <iostream>
#include <algorithm>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите размер n: ";
    cin >> n;


    int size = (n * n)-1;
    int* A = new int[size];
    cout << "rabot random";
    cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) {
        A[i] = rand() % 100;  
        cout << A[i] << " ";
    }
    cout << endl;

    sort(A, A + size);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    int** spiral = new int* [n];
    for (int i = 0; i < n; i++) {
        spiral[i] = new int[n];
    }

    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int index = 0;

    while (top <= bottom && left <= right) {

        for (int i = left; i <= right; i++) {
            spiral[top][i] = A[index++];
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            spiral[i][right] = A[index++];
        }
        right--;

        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                spiral[bottom][i] = A[index++];
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                spiral[i][left] = A[index++];
            }
            left++;
        }
    }

    cout << "Массив, заполненный по спирали:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << spiral[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] spiral[i];
    }
    delete[] spiral;
    delete[] A;

    return 0;
}