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

int main()
{int t,N;
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

    for(i = 0; i < k; i++)
    {if(pom==0)
    {
        if(i==t-1)
        cout<<endl<<"Dla i = "<<tablica[i]<<endl;
    if(i==N-1)
        cout<<endl<<"Dla j = "<<tablica[i]<<endl;
    }
    else
    {
    if(i==N-1)
        cout<<endl<<"Dla i = "<<tablica[i]<<endl;
    if(i==t-1)
        cout<<endl<<"Dla j = "<<tablica[i]<<endl;
    }
    }

  cout << endl << endl
       << "Zakres liczb pierwszych od 2 do " << N*15 << endl;

return 0;
}
