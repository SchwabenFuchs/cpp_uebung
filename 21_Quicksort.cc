#include <iostream>
#include <cstdlib>

using namespace std;

void Swap(double &a, double &b)
{
    double c = a;
    a = b;
    b = c;
}

int Partition(double list[], const int s, const int t)
{
    double pivot = list[s];
    int l = s;
    for (int i = s + 1; i <= t; i++)
    {
        if (list[i] < pivot)
        // to reverse the ordering to falling instead of rising: change to >
        {
            l++;
            Swap(list[i], list[l]);
        }
    }
    Swap(list[s], list[l]);
    cout << endl << l << endl;
    return l;
}

void QuickSort(double list[], const int s, const int t)
{
    // recursive sorting by partitioning into 2 parts every step
    // break condition: 1 or less elements to sort
    if (t <= s)
    {
        return;
    }

    // step 1: partitioning
    int pivot_index = Partition(list, s, t);

    // step 2: sort both parts
    QuickSort(list, s, pivot_index - 1);
    QuickSort(list, pivot_index + 1, t);
}

void PrintList(double list[], int size)
{
    cout << "Size: " << size << endl;
    for (int i = 0; i < size; i++)
    {
        cout << list[i] << " ,  ";
    }
}

int main()
{
    const int size = 5;
    double list[size];

    // random double values between 0 and 1
    srand((unsigned int)time(0));
    for (int i = 0; i < size; i++)
    {
        list[i] = rand() / double(RAND_MAX);
    }

    cout << "Unsorted list:" << endl;
    PrintList(list, size);
    cout << "\n\n";

    QuickSort(list, 0, size - 1);

    cout << "Sorted list:" << endl;
    PrintList(list, size);
    cout << "\n\n";

    cout << "\n\n";
    return 0;
}