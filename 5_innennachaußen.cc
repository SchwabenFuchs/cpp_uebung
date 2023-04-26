/*computes some stupier term*/

#include <iostream>
using namespace std;

int main()
{
    float P = 1;
    int n;
    printf("Input number n: ");
    cin >> n;
    for (int i = n; i > 0; i--)
    {
        P = 1 + P * i / (2 * i + 1);
    }
    printf("P_n: %f \n2*P_n: %f \n", P, 2*P);
}