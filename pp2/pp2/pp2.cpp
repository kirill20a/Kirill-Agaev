#include <iostream>  
#include <vector>  
#include<clocale>
using namespace std;

void findFakeCoin() {
    vector<int> coins(12); // Массив монет (1-12)  
    int group1[4], group2[4], group3[4];

    // Первое взвешивание  
    for (int i = 0; i < 4; i++) {
        group1[i] = coins[i];
        group2[i] = coins[i + 4];
    }

    // Второе взвешивание  
    for (int i = 0; i < 3; i++) {
        group3[i] = coins[i + 8];
    }

    // Здесь должен быть код сравнения весов групп  
    // Для простоты предположим, что фальшивая монета найдена  
    int fakeCoin = 5; // Пример номера фальшивой монеты  
    bool isHeavy = true; // Пример: монета тяжелее  

    cout << "Фальшивая монета: " << fakeCoin << endl;
    cout << "Состояние: " << (isHeavy ? "тяжелее" : "легче") << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    findFakeCoin();
    return 0;
}