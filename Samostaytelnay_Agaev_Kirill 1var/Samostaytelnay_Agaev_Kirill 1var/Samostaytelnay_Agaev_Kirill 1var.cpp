#include <iostream>
#include <string>
#include <cmath>

using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    const int MAX_inp = 50;
    const int SNILS_len = 11;

    char input[MAX_inp];
    char CL_SN[SNILS_len + 1];
    int CL_IND = 0;

    cout << "Введите номер СНИЛС: ";
    cin.getline(input, MAX_inp);


    for (int i = 0; input[i] != '\0' && CL_IND < SNILS_len; i++) {
        if (isdigit(input[i])) {
            CL_SN[CL_IND] = input[i];
            CL_IND++;
        }
    }
    CL_SN[CL_IND] = '\0';


    if (CL_IND != SNILS_len) {
        cout << "Ошибка: должно быть 11 цифр! Введено: " << CL_IND << endl;
        return 1;
    }


    int sum = 0;
    int weights[9] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };


    for (int i = 0; i < 9; i++) {
        int digit = CL_SN[i] - '0';
        sum += digit * weights[i];
        

    }
    cout<< sum << endl;

    int contr_N = sum % 101;
    if (contr_N == 100) contr_N = 0;


    int Last_2 = (CL_SN[9] - '0') * 10 + (CL_SN[10] - '0');

    cout << "\nРезультат проверки:" << endl;

    for (int i = 0; i < SNILS_len; i++) {

    }
    cout << endl;
    cout << "Контрольная сумма: " << sum << endl;
    cout << "Вычисленное контрольное число: " << contr_N << endl;
    cout << "Фактическое контрольное число: " << Last_2 << endl;

    if (contr_N == Last_2) {
        cout << " Номер СНИЛС корректен!" << endl;
    }
    else {
        cout << " Номер СНИЛС некорректен!" << endl;
        return 1;
    }
}