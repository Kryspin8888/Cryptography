#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

int main()
{
    std::ifstream plik("tekst_Vigenere2.txt");
    if( !plik.good() )
         std::cout<<"Nie mozna otworzyc pliku "<<std::endl;
std::cout<<"Tekst to : "<<std::endl<<std::endl;
char* jawny = (char*)std::malloc(1000*sizeof(int));
int i=0;
    while( true )
    {
        plik >> jawny[i];
        if( plik.good() )
            {std::cout<<jawny[i];
            i++;}
        else
             break;
}
char* klucz = (char*)std::malloc(30*sizeof(int));
std::cout<<std::endl<<std::endl;
std::cout<<"Podaj klucz do 30 znakow "<<std::endl;
std::cin>>klucz;
int dlklucza=strlen(klucz);
std::cout<<"Dlugosc twojego klucza to :"<<dlklucza<<std::endl;
std::cout<<"Twoj klucz to : "<<klucz<<std::endl;
int t=0,j=0,k;
std::fstream newfile("tekst_Vigenere_zaszyfrowany.txt");
fopen("tekst_Vigenere_zaszyfrowany.txt","w");
for(j=0; j<i; j++)
{
k=((klucz[t]+jawny[j]-2*'a')%26);
newfile<<(char)(k+'a');
if(t<dlklucza-1) t++; else t=0;
}
std::cout<<"Zaszyfrowany tekst zostal zapisany w pliku tekst_Vigenere_zaszyfrowany :"<<std::endl;
std::free(klucz);
std::free(jawny);
newfile.close();
plik.close();
return 0;
}

