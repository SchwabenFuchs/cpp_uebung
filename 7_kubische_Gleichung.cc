#include <iostream>
#include <cmath>
#include "a7-kubisch-fragment.cc"
using namespace std;

float pi = 3.141;

int main()
/*computes roots of cubic equation*/
{
    double a, b, c, d;
    do {

    printf("This program calculates the roots of a 3. order polynomial equation of the form f(x) = a*x^3 + b*x^2 + c*x + d.\nInput the parameters. \na: ");
    cin >> a;
    }
    while (a==0);
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
    cout << "d: ";
    cin >> d;

    printf("\n%+.2f*x^3 %+.2f*x^2 %+.2f*x %+.2f = 0 \n\n", a, b, c, d);

    double p, q, D;
    p = (3 * a * c - pow(b, 2)) / (3 * pow(a, 2));
    q = 2 * pow(b, 3) / (27 * pow(a, 3)) - b * c / (3 * pow(a, 2)) + d / a;
    D = pow((q / 2), 2) + pow((p / 3), 3);

    int x_1_vielfachheit, x_2_vielfachheit, x_3_vielfachheit;
    double x_1, x_2, x_3;

    if (D > 0)
    {
        x_1_vielfachheit = 1;
        x_1 = cubicroot(-q / 2 - sqrt(D)) + cubicroot(-q / 2 + sqrt(D)) - b / (3 * a);
        printf("x_1 = %f \nVielfachheit = %d", x_1, x_1_vielfachheit);
    }
    else if (D == 0)
    {
        if (q == 0)
        {
            x_1_vielfachheit = 3;
            x_1 = -b / (3 * a);
            printf("x_1 = %f \nVielfachheit = %d", x_1, x_1_vielfachheit);
        }
        else
        {
            x_1_vielfachheit = 2;
            x_1 = cubicroot(q / 2) - b / (3 * a);
            x_2_vielfachheit = 1;
            x_2 = cubicroot(-4 * q) - b / (3 * a);
            printf("x_1 = %f \nVielfachheit = %d \n\nx_2 = %f \nVielfachheit = %d", x_1, x_1_vielfachheit, x_2, x_2_vielfachheit);
        }
    }
    else if (D < 0)
    {
        double h = acos(-q / 2 * sqrt(-27 / pow(p, 3)));
        x_1_vielfachheit = 1;
        x_1 = -sqrt(-4 * p / 3) * cos(h / 3 - pi / 3) - b / (3 * a);
        x_2_vielfachheit = 1;
        x_2 = -sqrt(-4 * p / 3) * cos(h / 3 + pi / 3) - b / (3 * a);
        x_3_vielfachheit = 1;
        x_3 = sqrt(-4 * p / 3) * cos(h / 3) - b / (3 * a);
        printf("x_1 = %f \nVielfachheit = %d \n\nx_2 = %f \nVielfachheit = %d \n\nx_3 = %f \nVielfachheit = %d", x_1, x_1_vielfachheit, x_2, x_2_vielfachheit, x_3, x_3_vielfachheit);
    }
    printf("\n\n");
    return 0;
}
