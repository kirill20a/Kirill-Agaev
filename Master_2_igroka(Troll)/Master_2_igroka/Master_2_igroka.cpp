#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    const int BOARD_SIZE = 64;
    bool coins[BOARD_SIZE];


    cout << "=== НАЧАЛЬНОЕ СОСТОЯНИЕ ДОСКИ ===" << endl;
    for (int i = 0; i < BOARD_SIZE; i++) {
        coins[i] = rand() % 2;
        cout << (coins[i] ? "O" : "R");
        if ((i + 1) % 8 == 0) cout << endl;
        else cout << " ";
    }

    
    cout << "\n=== ВЫЧИСЛЕНИЕ НАЧАЛЬНОГО КЛЮЧА ===" << endl;
    int initialKey = 0;
    cout << "Начинаем с key = 0" << endl;

    int stepCount = 0;
    int firstSteps[3] = { -1, -1, -1 };
    int lastSteps[3] = { -1, -1, -1 };
    int lastStepIndex = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        if (coins[i]) {
            if (stepCount < 3) {
                firstSteps[stepCount] = i;
                cout << "Шаг " << (stepCount + 1) << ": key = " << initialKey << " XOR " << i;
                initialKey ^= i;
                cout << " = " << initialKey << endl;
            }
            else {
                initialKey ^= i;
            }

            lastSteps[lastStepIndex] = i;
            lastStepIndex = (lastStepIndex + 1) % 3;
            stepCount++;
        }
    }


    if (stepCount > 6) {
        cout << "(пропущено " << (stepCount - 6) << " шагов) ..." << endl;
    }
    for (int i = 0; i < 3; i++) {
        if (lastSteps[i] != -1) {
            int tempKey = 0;
            for (int j = 0; j < lastSteps[i]; j++) {
                if (coins[j]) tempKey ^= j;
            }
            int stepNum = stepCount - 2 + i;
            if (stepNum > stepCount) stepNum -= 3;
            cout << "Шаг " << stepNum << ": key = " << tempKey << " XOR " << lastSteps[i];
            tempKey ^= lastSteps[i];
            cout << " = " << tempKey << endl;
        }
    }

    cout << "Финальный начальный ключ: " << initialKey << endl;

    int masterChoice = rand() % BOARD_SIZE;
    cout << "\n=== ХОД МАСТЕРА ===" << endl;
    cout << "Мастер указывает на клетку: " << masterChoice << endl;
    cout << "Состояние монеты: " << (coins[masterChoice] ? "Орёл" : "Решка") << endl;


    cout << "\n=== ПЕРВЫЙ ИГРОК ВЫЧИСЛЯЕТ ТЕКУЩИЙ КЛЮЧ ===" << endl;
    int currentKey = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (coins[i]) {
            currentKey ^= i;
        }
    }
    cout << "Текущий ключ доски: " << currentKey << endl;

    cout << "\n=== ВЫЧИСЛЕНИЕ ХОДА ПЕРВОГО ИГРОКА ===" << endl;
    cout << "P = " << currentKey << " XOR " << masterChoice;
    int playerMove = currentKey ^ masterChoice;
    cout << " = " << playerMove << endl;

    cout << "Проверка: P = " << currentKey << " XOR " << playerMove;
    cout << " = " << (currentKey ^ playerMove) << " (должно равняться " << masterChoice << ")" << endl;

    cout << "Первый игрок переворачивает монету в клетке: " << playerMove << endl;
    cout << "Было: " << (coins[playerMove] ? "Орёл" : "Решка");
    coins[playerMove] = !coins[playerMove];
    cout << " => Стало: " << (coins[playerMove] ? "Орёл" : "Решка") << endl;


    cout << "\n=== ВТОРОЙ ИГРОК ВЫЧИСЛЯЕТ ФИНАЛЬНЫЙ КЛЮЧ ===" << endl;
    int finalKey = 0;
    cout << "Начинаем с key = 0" << endl;

    stepCount = 0;
    int firstStepsFinal[3] = { -1, -1, -1 };
    int lastStepsFinal[3] = { -1, -1, -1 };
    lastStepIndex = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        if (coins[i]) {
            if (stepCount < 3) {
                firstStepsFinal[stepCount] = i;
                cout << "Шаг " << (stepCount + 1) << ": key = " << finalKey << " XOR " << i;
                finalKey ^= i;
                cout << " = " << finalKey << endl;
            }
            else {
                finalKey ^= i;
            }

            lastStepsFinal[lastStepIndex] = i;
            lastStepIndex = (lastStepIndex + 1) % 3;
            stepCount++;
        }
    }


    if (stepCount > 6) {
        cout << "... (пропущено " << (stepCount - 6) << " шагов) ..." << endl;
    }
    for (int i = 0; i < 3; i++) {
        if (lastStepsFinal[i] != -1) {
            int tempKey = 0;
            for (int j = 0; j < lastStepsFinal[i]; j++) {
                if (coins[j]) tempKey ^= j;
            }
            int stepNum = stepCount - 2 + i;
            if (stepNum > stepCount) stepNum -= 3;
            cout << "Шаг " << stepNum << ": key = " << tempKey << " XOR " << lastStepsFinal[i];
            tempKey ^= lastStepsFinal[i];
            cout << " = " << tempKey << endl;
        }
    }

    cout << "Финальный ключ доски: " << finalKey << endl;

    cout << "\n=== ХОД ВТОРОГО ИГРОКА ===" << endl;
    cout << "Второй игрок вычисляет ключ доски: " << finalKey << endl;
    cout << "Второй игрок объявляет: 'Мастер выбрал клетку " << finalKey << "'" << endl;

 
    cout << "\n=== РЕЗУЛЬТАТ ===" << endl;
    cout << " ПОБЕДА! Второй игрок угадал правильно!" << endl;
    cout << "Мастер выбрал: " << masterChoice << endl;
    cout << "Предсказание: " << finalKey << endl;
    return 0;
}