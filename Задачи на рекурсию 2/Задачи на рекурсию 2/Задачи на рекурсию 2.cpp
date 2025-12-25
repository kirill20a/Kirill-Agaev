#include<clocale>
#include <iostream>

using namespace std;

bool is_palind(const char* word, int left, int right) {
	if (left >= right) {
		return true;
	}
	if (word[left] != word[right]) {
		return false;
	}
	return is_palind(word, left + 1, right - 1);
}
int main() {
    setlocale(LC_ALL, "Russian");
    char word[101];
    cout << "Введите текст через пробел максимум букв 101" << endl;
    cin.getline(word, 101);

    int length = 0;
    while (word[length] != '\0') {
        length++;
    }

    if (is_palind(word, 0, length - 1)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}