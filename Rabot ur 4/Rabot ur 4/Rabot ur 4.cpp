#include<iostream>
#include <string>
#include<clocale>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	string m;
	cout << "Введите систеу счисления от 2 до 35  ";
	cin >> n;
	if (n < 2 || n > 35) {
		cout << "Ошибка: число не может быть больше 35 и меньше 2  " << endl;
		return 1;
	}
	cout << "Введите число ";
	cin >> m;
	

	if (m.empty()) {
		cout << "Ошибка: число не может быть пустым  " << endl;
		return 1;
	}
	unsigned long long res = 0;
	int length = m.length();
	bool Val = true;

	for (int i = 0; i < length; i++) {
		char masm = m[i];
		int dgVal;

		if (masm >= '0' && masm <= '9') {
			dgVal = masm - '0';
		}
		else if (masm >= 'A' && masm <= 'Z') {
			dgVal = masm - 'A' + 10;
		}
		else {
			Val = false;
			break;
		}
		int power = length - 1 - i;
		long long powerVal = 1;

		for (int j = 0; j < power; j++) {
			powerVal *= n;
		}

		res += dgVal * powerVal;
	}
		if (Val) {
			cout << "Число " << m << " в системе счисления " << n
				<< " равно " << res << " в десятичной системе" << endl;
		}
		else {
			return 1;
		}

		return 0;
}