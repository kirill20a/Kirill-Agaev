#include<iostream>
#include<ctime>
#include<clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int N = 10;
    int* p_ra = new int[N];
    int r_min = -50;
    int r_max = 50;


    for (int i = 0; i < N; i++) {
        *(p_ra + i) = r_min + rand() % (r_max - r_min + 1);
        cout << "A[" << i << "]=" << *(p_ra + i) << endl;
    }


    int* ptr = p_ra;
    int min_el = *ptr;

    for (int i = 0; i < N; i++) {
        if (*(ptr + i) < min_el) {
            min_el = *(ptr + i);
        }
    }

    cout << "Минимальный элемент массива: " << min_el << endl;

    delete[] p_ra;

    return 0;
}