#include <iostream>
#include<clocale>
using namespace std;

void REC1(int n, int divis = 2) {
	if (n == 1) {
		return;
	}
	if (n % divis == 0) {
		cout << divis << "" << endl;
		REC1(n / divis, divis);
	}
	else {
		REC1(n, divis + 1);
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите число" << endl;
	cin >> n;
	REC1(n);
	return 0;
}