#include <iostream>
#include <locale.h>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Преобразование числа в двоичную систему" << endl;
    double NUM;

    cout << "Введите число: ";
    cin >> NUM;


    int chelay = (int)NUM;
    double Drob = NUM - chelay;

    cout << "Число: " << NUM << endl;
    cout << "Целая часть: " << chelay << endl;
    cout << "Дробная часть: " << Drob << endl;
    cout << "Двоичное представление: ";

    if (chelay == 0) {
        cout << "0";
    }
    else {
        int binValue = 0x40000000;


        while (binValue > chelay) binValue >>= 1;

        while (binValue > 0)
        {
            if (chelay >= binValue)
            {
                cout << "1";
                chelay -= binValue;
            }
            else
                cout << "0";
            binValue >>= 1;
        }
    }

    if (Drob > 0) {
        cout << ".";

        for (int i = 0; i < 24; i++)
        {
            Drob *= 2;

            cout << (int)Drob;
            Drob -= (int)Drob;

            if (Drob <= 1e-8)
                break;
        }
    }

    cout << endl;

    return 0;
}