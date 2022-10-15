// факторизация методом простого перебора

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


bool isSimple(int N){
    if(N == 1){
        return true;
    }

    vector<int> S(N - 1);

    // создание вектора S (2, 3, ..., N)
    for(int i = 2; i <= N; i++){
        S.at(i - 2) = i;
    }

    bool loop = true;

    for(int k = 0; loop; k++){
        // счетчик составных чисел в векторе S
        // p - очередной делитель
        int t = 0, p = S.at(k);

        // проверка всех чисел вектора S кроме p на предмет делимости на p
        // если делится - удаляется из вектора и t++
        for(int i = k + 1; i < size(S); i++){
            if(S.at(i) % p == 0){
                S.erase(S.begin() + i);
                t++;
            }
        }

        // составных чисел в векторе нет => выход из цикла
        if(t == 0){
            loop = false;
        }
    }

    // окончательный вывод
    // проверка, есть ли проверяемое число в векторе
    for(int i = 0; i < size(S); i++){
        if(S.at(i) == N){
            return true;
        }
    }

    return false;
}

vector<int> eratosphen(int N){
    vector<int> S(N - 1);

    // создание вектора S (2, 3, ..., N)
    for(int i = 2; i <= N; i++){
        S.at(i - 2) = i;
    }

    bool loop = true;

    for(int k = 0; loop; k++){
        // счетчик составных чисел в векторе S
        // p - очередной делитель
        int t = 0, p = S.at(k);

        // проверка всех чисел вектора S кроме p на предмет делимости на p
        // если делится - удаляется из вектора и t++
        for(int i = k + 1; i < size(S); i++){
            if(S.at(i) % p == 0){
                S.erase(S.begin() + i);
                t++;
            }
        }

        // составных чисел в векторе нет => выход из цикла
        if(t == 0){
            loop = false;
        }
    }

    // окончательный вывод
    return S;
}


int main(){
    int a, del = 0, t = 0;
    cin >> a;

    // проверка входного числа на простоту
    if(isSimple(a)){
        cout << "Число простое";
        return 0;
    }


    // факторизация
    vector<int> A = eratosphen(round(sqrt(a)));
    
    bool simple = false;

    // цикл факторизации
    while(!simple){
        // перебор простых делителей p
        for(int i = 0; i < size(A); i++){
            if(a % A.at(i) == 0){
                int p = A.at(i);

                // счетчик раз, сколько можно поделить a на делитель p
                int t = 0;
                
                // подсчет количества делений
                while(a % p == 0){
                    a /= p;
                    t++;
                }

                // вывод промежуточного делителя p в степени t
                cout << p << '^' << t;
                break;
            }
        }

        // проверка числа на простоту и выход из цикла, если это так
        // если составное => продолжаем перебор, вывод '*'
        simple = isSimple(a);
        if(!simple){
            cout << '*';
        }
    }
    
    // вывод оставшегося числа a
    cout << '*' << a;
}