#include <iostream>
#include<clocale>
using namespace std;

const int max_L = 80;

int main() {
    setlocale(LC_ALL, "Russian");
    char input[max_L + 1];
    char stack[max_L];
    int top = -1;

    cout << "Введите строку для проверки скобок: ";
    cin.getline(input, max_L + 1);

    char* ptr = input;
    bool correct = true;

    while (*ptr != '\0' && correct) {

        if (*ptr == '(' || *ptr == '[' || *ptr == '{') {
            if (top < max_L - 1) {
                stack[++top] = *ptr;
            }
        }

        else if (*ptr == ')' || *ptr == ']' || *ptr == '}') {
            if (top == -1) {
                correct = false; 
                break;
            }

            char L_open = stack[top--];


            if ((L_open == '(' && *ptr != ')') ||
                (L_open == '[' && *ptr != ']') ||
                (L_open == '{' && *ptr != '}')) {
                correct = false;
                break;
            }
        }
        ptr++;
    }


    if (correct && top != -1) {
        correct = false;
    }

    cout << "Скобки расставлены " << (correct ? "корректно!" : "НЕкорректно!") << endl;

    return 0;
}