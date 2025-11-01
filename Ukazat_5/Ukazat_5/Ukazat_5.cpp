#include <iostream>
#include <cstring>
#include<clocale>
using namespace std;

const int max_L = 200;

int main() {
    setlocale(LC_ALL, "Russian");
    char input[max_L];
    char result[max_L] = { 0 };

    cout << "Введите выражение со скобками: ";
    cin.getline(input, max_L);


    int balance = 0;
    char* ptr = input;
    bool correct = true;


    while (*ptr != '\0' && correct) {
        if (*ptr == '(') {
            balance++;
        }
        else if (*ptr == ')') {
            balance--;
            if (balance < 0) {
                correct = false;
                cout << "Ошибка: закрывающая скобка без открывающей!" << endl;
            }
        }
        ptr++;
    }

    if (balance > 0 && correct) {
        correct = false;
        cout << "Ошибка: " << balance << " незакрытых скобок!" << endl;
    }

    if (!correct) {
        return 1;
    }


    int level = 0;
    int Res_ind = 0;
    ptr = input;

    while (*ptr != '\0') {
        if (*ptr == '(') {
            level++;

            if (level == 1) {
                result[Res_ind++] = '(';
            }
            else if (level == 2) {
                result[Res_ind++] = '[';
            }
            else {
                result[Res_ind++] = '{';
            }
        }
        else if (*ptr == ')') {

            if (level == 1) {
                result[Res_ind++] = ')'; 
            }
            else if (level == 2) {
                result[Res_ind++] = ']';
            }
            else {
                result[Res_ind++] = '}';
            }
            level--;
        }
        else {

            result[Res_ind++] = *ptr;
        }
        ptr++;
    }

    result[Res_ind] = '\0';

    cout << "Преобразованное выражение: " << result << endl;

    return 0;
}