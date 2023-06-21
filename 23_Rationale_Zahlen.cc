#include <iostream>

using namespace std;

class Ratio
{
private:
    long int zähler, nenner;
    void kürzen();

    // protected:

public:
    Ratio(long a, long b);
    Ratio operator+(Ratio zahl);
    Ratio operator-(Ratio zahl);
    Ratio operator*(Ratio zahl);
    Ratio operator/(Ratio zahl);
    Ratio operator-(); // unitary minus
    double to_decimal();
    operator double();
    void print_out();
};

void Ratio::kürzen()
{
    // find greatest common Divider
    long int a = abs(zähler);
    long int b = abs(nenner);
    while (b != 0)
    {
        long int h = a % b;
        a = b;
        b = h;
    }

    // a is the gcDivider
    zähler = zähler / a;
    nenner = nenner / a;

    // move minus sign to zähler
    if (nenner < 0)
    {
        zähler *= -1;
        nenner *= -1;
    }
}

Ratio::Ratio(long a = 0, long b = 3)
{
    zähler = a;
    nenner = b;
    if (nenner == 0)
        cout << "\nDenominator can not be 0!\n";
    kürzen();
}

Ratio Ratio::operator+(Ratio zahl)
{
    Ratio result;
    result.zähler = zähler * zahl.nenner + zahl.zähler * nenner;
    result.nenner = nenner * zahl.nenner;
    result.kürzen();
    return result;
}

Ratio Ratio::operator-()
{
    // uniary minus sign
    return Ratio(-zähler, nenner);
}

Ratio Ratio::operator-(Ratio zahl)
{
    Ratio result = operator+(-zahl);
    return result; // shortening happens in operator+ method
}

Ratio Ratio::operator*(Ratio zahl)
{
    Ratio result;
    result.zähler = zähler * zahl.zähler;
    result.nenner = nenner * zahl.nenner;
    result.kürzen();
    return result;
}

Ratio Ratio::operator/(Ratio zahl)
{
    return Ratio(zähler * zahl.nenner, nenner * zahl.zähler);
}

void Ratio::print_out()
{
    cout << "\n"
         << zähler << "/" << nenner << "\n";
}

double Ratio::to_decimal()
{
    return double(zähler) / double(nenner);
}

Ratio::operator double()
{
    return double(zähler) / double(nenner);
}

int main()
{
    Ratio a(1, 2);
    Ratio b(-2, 3);
    Ratio c = a + b;

    cout << "Trying out stuff:";
    c.print_out();
    cout << "=" << c.to_decimal() << endl;
    cout << "=" << double(c) << endl;
    cout << "\n\n";

    Ratio d;
    cout << "default Ratio:";
    d.print_out();
    cout << "\n\n";
    Ratio calculation = Ratio(2, 15) / Ratio(7, 5) + Ratio(3, 7) * (-Ratio(1, 2) + Ratio(1, 3));
    cout << "Calculation:";
    calculation.print_out();
    cout << "=" << double(calculation);

    cout << "\n\n";
    return 0;
}
