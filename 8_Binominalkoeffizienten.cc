#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    /*prints pascals triangle*/
    int zeile[10];
    int zeiletmp[10];

    for (int n = 0; n < 10; n++)
    {
        for (int a = 0; a < n; a++)
        {
            zeiletmp[a] = zeile[a];
        }
        zeile[0] = 1;
        zeile[n] = 1;
        for (int k = 1; k <= n + 1; k++)
        {
            zeile[k] = zeiletmp[k - 1] + zeiletmp[k];
        }
        printf("\n\n");
        cout << setw(40-2.3*n) << " ";
        for (int k = 0; k <= n; k++)
        {
            // printf("%d", zeile[k]);
            cout << setw(5) << zeile[k];
        }
    }

    printf("\n\n");
    return 0;
}