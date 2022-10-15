// поиск простых чисел по решету Сундарама

#include <iostream>
#include <vector>

using namespace std;


void sundaram(int N){
    vector<int> S(((N - 1)/2));

    // создание вектора S (1, 2, ..., (N - 1)/2)
    for(int i = 1; i <= (N - 1) / 2; i++){
        S.at(i - 1) = i;
    }

    // цикл по i (1 <= i <= j)
    for(int i = 1; i <= N; i++){
        
        // цикл по j (1 <= j <= N)
        for(int j = 1; j <= N; j++){
            
            // цикл проверки всех чисел на вид i + j + 2ij
            for(int t = 0; t < size(S); t++){
                
                if(S.at(t) == i + j + 2*i*j){
                    //вычеркивание числа вида i + j + 2ij
                    S.erase(S.begin() + t);
                }
            }
        }
    }

    // вывод
    for(int i = 0; i < size(S); i++){
        cout << 2 * S.at(i) + 1 << ' ';
    }
}

int main(){
    sundaram(25);
}