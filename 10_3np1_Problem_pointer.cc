#include <iostream>
#include <cmath>
using namespace std;

void Collatz_Algorithmus(int a_1, int * Anzahl, int * Maximum)
{
    //Anzahl_Maximal result;
    int a_n = a_1;
    int a_max = a_1;
    int n = 1;
    printf("a_%i = %i \n", n, a_n);
    while (a_n != 1)
    {
        if (a_n % 2 == 0)
        {
            a_n = a_n / 2;
        }
        else
        {
            a_n = 3 * a_n + 1;
        }
        if (a_n > a_max){
            a_max = a_n;
        }
        n++;
        * Anzahl = n - 1;
        * Maximum = a_max;
        printf("a_%i = %i \n", n, a_n);
    }
    return;
}

int main()
{
    int a_1;
    printf("Input starting natural number a_1: \n");
    cin >> a_1;
    printf("\n");
    int Anzahl;
    int Maximum;
    Collatz_Algorithmus(a_1, &Anzahl, &Maximum);
    printf("\n\n\nStartzahl a_1 = %i \nMaximum a_max = %i \nSchritte n = %i \n\n", a_1, Maximum, Anzahl);
    return 0;
}
