#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

int dzielniki[100]={0};
int krotnosci[100]={0};
int i=1;

unsigned long long szybk_pot_modulo(short a, int b, short c);
bool czypierwsza(int liczba1);
void fermat(int d);


int main()
{   int a, k, rozkl2,q, zlicz=0,n;
    cout << "Podaj n :" << endl;
    cin>>n;

    cout << "Podaj q :" << endl;
    cin>>q;

    a=n-1;

int d1;

k = 0;
    rozkl2 = 1;
    while ((rozkl2 & (a)) == 0)
    {
    k  += 1;
    rozkl2 <<= 1;
    }
d1 = a/rozkl2;

cout<<endl<<"Liczba n-1 w postaci 2^k * d :"<<endl;

cout<<endl<<"n-1 = "<<2<<"^"<<k<<" * "<<d1<<endl<<endl;

dzielniki[0]=2; krotnosci[0]=k;

fermat(d1);

for(int k=0;k<100; k++)
for(int l=0;l<100; l++)
{
    if(dzielniki[k]==dzielniki[l] && dzielniki[k]!=0 && l>k )
    {
        krotnosci[k]++;
        dzielniki[l]=-1;

    }
}

cout<<endl<<"Dzielniki liczby :"<<endl;
int m=0;
if(k==0) m=1;

while (dzielniki[m]!=0 && dzielniki[m]!=-1 && m<100)
{
    cout<<dzielniki[m]<<" ";
    zlicz++;
    m++;
}
cout<<endl<<endl;

int wynik;
bool rezultat=false, rezultat1=true;

if(k!=0)
{
wynik=szybk_pot_modulo(q,a,n);
    cout<<q<<"^"<<a<<" = "<<wynik<<" (mod "<<n<<")"<<endl;
if(wynik==1) rezultat=true;

for(int i=0; i<zlicz; i++ )
{
    wynik=szybk_pot_modulo(q,a/dzielniki[i],n);
    cout<<q<<"^("<<a<<" / "<<dzielniki[i]<<") = "<<wynik<<" (mod "<<n<<")"<<endl;
    if(wynik==1) rezultat1=false;
}
cout<<endl;
if(rezultat==1 && rezultat1==1) cout<<"Liczba "<<n<<" jest pierwsza";
else cout<<"Test nie rozstrzyga czy liczba "<<n<<" jest pierwsza";
}


else

{
    wynik=szybk_pot_modulo(q,a,n);
    cout<<q<<"^"<<a<<" = "<<wynik<<" (mod "<<n<<")"<<endl;
if(wynik==1) rezultat=true;

for(int i=1; i<zlicz+1; i++ )
{
    wynik=szybk_pot_modulo(q,a/dzielniki[i],n);
    cout<<q<<"^("<<a<<" / "<<dzielniki[i]<<") = "<<wynik<<" (mod "<<n<<")"<<endl;
    if(wynik==1) rezultat1=false;
}
cout<<endl;
if(rezultat==1 && rezultat1==1) cout<<"Liczba "<<n<<" jest pierwsza";
else cout<<"Test nie rozstrzyga czy liczba "<<n<<" jest pierwsza";

}

cout<<endl<<endl;
return 0;
}


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

bool czypierwsza(int liczba1)
{
   for(int i=2; i<=sqrt(liczba1); ++i)
        if(liczba1%i==0)
        return false;

    return true;

}

void fermat(int d)
{
int x,y;

x=floor(sqrt(d));
if(x==sqrt(d)) {dzielniki[i]=x; krotnosci[i]=2; i++; }
else x=x+1;

do
{
    y=x*x-d;

    if(y>0 && floor(sqrt(y))==sqrt(y) )
    {
      if (!(czypierwsza(x+sqrt(y))))
              {
                 fermat(x+sqrt(y));
              }
      else
              {
                  dzielniki[i]=x+sqrt(y);
                  krotnosci[i]=1;
                  i++;
              }
      if(!(czypierwsza(x-sqrt(y))))
            {
                fermat(x-sqrt(y));
            }
      else
            {
               dzielniki[i]=x-sqrt(y);
               krotnosci[i]=1;
               i++;
            }
      break;
    }

    else x=x+1;

} while(x<(d+1)/2);

}
