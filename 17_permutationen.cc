/*
 * Programmieren fuer Physiker, SS 2023, Blatt 7, Aufgabe 17
 *
 * Permutationen in lexikographischer Ordnung generieren
 */

#include <iostream>
using namespace std;

void swap(char &a, char &b)
{
    char c = b;
    b = a;
    a = c;
}

bool next_permutation(char wort[], int size)
{
    // P1
    int k = size - 2;
    while (wort[k] >= wort[k + 1])
    {
        k--;
        if (k < 0)
        {
            return false;
        }
    }

    // P2
    int l = size - 1;
    while (wort[k] >= wort[l])
    {
        l--;
    }

    // P3
    swap(wort[k], wort[l]);

    // P4
    int start = k + 1;
    int end = size - 1;
    int difference = (end - start) / 2;
    for (int i = 0; i <= difference; i++)
    {
        swap(wort[start + i], wort[end - i]);
    }
    return true;
}

int main()
{
    // Beispieldatensatz, muss sortiert vorliegen
    const int size = 6;
    char wort[size] = {'A', 'E', 'E', 'F', 'F', 'K'};

    cout << "Generierung aller Permutationen" << endl
         << endl;

    // Hauptschleife, erzeuge alle Permutationen
    int anzperm = 0; // zaehle die Permutationen
    do
    {
        ++anzperm;
        cout << "Nr: " << anzperm << "  ";
        for (int i = 0; i < size; i++)
            cout << wort[i] << " ";
        cout << endl;
    } while (next_permutation(wort, size));

    cout << "Anzahl der Permutationen: " << anzperm << endl;

    return 0;
}
