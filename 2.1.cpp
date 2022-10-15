// НОД 4-ех чисел, заданных с клавиатуры

#include <iostream>

using namespace std;


int nod(int a, int b){
    while(a != b){
        if(a > b){
            a -= b;
        }
        
        else{
            b -= a;
        }
    }

    return a;
}


int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    a = nod(a, b);
    a = nod(a, c);
    a = nod(a, d);

    cout << a;
}