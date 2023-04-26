/*computes some strange double sum*/

#include <iostream>
using namespace std;

float first_sum(int i){
    float P = 1;
    for (int j=1; j<=i; j++){
        P += 1 / (i * j);
    }
    return P;
}


int main(){
    printf("Input number N: ");
    int N;
    cin >> N;
    float S = 0;
    for (int i=1; i<=N; i++){
        S += first_sum(i);
    }
    printf("Result: %f \n", S);
    return 0;
}