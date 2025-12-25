#include <iostream>
#include<clocale>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int ocenka;

		cout << "Введите оценку:_1-5";
		cin >> ocenka;
		if (ocenka == 5) {
			cout << "Отлично" << endl;
		}
		else if (ocenka == 4) {
			cout << "Хорошо" << endl;
		}
		else if (ocenka == 3) {
			cout << "Удовл" << endl;
		}
		else if (ocenka == 2) {
			cout << "плохо" << endl;
		}
		else if (ocenka == 1) {
			cout << "Ужасно" << endl;

		}
		else {
			cout << "Неверная оценка" << endl;
		}
		return 0;
}

