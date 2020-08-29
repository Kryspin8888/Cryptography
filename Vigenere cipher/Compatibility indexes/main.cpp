#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

int main()
{
    std::ifstream plik("tekst_Vigenere_zaszyfrowany.txt");
    if( !plik.good() )
         std::cout<<"Nie mozna otworzyc pliku "<<std::endl;
std::cout<<"Zaszyfrowany tekst to "<<std::endl<<std::endl;
char* jawny = (char*)std::malloc(1064*sizeof(int));
int i=0,x,c,f=0,g=0;
int litery[25];
float wsp=0;
    while( true )
    {   plik >> jawny[i];
        if( plik.good() )
            {std::cout<<jawny[i];
            i++;}
        else
             break;
}
std::cout<<std::endl<<std::endl;
std::cout<<"Dlugosc tekstu wynosi : "<<i;
std::cout<<std::endl<<std::endl;
std::cout<<"Na ile kolumn chcesz podzielic szyfrogram ? "<<std::endl;
std::cin>>x;
int liter[25][x+1];
std::cout<<std::endl<<std::endl;
for(int b=0; b<26; b++)
     {litery[b]=0;}
while(g<x)
{std::cout<<"Kolumna "<<g<<std::endl;
    for(int j=0+g; j<i; j=j+x)
    { c=(int)jawny[j];
    litery[c-97]++;
    std::cout<<jawny[j];
    f++;}
std::cout<<std::endl<<std::endl;
std::cout<<"Zliczona czestosc liter : "<<std::endl;
for(int k=0;k<26;k++)
    std::cout<<litery[k]<<" ";
std::cout<<std::endl<<std::endl;
for(int d=0;d<26;d++)
    wsp=wsp+(litery[d]*(litery[d]-1));
std::cout<<"Wspolczynnik zgodnosci dla "<<g<<" kolumny :"<<std::endl;
std::cout<<wsp/(f*(f-1));
std::cout<<std::endl<<std::endl<<std::endl<<std::endl;
for(int b=0; b<26; b++)
     litery[b]=0;
g++; f=0; wsp=0;
}


char h;
std::cout<<"Czy ten podzial ci odpowiada ? Wpisz 't' jesli tak lub 'n' jesli nie :"<<std::endl;
std::cin>>h;
if(h=='n')
    {std::cout<<"By wybrac inny podzial na kolumny uruchom program ponownie"<<std::endl; exit(0);}
else if(h=='t')
{
    g=0; int dl[x];
    std::cout<<std::endl;
for(int l=0; l<26; l++)
    for(int r=0; r<x+1; r++)
     {liter[l][r]=0;}
for(int l=0; l<x; l++)
        dl[l]=0;
while(g<x)
{std::cout<<"Kolumna "<<g<<std::endl;
    for(int m=0+g; m<i; m=m+x)
    { c=(int)jawny[m];
    liter[c-97][g]++;
    dl[g]++;}
std::cout<<std::endl;
std::cout<<"Zliczona czestosc liter : "<<std::endl;
for(int n=0;n<26;n++)
    std::cout<<liter[n][g]<<" ";
std::cout<<std::endl<<std::endl;
std::cout<<std::endl<<std::endl<<std::endl;
g++;
}
std::cout<<"Wspolczynniki koincydencji miedzy kolumnami :"<<std::endl<<std::endl;
float wspk=0; g=0;
while(g<x-1){
for(int s=0; s<26; s++)
 wspk=wspk+(liter[s][g]*liter[s][g+1]);
std::cout<<"Wspolczynnik miedzy kolumnami : "<<g<<" a "<<g+1<<" wynosi "<<(wspk)/(dl[g]*dl[g+1])<<std::endl;
g++; wspk=0;
}
g=0;
for(int s=0; s<26; s++)
 wspk=wspk+(liter[s][0]*liter[s][x-1]);

std::cout<<"Wspolczynnik miedzy kolumnami : "<<0<<" a "<<x-1<<" wynosi "<<(wspk)/(dl[0]*dl[x-1])<<std::endl;
}
else std::cout<<"Wpisales zla litere uruchom program ponownie"<<std::endl;

std::free(jawny);
plik.close();
system("pause");
return EXIT_SUCCESS;
}

