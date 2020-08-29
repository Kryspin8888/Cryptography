#include <iostream>
#include <cstdlib>

using namespace std;

unsigned long long szybk_pot_modulo(short a, int b, short c)
{
unsigned long long wynik = 1;
long int x = a%c;

for (int i=1; i<=b; i<<=1)   // binarne przesuniecie w lewo o jedeno miejsce
    {
    x %= c;
    if ((b&i) != 0)        // iloczyn bitowy rozny od zera
        {
        wynik *= x;
        wynik %= c;
        }
    x *= x;
    }

return wynik;
}



int main(void)
{
short d,f;
int e;

cout<<"OBLICZANIE WYRAZENIA a^b mod c :"<<endl<<endl;
cout<<"Podaj wspolczynnik a  (<32 000) :"<<endl;
cin>>d;
cout<<"Podaj wspolczynnik b  (<2 000 000 000):"<<endl;
cin>>e;
cout<<"Podaj wspolczynnik c  (<32 000) :"<<endl;
cin>>f;

cout<<endl<<"WYNIK DZIALANIA "<<d<<"^"<<e<<" mod "<<f<<" to :  "<<szybk_pot_modulo(d,e,f)<<endl<<endl;

system("pause");
return 0;
}
