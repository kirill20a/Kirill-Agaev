#include <iostream>
#include<clocale>

using namespace std;

int main(){
	setlocale(LC_ALL, "Russian");
	int nam, tar;
	cout << "Введите числло";
	cin >> nam;
	cout << "Введите chifru";
	cin >> tar;
	nam = abs(nam);

	int ct = 0;
	int k = nam;
	while (k > 0) {
		int del = k % 10;
		if (del == tar) {
			ct++;

		}
		k /= 10;
	}
	cout << "цифра_" << tar << "  встречается_" << ct << "  раз в числе:" << nam << endl;
	return 0;
}