#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void sito_Erastotenesa(bool *pomtab,int koniec,int n)
{int i,j;
for(i = 2; i <= koniec; i++)
    if(pomtab[i])
    {
      j = i + i;
      while(j <= n)
      {
        pomtab[j] = false;
        j += i;
      }
    }
}
int m1=0, mpom=0, r3=0, rpom=1, nwdpom=0, wynik;

void Euklides(int a, int b)
{
if(b==0)
    {
    nwdpom=a;
    r3=a;
    return;
    }
else
    Euklides(b,a%b);

wynik=mpom;
int t=mpom;
mpom=(rpom-floor(a/b)*mpom);
m1=b;
rpom=t;
r3=a;
}

int main()
{int t,N,e;
    cout<<"Podaj i:"<<endl;
cin>>t;
cout<<endl<<"Podaj j:"<<endl;
cin>>N;

int pom=0;

if (t>N)
{
    pom=t;
    t=N;
    N=pom;
}
    int i,j;

    bool tab[N*15+1];
   int koniec1=sqrt(N*15);
   int * tablica = new int[N*15];
   int k=0;

    for( i = 2; i <= N*15; i++) tab[i] = true;

    sito_Erastotenesa(tab,koniec1,N*15);

    for(i = 2; i <= N*15; i++)
    if(tab[i])
    {
        tablica[k]=i;
        k++;
    }

int p,q;

    for(i = 0; i < k; i++)
    {if(pom==0)
    {
        if(i==t-1)
        {p=tablica[i];
        cout<<endl<<"Twoje p = "<<p<<endl;}
    if(i==N-1){
            q=tablica[i];
        cout<<endl<<"Twoje q = "<<q<<endl;}
    }
    else
    {
    if(i==N-1){
            p=tablica[i];
        cout<<endl<<"Twoje p = "<<p<<endl;}
    if(i==t-1){
            q=tablica[i];
        cout<<endl<<"Twoje q = "<<q<<endl;}
    }
    }

int n=p*q;
int m=(p-1)*(q-1);

cout<<endl<<"n : "<<n<<endl<<endl;
cout<<"m : "<<m<<endl<<endl;

cout<<endl<<"Podaj liczbe losowa e taka ze NWD(e,m)=1 :"<<endl;
cin>>e;
cout<<endl;

Euklides(e,m);

cout<<"d : "<<wynik<<endl<<endl;

while(wynik<=0)
{wynik=wynik+m;
cout<<"d : "<<wynik<<endl<<endl;}

cout<<"Klucz publiczny to : "<<n<<"  "<<e<<endl<<endl;
cout<<"Klucz prywatny to : "<<n<<"  "<<wynik<<endl<<endl;

return 0;
}
