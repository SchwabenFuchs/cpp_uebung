#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include "a7-kubisch-fragment.cc"
using namespace std;

float pi = 3.141;

struct Wert_Vielfachheit {
    vector <double> Wert;
    vector <int> Vielfachheit;
} typedef Wert_Vielfachheit;


Wert_Vielfachheit compute_roots(double a,double b,double c,double d)
{   
    Wert_Vielfachheit x_roots; 
    double p, q, D;
    p = (3 * a * c - pow(b, 2)) / (3 * pow(a, 2));
    q = 2 * pow(b, 3) / (27 * pow(a, 3)) - b * c / (3 * pow(a, 2)) + d / a;
    D = pow((q / 2), 2) + pow((p / 3), 3);

    int x_1_vielfachheit, x_2_vielfachheit, x_3_vielfachheit;
    double x_1, x_2, x_3;
    vector <double> x;
    vector <int> x_vielfachheit;

    if (D > 0)
    {
        x_1_vielfachheit = 1;
        x_1 = cubicroot(-q / 2 - sqrt(D)) + cubicroot(-q / 2 + sqrt(D)) - b / (3 * a);
        x_vielfachheit.push_back(x_1_vielfachheit);
        x.push_back(x_1);
    }
    else if (D == 0)
    {
        if (q == 0)
        {
            x_1_vielfachheit = 3;
            x_1 = -b / (3 * a);
            x_vielfachheit.push_back(x_1_vielfachheit);
            x.push_back(x_1);
        }
        else
        {
            x_1_vielfachheit = 2;
            x_1 = cubicroot(q / 2) - b / (3 * a);
            x_2_vielfachheit = 1;
            x_2 = cubicroot(-4 * q) - b / (3 * a);
            x_vielfachheit.insert(x_vielfachheit.end(), {x_1_vielfachheit, x_2_vielfachheit});
            x.insert(x.end(), {x_1, x_2});
        }
    }
    else if (D < 0){
        double h = acos(-q/2 * sqrt(-27/pow(p, 3)));
        x_1_vielfachheit = 1;
        x_1 = -sqrt(-4*p/3) * cos(h/3 - pi/3) - b/(3*a);
        x_2_vielfachheit = 1;
        x_2 = -sqrt(-4*p/3) * cos(h/3 + pi/3) - b/(3*a);
        x_3_vielfachheit = 1;
        x_3 = sqrt(-4*p/3) * cos(h/3) - b/(3*a);
        x_vielfachheit.insert(x_vielfachheit.end(), {x_1_vielfachheit, x_2_vielfachheit, x_3_vielfachheit});
        x.insert(x.end(), {x_1, x_2, x_3});
    }
    x_roots.Vielfachheit = x_vielfachheit;
    x_roots.Wert = x;
    return x_roots;
}


int main()
/*computes roots of cubic equation; uses data type vector*/
{
    double a, b, c, d;
    printf("This program calculates the roots of a 3. order polynomial equation of the form f(x) = a*x^3 + b*x^2 + c*x + d.\nInput the parameters.\na: ");
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
    cout << "d: ";
    cin >> d;

    printf("\n%+.2f*x^3 %+.2f*x^2 %+.2f*x %+.2f = 0 \n\n", a, b, c, d);

    auto x_roots = compute_roots(a, b, c, d);

    printf("\n\n");

    int i=0;
    for (auto x: x_roots.Wert){
        printf("x = %f \n", x);
        printf("Vielfachheit: %d \n\n", x_roots.Vielfachheit[i]);
        i++;
    }

    printf("\n\n");
    return 0;
}
