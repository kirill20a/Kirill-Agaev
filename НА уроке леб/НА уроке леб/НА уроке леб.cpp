#include<iostream>
#include<ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	int N = 10;
	int* p_ra = new int[N];
	int r_min = -50;
	int r_max = 50;
	int minimum=*(p_ra)= r_min + rand() % (r_max - r_min + 1);
	for (int i = 0; i < N; i++) {
		*(p_ra + i) = r_min + rand() % (r_max - r_min + 1);
		cout << "A[" << i << "]=" << *(p_ra + i) << endl;
	}


	return 0;
}