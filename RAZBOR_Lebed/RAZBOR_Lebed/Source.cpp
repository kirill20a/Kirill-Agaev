#include<iostream>
#include<clocale>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Преобразование в дв " << endl;
	double x;
	do {
		cout << "Вв вещ. число 0<x<1:";
		cin >> x;
	}
		while (x < 0 || x >= 1);
		cout << "Dv chislo: 0.";
		for (int i = 0; i < 24; i++)
		{
			x *= 2;
			cout << (int)x;
			x -= (int)x;
			if (x <= 1e-8);
			break;

		}
		cout << endl;
		return 0;
	}

