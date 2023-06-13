/*
 * Programmieren fuer Physiker, SS 2023, Blatt 8, Aufgabe 20
 *
 * Klasse fuer Rechteck
 */

#include <iostream>
using namespace std;

// Zu implementieren: Klasse Rechteck mit den
// drei Methoden setze, rotation und bedeckt
class rechteck
{
    // private:

    protected:
    double breite;
    double höhe;

    public:
    void setze(double b, double h)
    {
        breite = b;
        höhe = h;
    }
    void rotation()
    {
        double b = breite;
        breite = höhe;
        höhe = b;
    }
    bool bedeckt(rechteck r)
    {
        bool result = false;
        if (höhe >= r.höhe and breite >= r.breite)
        {
            result = true;
        }
        return result;
    }
};

// gegebenes Hauptprogramm
int main()
{
    cout << "Klasse für Rechtecke" << endl;
    rechteck r1, r2;
    r1.setze(3.3, 2.0);
    r2.setze(1.8, 2.7);

    cout << "Vor Rotation: ";
    if (r1.bedeckt(r2))
        cout << "r1 bedeckt r2.";
    else
        cout << "r1 bedeckt r2 nicht.";
    cout << endl;

    r2.rotation();

    cout << "Nach Rotation: ";
    if (r1.bedeckt(r2))
        cout << "r1 bedeckt r2.";
    else
        cout << "r1 bedeckt r2 nicht.";
    cout << endl;

    return 0;
}
