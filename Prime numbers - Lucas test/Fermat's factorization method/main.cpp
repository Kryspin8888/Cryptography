#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

int dzielniki[100]={0};
int krotnosci[100]={0};
int i=1;

bool czypierwsza(int liczba1);
void fermat(int d);

int main()
{   int a, k, rozkl2;
    cout << "Podaj a :" << endl;
    cin>>a;

if (czypierwsza(a))
{
cout<<endl<<"Liczba jest pierwsza "<<endl<<endl;
exit(0);
}

int d1;

k = 0;
    rozkl2 = 1;
    while ((rozkl2 & (a)) == 0)
    {
    k  += 1;
    rozkl2 <<= 1;
    }
d1 = a/rozkl2;

cout<<endl<<"Liczba a w postaci 2^k * d :"<<endl;

cout<<endl<<"a = "<<2<<"^"<<k<<" * "<<d1<<endl<<endl;

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
    m++;
}

cout<<endl<<endl<<"Krotnosci dzielnikow :"<<endl;
m=0;
if(k==0)m=1;
while (dzielniki[m]!=0 && dzielniki[m]!=-1 && m<100)
{
    cout<<krotnosci[m]<<" ";
    m++;
}
cout<<endl<<endl;
return 0;
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
