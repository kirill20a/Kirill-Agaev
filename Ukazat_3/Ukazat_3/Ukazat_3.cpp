#include <iostream>
#include<clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    const int max_l = 80;
    char input[max_l + 1];

    cout << "Введите строку (максимум 80 символов): ";
    cin.getline(input, max_l + 1);

    int dit_count[10] = { 0 }; 

    char* ptr = input;

    while (*ptr != '\0') {
        if (*ptr >= '0' && *ptr <= '9') {
            dit_count[*ptr - '0']++;
        }
        ptr++;
    }

    int Count = 0;
    int most_freq = -1;

    for (int i = 0; i < 10; i++) {
        if (dit_count[i] > Count) {
            Count = dit_count[i];
            most_freq = i;
        }
    }

    if (most_freq == -1) {
        cout << "В строке отсутствуют цифры." << endl;
    }
    else {
        cout << "Наиболее часто встречающаяся цифра: '" << most_freq
            << "' (встретилась " << Count << " раз";
        if (Count == 1) {
            cout << ")";
        }
        else {
            cout << "а)";
        }
        cout << endl;
    }

    return 0;
}
