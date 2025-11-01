#include <iostream>
#include<clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    const int max_l = 80;
    char input[max_l + 1]; 
    char output[max_l + 1];

    cout << "Введите строку (максимум 80 символов): ";
    cin.getline(input, max_l + 1);

    char* src = input;  
    char* dest = output; 

    while (*src == ' ') {
        src++;
    }

    
    bool space_ = false;

    
    while (*src != '\0') {
        if (*src == ' ') {
            if (!space_) {
                *dest = ' ';
                dest++;
                space_ = true;
            }
        }
        else {
            *dest = *src;
            dest++;
            space_ = false;
        }
        src++;
    }

    
    if (dest > output && *(dest - 1) == ' ') {
        dest--;
    }


    *dest = '\0';

    cout << "Новая строка: \"" << output << "\"" << endl;

    return 0;
}