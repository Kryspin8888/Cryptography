#include <iostream>
#include <cmath>

using namespace std;

unsigned long long szybk_pot_modulo(unsigned long long a, unsigned long long b, unsigned long long c);
bool czypierwsza(int liczba1);
int dzielniki_pierwsze(int n,int * tab);

int main()
{
    unsigned long long n,j,t,r,k,a,c1,c2, t_odsz;
    int *tab_dzielnikow=new int[100];
    cout << "Wprowadz n < 32 000: " << endl;
    cin>>n;
    cout << "Wprowadz r: " << endl;
    cin>>r;
    cout << "Wprowadz k: " << endl;
    cin>>k;
    cout << "Wprowadz j: " << endl;
    cin>>j;
    cout << "Wprowadz t: " << endl;
    cin>>t;

    if(!czypierwsza(n))                                         //kontrola bledow
    {
        cout<<endl<<"Liczba n nie jest pierwsza: "<<endl;
        return 1;
    }

    if(r<=1 || r>=n-1)                                         //kontrola bledow
    {
        cout<<endl<<"Liczba r podana ze zlego przedzialu: "<<endl;
        return 1;
    }
    if(k<=1 || k>=n-1)                                         //kontrola bledow
    {
        cout<<endl<<"Liczba k podana ze zlego przedzialu: "<<endl;
        return 1;
    }
    if(t>=n)                                         //kontrola bledow
    {
        cout<<endl<<"Liczba t podana ze zlego przedzialu: "<<endl;
        return 1;
    }
    if(n>=32000)                                         //kontrola bledow
    {
        cout<<endl<<"Liczba n jest za duza: "<<endl;
        return 1;
    }

    dzielniki_pierwsze(n-1,tab_dzielnikow);

    cout<<endl<<"Dzielniki n-1: "<<endl;

    for(int i=0;tab_dzielnikow[i]!=0;i++)              //kontrola bledow
        {
            cout<<tab_dzielnikow[i]<<" ";
            if(szybk_pot_modulo(r,(n-1)/tab_dzielnikow[i],n)==1)
               {
                cout<<endl<<endl<<"Liczba r nie jest pierwiastkiem pierowtnym n: "<<endl;
                return 1;
               }
        }
        cout<<endl;

    a=szybk_pot_modulo(r,k,n);

    cout <<endl<< "Klucz publiczny (n,r,a) to: (" <<n<<","<<r<<","<<a<<")"<< endl<<endl;
    cout << "Klucz prywatny (n,r,a,k) to: (" <<n<<","<<r<<","<<a<<","<<k<<")"<< endl<<endl;

    c1=szybk_pot_modulo(r,j,n);
    c2=szybk_pot_modulo(a,j,n)*t%n;

    cout << "Szyfrogram (c1,c2) to: (" <<c1<<","<<c2<<")"<< endl<<endl;

    t_odsz=szybk_pot_modulo(c1,n-1-k,n)*c2%n;

    cout << "Tekst odszyfrowany to: "<<t_odsz<< endl<<endl;

    return 0;
}

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

bool czypierwsza(int liczba1)
{
   for(int i=2; i<=sqrt(liczba1); ++i)
        if(liczba1%i==0)
        return false;

    return true;

}

int dzielniki_pierwsze(int n, int tab[100])
{
    int pierw, pom,i=0;


        pierw = sqrt(n);

        int k=2;

 while(n>1&&k<=pierw)
        {
                while(n%k==0)
                {
                        tab[i]=k;
                        n/=k;
                        i++;
                }
                ++k;
        }
        if(n>1)
               tab[i]=n;

        return *tab;

}
