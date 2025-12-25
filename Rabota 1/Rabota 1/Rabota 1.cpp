#include <iostream>
#include <clocale>
#include<locale.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cout<<"Поиск сов. чисел.Введите max: ";
	cin>>n;
	if (n < 6)
	{
		cout<<"Not found"<<endl;
		return 0;
	}
	for (int i=6; i<=n; i+=1) {
		int sum=1;
		for (int j=2; j<=i/2; j+=1) {
			if (i%j==0) {
				sum += j;
				if (sum > i)
					break;
			}
		}
		if (sum != i)
			continue;
		cout<<i<<"=1+"; sum = 1;
		for (int j = 2; j <= i / 2; j += 1)
			if (i % j == 0)
			{
				cout << j;
				sum += j;
				if (sum == i) 
				{
					cout << endl;
					break;
				}
				else cout << "+";
			}
	}
	return 0;
}