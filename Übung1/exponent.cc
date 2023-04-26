/* Input is a float x. Outputs exp(x). */

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double x;
    printf("Input a number:\n");
    cin >> x;
    printf("e^x= %f \n", exp(x));
    cout << exp(x);
    return(0);
}