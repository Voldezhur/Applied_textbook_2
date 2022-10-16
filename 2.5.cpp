// 10 чисел фон Неймана длины 5

#include <iostream>

using namespace std;


/* 
функция, которая возвращает число фон Неймана длины х,
используя начальное число А
*/
double fonNeyman(unsigned int x){
    if(x < 8){
        // seed
        static double A = 8691454516;

        // get the number from which to get the random value
        string B = to_string(A*A);
        string num = "";

        // index to start building randomized value from
        int n = 10;
        

        // build randomized value with numbers taken from the middle of the original number (from 5th to (x-1)th)
        for(int i = n; i <= n + x - 1; i++){
            // check if value starts with 0 and if it does replace 0  with 1
            if(i == n && B[i] == '0'){
                num += '1';
            }

            else{
                num += B[i];
            }
        }


        // replace A with B for different results, checking if the first number is 0 and replacing it with 1 in that case
        if(B[4] == '0'){
            B[4] = '1';
        }

        A = stod(B.substr(4, 11));
    

        // return final randomized value
        return stod(num);
    }


    else{
        cout << "x must be less than 8";
    }
    
    return 0;
}


int main(){
    for(int i = 0; i < 10; i++){
        cout << fonNeyman(5) << '\n';
    }
}