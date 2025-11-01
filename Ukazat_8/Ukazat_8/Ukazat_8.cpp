#include <iostream>
#include<clocale>
using namespace std;

const int M = 5;
const int N = 4;

int main() {
    setlocale(LC_ALL, "Russian");
    int L[M][N] = {
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0},//дубликат
        {1, 1, 0, 0},
        {0, 1, 0, 1}//дубликат
    };

    cout << "Исходная матрица " << M << "x" << N << ":" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << L[i][j] << " ";
        }
        cout << endl;
    }


    bool keepRow[M] = { true, true, true, true, true };

    for (int i = 0; i < M; i++) {
        if (keepRow[i]) {
            for (int j = i + 1; j < M; j++) {
                bool equal = true;
                for (int k = 0; k < N; k++) {
                    if (L[i][k] != L[j][k]) {
                        equal = false;
                        break;
                    }
                }
                if (equal) {
                    keepRow[j] = false;
                }
            }
        }
    }


    int remaining = 0;
    for (int i = 0; i < M; i++) {
        if (keepRow[i]) remaining++;
    }


    int** result = new int* [remaining];
    int* binary = new int[remaining];

    for (int i = 0; i < remaining; i++) {
        result[i] = new int[N];
    }

    int resultIndex = 0;
    for (int i = 0; i < M; i++) {
        if (keepRow[i]) {

            for (int j = 0; j < N; j++) {
                result[resultIndex][j] = L[i][j];
            }

            int bin = 0;
            for (int j = 0; j < N; j++) {
                bin = bin * 2 + L[i][j];
            }
            binary[resultIndex] = bin;
            resultIndex++;
        }
    }


    for (int i = 0; i < remaining - 1; i++) {
        for (int j = 0; j < remaining - i - 1; j++) {
            if (binary[j] > binary[j + 1]) {

                swap(binary[j], binary[j + 1]);

                for (int k = 0; k < N; k++) {
                    swap(result[j][k], result[j + 1][k]);
                }
            }
        }
    }

    cout << "\nФИНАЛЬНЫЙ РЕЗУЛЬТАТ :" << endl;
    for (int i = 0; i < remaining; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j] << " ";
        }
        cout << "= " << binary[i] << " в дес." << endl;
    }


    for (int i = 0; i < remaining; i++) {
        delete[] result[i];
    }
    delete[] result;
    delete[] binary;

    return 0;
}