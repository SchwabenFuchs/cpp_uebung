#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> parse_to_token(string s, string delimiter)
{
    size_t pos = 0;
    vector<string> tokens;
    while ((pos = s.find(delimiter)) != std::string::npos)
    {
        string token = s.substr(0, pos);
        tokens.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    return tokens;
}

int main()
{
    int teilnehmernummern[8];
    double weiten[8][6];
    double weiten_beste[8];
    string delimiter = "  ";
    ifstream Weitsprung_File("a11-weitsprung.txt");
    int i = 0;
    for (string line; getline(Weitsprung_File, line);)
    {
        auto tokens = parse_to_token(line, delimiter);
        teilnehmernummern[i] = stoi(tokens[0]);
        for (int n = 0; n < 6; n++)
        {
            weiten[i][n] = stod(tokens[n + 1]);
        }
        i++;
    }
    double weite_max;
    for (int i = 0; i < 8; i++)
    {
        weite_max = 0;
        for (int n = 0; n < 6; n++)
        {
            double weite_aktuell = weiten[i][n];
            if (weite_aktuell > weite_max)
            {
                weite_max = weite_aktuell;
            }
        }
        weiten_beste[i] = weite_max;
    }
    double weiten_beste_max = 0;
    for (int i = 0; i < 8; i++)
    {
        double weite_aktuell = weiten_beste[i];
        if (weite_aktuell > weiten_beste_max)
        {
            weiten_beste_max = weite_aktuell;
        }
    }
    string weiten_beste_nummer [8] {};
    for (int i = 0; i < 8; i++){
        if (weiten_beste[i] == weiten_beste_max){
            weiten_beste_nummer[i] = "Champion";
        }
        else {
            weiten_beste_nummer[i] = ' ';
        }
    }
    printf("Teilnehmernummer 1.   2.   3.   4.   5.   6.   beste   Gewinner \n");
    for (int i=0; i<8; i++){
        printf("%i             ", teilnehmernummern[i]);
        for (int n=0; n<6; n++){
            printf("%.2f ", weiten[i][n]);
        }
        printf("%.2f    ", weiten_beste[i]);
        cout << weiten_beste_nummer[i];
        printf("\n");
    }

    printf("\n\n");
    return 0;
}
