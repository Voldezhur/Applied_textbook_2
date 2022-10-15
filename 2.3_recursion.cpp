// факторизация методом Ферма

// 

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


bool isSimple(int N){
    if(N == 1){
        return true;
    }

    vector<long int> S(N - 1);

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

int ferm(int n){
    // проверка, простое ли входное число
    if(isSimple(n)){
        cout << n << '*';
        return -1;
    }

    // вычисление целой части от корня n
    int m = floor(sqrt(n)), x = 1;
    float y; // переменная для работы функции modf()

    // число - полный квадрат => вывод корень n * корень n
    if(modf(sqrt(n), &y) == 0){
        int sq = sqrt(n);
        
        ferm(sq);
        ferm(sq);

        return 0;
    }

    // начало цикла нахождения полного квадрата
    float q = pow((m + x), 2) - n;

    // пока q - не полный квадрат
    while(modf(sqrt(q), &y) != 0){
        x++;
        q = pow((m + x), 2) - n;
    }

    ferm(m + x - sqrt(q));
    ferm(m + x + sqrt(q));

    return 0;
}


int main(){
    int n, N;
    cin >> n;

    ferm(n);
}