/*Genauigkeitstest*/

#include <iostream>
using namespace std;

int main(){
    float epsilon = 1; 
    while (1 != 1 + epsilon){
        epsilon = epsilon * 1/2;
    }
    auto zeros = 2*epsilon;
    printf("2*epsilon: %.2e \n", zeros);
    return 0;
}