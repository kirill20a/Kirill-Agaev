#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
    ofstream out("prime.txt");
    const int PRIME_NUM = 1e6;
    int primeFound = 0;
    vector<int> primeArray;
    primeArray.reserve(PRIME_NUM);
    int current = 2;
    bool isPrime = true;

    while (primeFound < PRIME_NUM)
    {
        isPrime = true;
        int limit = sqrt(current);

        for (int i = 0; i < primeFound && primeArray[i] <= limit; i++)
        {
            if (current % primeArray[i] == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
        {
            out << current << endl;
            primeArray.push_back(current);
            primeFound++;

        }
        current++;
    }

    cout << "Готово! Найдено " << PRIME_NUM << " простых чисел." << endl;
    return 0;
}