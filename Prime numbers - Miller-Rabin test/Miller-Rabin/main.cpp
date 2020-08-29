#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;



unsigned long long szybk_pot_modulo(unsigned long long a, unsigned long long b, unsigned long long c)
{
unsigned long long wynik = 1;
unsigned long long x = a%c;

for (unsigned long long i=1; i<=b; i<<=1)    // binarne przesuniecie w lewo o jedeno miejsce
    {
    x %= c;
    if ((b&i) != 0)      // iloczyn bitowy rozny od zera
        {
        wynik *= x;
        wynik %= c;
        }
    x *= x;
    }

return wynik;
}

int test_Millera_Rabina(unsigned long long n,unsigned long long q, int k)
{
unsigned long long rozkl1 = 0;
unsigned long long rozkl2 = 1;
unsigned long long d;
int rezultat;

srand(time(NULL));

if (n<4)
    {
    return 1;
    }

while ((rozkl2 & (n-1)) == 0)
    {
    rozkl1  += 1;
    rozkl2 <<= 1;
    }

d = n/rozkl2;

if(k>=1)
    if (szybk_pot_modulo(q, d, n) != 1)
        {
        rezultat = 0;

        for (unsigned long long r=0; r<=rozkl1-1; r++)
            {
            cout<<endl<<szybk_pot_modulo(q, pow(2,r)*d, n)<<" (mod "<<n<<")"<<endl;
            if (szybk_pot_modulo(q, pow(2,r)*d, n) == n - 1)
                {
                rezultat = 1;
                break;
                }
            }

        if (rezultat == 0)
            {
            return 0;
            }
        }

if(k!=1){
cout<<endl<<"Elementy ciagu dla losowych q:"<<endl;
for (unsigned long long i=0; i<k; i++)
    {
    q = 1+(int) ((n-1)*rand()/(RAND_MAX+1.0));
    cout<<endl<<" Dla q = "<<q<<endl;
    if (szybk_pot_modulo(q, d, n) != 1)
        {
        rezultat = 0;

        for (unsigned long long r=0; r<=rozkl1-1; r++)
            {
            cout<<endl<<szybk_pot_modulo(q, pow(2,r)*d, n)<<" (mod "<<n<<")"<<endl;
            if (szybk_pot_modulo(q, pow(2,r)*d, n) == n - 1)
                {
                rezultat = 1;
                break;
                }
            }

        if (rezultat == 0)
            {
            return 0;
            }
        }}}


return 1;
}

int main()
{
unsigned long long g,e;
int f;

do
{
cout<<"Podaj liczbe nieparzysta do sprawdzenia: "<<endl;
cin>>g;
} while(g%2==0);

cout<<"Podaj pierwsza wartosc q: "<<endl;
cin>>e;

cout<<endl<<"Podaj dokladnosc sprawdzenia (dla ilu wartosci q chcesz wykonac test): "<<endl;
cout<<"Jesli podasz 1 to sprawdzenie zostanie wykonane tylko dla podanej przez ciebie wartosci q"<<endl;
cout<<"Jesli podasz wiecej niz 1 to sprawdzenie zostanie dodatkowo wykonane dla roznych wartosci losowych q"<<endl;
cin>>f;

cout<<endl<<"Kolejne elementy ciagu: "<<endl;

if (test_Millera_Rabina(g,e,f) == 1)
    {
        if(f==1)
            cout<<endl<<"Liczba jest prawdopodobnie pierwsza  (z prawdopodobienstwem okolo 75%)"<<endl;
        else if (f>1)
            cout<<endl<<"Liczba jest prawdopodobnie pierwsza  (z duzym prawdopodobienstwem wiekszym niz 75%)"<<endl;
    }
else
    {
    cout<<endl<<"Liczba jest zlozona "<<endl;
    }

return 0;
}
