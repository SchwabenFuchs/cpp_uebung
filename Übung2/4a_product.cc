/*calculates some product sum*/

#include <iostream>
using namespace std;

int main()
{
    printf("Input a number N: \n");
    int N;
    cin >> N;
    int P = 1;
    for (int i = 0; i <= N; i++)
    {
        P = P * (2 * i + 1);
        printf("P_%i = %i \n", i, P);
    }
    return 0;
}
