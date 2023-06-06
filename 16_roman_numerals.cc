#include <iostream>
#include <cstring>
using namespace std;


char to_upper(char ch)
{
    if (ch>='a' and ch<='z'){
        return char(int(ch)-int('a')+int('A'));
    }
    else{
        return ch;
    }
}

int value_roman_char( char ch) 
{
    const int nr_rm_letters = 7 ;
    const char letter[nr_rm_letters] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'} ;
    const int  value[nr_rm_letters]  = {  1,   5,  10,  50, 100, 500, 1000} ;
    for (int i=0; i<nr_rm_letters; ++i)
	if (to_upper(ch) == letter[i])
	    return value[i] ;
    cout << "Unbekanntes roemisches Zahlzeichen: " << ch << endl ;
    return 0 ; 
}

int main()
{
    char rm_string[40] ;  // unschoen, feste Maximallaenge
    cout << "Roemisch -> Arabisch" << endl ;
    cout << "Bitte roemische Zahl eingeben: " ;
    cin >> rm_string ;

    int sum = 0 ;
    int len = strlen(rm_string) ;
    for( int i=0; i<len; ++i)
    {
	int val = value_roman_char(rm_string[i]) ;
	if (i<len-1)  // wichtig!
	    if (val < value_roman_char(rm_string[i+1]))
		val *= -1 ;  // eventuell negativen Wert nehmen
	sum += val ;
    }
    cout << "Das ist im Dezimalsystem: " << sum << endl ;
}