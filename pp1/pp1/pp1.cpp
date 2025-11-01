#include <iostream>
#include <cstdlib>
#include <ctime>
#include<clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const int n = 20; // размер массива
    int K[n];

    // Заполняем массив случайными числами с дубликатами
    srand(time(NULL));
    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        K[i] = rand() % 10; // числа от 0 до 9 (будут дубликаты)
        cout << K[i] << " ";
    }
    cout << endl;

    // Алгоритм удаления дубликатов
    int uniqueCount = 0; // счетчик уникальных элементов

    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;

        // Проверяем, встречался ли текущий элемент ранее
        for (int j = 0; j < uniqueCount; j++) {
            if (K[j] == K[i]) {
                isDuplicate = true;
                break;
            }
        }

        // Если элемент не дубликат, добавляем его в начало массива
        if (!isDuplicate) {
            K[uniqueCount] = K[i];
            uniqueCount++;
        }
    }

    // Вывод результата
    cout << "Массив без дубликатов: ";
    for (int i = 0; i < uniqueCount; i++) {
        cout << K[i] << " ";
    }
    cout << endl;

    cout << "Было элементов: " << n << endl;
    cout << "Стало уникальных: " << uniqueCount << endl;
    cout << "Удалено дубликатов: " << n - uniqueCount << endl;

    return 0;
}