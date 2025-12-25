#include <stdio.h>
#include <stdlib.h>
#include<clocale>
void read_input(int*, int*);

int main() {
    setlocale(LC_ALL,"Russian")''
    int a, b, p, q;
    read_input(&a, &b);

    p = a / b;
    q = a % b;
    printf("p: %d, q: %d\n", p, q);

    int x = a;
    int y = b;

    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }

    printf("НОД(%d, %d) = %d\n", a, b, x);

    return 0;
}

void read_input(int* a, int* b) {
    printf("Введите два числа: ");
    scanf("%d %d", a, b);
}