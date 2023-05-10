#include <iostream>
#include <cmath>
#include <iostream>
using namespace std;

struct Anzahl_Maximal{
    int Anzahl;
    int Maximum;
} typedef Anzahl_Maximal;

Anzahl_Maximal Collatz_Algorithmus(int a_1)
{
    Anzahl_Maximal result;
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
        result.Anzahl = n - 1;
        result.Maximum = a_max;
        printf("a_%i = %i \n", n, a_n);
    }
    return result;
}

int main()
{
    int a_1;
    printf("Input starting natural number a_1: \n");
    cin >> a_1;
    printf("\n");
    auto result = Collatz_Algorithmus(a_1);
    printf("\n\n\nStartzahl a_1 = %i \nMaximum a_max = %i \nSchritte n = %i \n\n", a_1, result.Maximum, result.Anzahl);
    return 0;
}
