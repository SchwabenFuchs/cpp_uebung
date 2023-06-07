#include <iostream>
using namespace std;

const int max_input = 100;

struct minsek
{
    int min;
    int sek;
} typedef minsek;

minsek enter_time()
{
    minsek time;
    cout << "Please enter time in the format mm ss.\n";
    cin >> time.min >> time.sek;
    return time;
}

void print_time(minsek time){
    cout << time.min << ":" << time.sek;
}

minsek add_time(minsek time_1, minsek time_2){
    minsek time_3;
    time_3.min = 0;
    time_3.sek = time_1.sek + time_2.sek;
    if (time_3.sek >= 60){
        time_3.sek += -60;
        time_3.min += 1;
    }
    time_3.min += time_1.min + time_2.min;
    return time_3;
}

int main()
{
    minsek time_1 = enter_time();
    cout << "\n";
    minsek time_2 = enter_time();
    cout << "\nAdded time:\n";
    print_time(add_time(time_1, time_2));

    cout << "\n\n";
    return 0;
}
