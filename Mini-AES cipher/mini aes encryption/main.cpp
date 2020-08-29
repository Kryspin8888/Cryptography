#include <iostream>
#include <conio.h>

using namespace std;

int sboxe(int *tab);
int mnoz(int *wynik, int *a, int *b);

int main()
{
char z;
int t[16]={0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1};
int kp[16]={3, 0, 1, 1, 0, 3, 1, 0, 1, 1, 1, 3, 3, 1, 1, 0};

cout<<"*Twoj tekst to: "<<endl;
for(int i=0; i<16; i++)
{ cout<<t[i]<<" ";

}

cout<<endl<<endl<<"*Wprowadz cztery bity A, B, C i D kluczu poczatkowym:"<<endl;
cout<<"A=kp[0] , B=kp[5] , C=kp[11] , D=kp[12] : "<<endl<<endl;

for(int i=0; i<4; i++)
    {                                                                      //wprowadzanie A B C D
    z=getch();
    cout<<z<<endl;
    if(z!=48 && z!=49 ) {cout<<"Zly znak podaj 0 lub 1 "<<endl; i--;}
    if(i==0) kp[0]= (int)z-48;
    if(i==1) kp[5]= (int)z-48;
    if(i==2) kp[11]= (int)z-48;
    if(i==3) kp[12]= (int)z-48;
    }

cout<<endl<<"Twoj klucz poczatkowy to: "<<endl<<endl;
for(int i=0; i<16; i++)
{ cout<<kp[i]<<" ";

}
cout<<endl<<endl;

int k1[16], k2[16], kpom11[4]={kp[12], kp[13], kp[14], kp[15]};          //generacja klucza I rundy
sboxe(kpom11);

k1[0]=(((kpom11[0]+kp[0])%2)+0)%2; k1[1]=(((kpom11[1]+kp[1])%2)+0)%2;
k1[2]=(((kpom11[2]+kp[2])%2)+0)%2; k1[3]=(((kpom11[3]+kp[3])%2)+1)%2;
k1[8]=(k1[0]+kp[8])%2; k1[9]=(k1[1]+kp[9])%2; k1[10]=(k1[2]+kp[10])%2; k1[11]=(k1[3]+kp[11])%2;
k1[4]=(k1[8]+kp[4])%2; k1[5]=(k1[9]+kp[5])%2; k1[6]=(k1[10]+kp[6])%2; k1[7]=(k1[11]+kp[7])%2;
k1[12]=(k1[4]+kp[12])%2; k1[13]=(k1[5]+kp[13])%2; k1[14]=(k1[6]+kp[14])%2; k1[15]=(k1[7]+kp[15])%2;

cout<<"Wygenerowany klucz 1 rundy to: "<<endl<<endl;
for(int i=0; i<16; i++)
 cout<<k1[i]<<" ";

kpom11[0]=k1[12]; kpom11[1]=k1[13]; kpom11[2]=k1[14]; kpom11[3]=k1[15];                 //generacja klucza II rundy

sboxe(kpom11);

k2[0]=(((kpom11[0]+k1[0])%2)+0)%2; k2[1]=(((kpom11[1]+k1[1])%2)+0)%2;
k2[2]=(((kpom11[2]+k1[2])%2)+1)%2; k2[3]=(((kpom11[3]+k1[3])%2)+0)%2;
k2[8]=(k2[0]+k1[8])%2; k2[9]=(k2[1]+k1[9])%2; k2[10]=(k2[2]+k1[10])%2; k2[11]=(k2[3]+k1[11])%2;
k2[4]=(k2[8]+k1[4])%2; k2[5]=(k2[9]+k1[5])%2; k2[6]=(k2[10]+k1[6])%2; k2[7]=(k2[11]+k1[7])%2;
k2[12]=(k2[4]+k1[12])%2; k2[13]=(k2[5]+k1[13])%2; k2[14]=(k2[6]+k1[14])%2; k2[15]=(k2[7]+k1[15])%2;

cout<<endl<<endl<<"Wygenerowany klucz 2 rundy to: "<<endl<<endl;
for(int i=0; i<16; i++)
 cout<<k2[i]<<" ";

int szyfr[16];

cout<<endl<<endl<<"Krok 1 dodanie klucza poczatkowego do tekstu: "<<endl<<endl;
for(int i=0; i<16; i++)
{szyfr[i]=(kp[i]+t[i])%2;      //dodawanie klucza
 cout<<szyfr[i]<<" ";}

int szyfrpom00[4], szyfrpom10[4], szyfrpom01[4], szyfrpom11[4];                //podzial na 4 bity pod sboxa
szyfrpom00[0]=szyfr[0]; szyfrpom00[1]=szyfr[1]; szyfrpom00[2]=szyfr[2]; szyfrpom00[3]=szyfr[3];
szyfrpom10[0]=szyfr[4]; szyfrpom10[1]=szyfr[5]; szyfrpom10[2]=szyfr[6]; szyfrpom10[3]=szyfr[7];
szyfrpom01[0]=szyfr[8]; szyfrpom01[1]=szyfr[9]; szyfrpom01[2]=szyfr[10]; szyfrpom01[3]=szyfr[11];
szyfrpom11[0]=szyfr[12]; szyfrpom11[1]=szyfr[13]; szyfrpom11[2]=szyfr[14]; szyfrpom11[3]=szyfr[15];

sboxe(szyfrpom00); sboxe(szyfrpom10); sboxe(szyfrpom01); sboxe(szyfrpom11);

for(int i=0; i<4; i++)                      //przestawienie ZK
 szyfr[i]=szyfrpom00[i];
for(int i=0; i<4; i++)
 szyfr[i+4]=szyfrpom10[i];
for(int i=0; i<4; i++)
 szyfr[i+12]=szyfrpom01[i];
for(int i=0; i<4; i++)
 szyfr[i+8]=szyfrpom11[i];

cout<<endl<<endl<<"Krok 2 i 3 SBoxE i ZK: "<<endl<<endl;
for(int i=0; i<16; i++)
 cout<<szyfr[i]<<" ";

int m[16]={0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1};
int mpom00[4],mpom10[4],mpom01[4],mpom11[4];
int szyfr1[4],szyfr2[4],szyfr3[4],szyfr4[4],szyfr5[4],szyfr6[4],szyfr7[4],szyfr8[4];
                                                                                                    //podzial pod mnozenie
szyfrpom00[0]=szyfr[0]; szyfrpom00[1]=szyfr[1]; szyfrpom00[2]=szyfr[2]; szyfrpom00[3]=szyfr[3];
szyfrpom10[0]=szyfr[4]; szyfrpom10[1]=szyfr[5]; szyfrpom10[2]=szyfr[6]; szyfrpom10[3]=szyfr[7];
szyfrpom01[0]=szyfr[8]; szyfrpom01[1]=szyfr[9]; szyfrpom01[2]=szyfr[10]; szyfrpom01[3]=szyfr[11];
szyfrpom11[0]=szyfr[12]; szyfrpom11[1]=szyfr[13]; szyfrpom11[2]=szyfr[14]; szyfrpom11[3]=szyfr[15];

mpom00[0]=m[0]; mpom00[1]=m[1]; mpom00[2]=m[2]; mpom00[3]=m[3];
mpom10[0]=m[4]; mpom10[1]=m[5]; mpom10[2]=m[6]; mpom10[3]=m[7];
mpom01[0]=m[8]; mpom01[1]=m[9]; mpom01[2]=m[10]; mpom01[3]=m[11];
mpom11[0]=m[12]; mpom11[1]=m[13]; mpom11[2]=m[14]; mpom11[3]=m[15];

mnoz(szyfr1,szyfrpom00,mpom00);
mnoz(szyfr2,szyfrpom01,mpom10);
mnoz(szyfr3,szyfrpom10,mpom00);
mnoz(szyfr4,szyfrpom11,mpom10);
mnoz(szyfr5,szyfrpom00,mpom01);
mnoz(szyfr6,szyfrpom01,mpom11);
mnoz(szyfr7,szyfrpom10,mpom01);
mnoz(szyfr8,szyfrpom11,mpom11);

szyfr[0]=(szyfr1[0]+szyfr2[0])%2; szyfr[1]=(szyfr1[1]+szyfr2[1])%2;         //dodawanie pomnozonych bitow
szyfr[2]=(szyfr1[2]+szyfr2[2])%2; szyfr[3]=(szyfr1[3]+szyfr2[3])%2;

szyfr[4]=(szyfr3[0]+szyfr4[0])%2; szyfr[5]=(szyfr3[1]+szyfr4[1])%2;
szyfr[6]=(szyfr3[2]+szyfr4[2])%2; szyfr[7]=(szyfr3[3]+szyfr4[3])%2;

szyfr[8]=(szyfr5[0]+szyfr6[0])%2; szyfr[9]=(szyfr5[1]+szyfr6[1])%2;
szyfr[10]=(szyfr5[2]+szyfr6[2])%2; szyfr[11]=(szyfr5[3]+szyfr6[3])%2;

szyfr[12]=(szyfr7[0]+szyfr8[0])%2; szyfr[13]=(szyfr7[1]+szyfr8[1])%2;
szyfr[14]=(szyfr7[2]+szyfr8[2])%2; szyfr[15]=(szyfr7[3]+szyfr8[3])%2;

cout<<endl<<endl<<"Krok 4 mnozenie przez m: "<<endl<<endl;
for(int i=0; i<16; i++)
 cout<<szyfr[i]<<" ";

cout<<endl<<endl<<"Krok 5 dodawanie klucza rundy I: "<<endl<<endl;
for(int i=0; i<16; i++)
 {
     szyfr[i]=(szyfr[i]+k1[i])%2;            //dodawanie klucza I rundy
     cout<<szyfr[i]<<" ";
 }

szyfrpom00[0]=szyfr[0]; szyfrpom00[1]=szyfr[1]; szyfrpom00[2]=szyfr[2]; szyfrpom00[3]=szyfr[3];    //podzial pod sboxa
szyfrpom10[0]=szyfr[4]; szyfrpom10[1]=szyfr[5]; szyfrpom10[2]=szyfr[6]; szyfrpom10[3]=szyfr[7];
szyfrpom01[0]=szyfr[8]; szyfrpom01[1]=szyfr[9]; szyfrpom01[2]=szyfr[10]; szyfrpom01[3]=szyfr[11];
szyfrpom11[0]=szyfr[12]; szyfrpom11[1]=szyfr[13]; szyfrpom11[2]=szyfr[14]; szyfrpom11[3]=szyfr[15];

sboxe(szyfrpom00); sboxe(szyfrpom01); sboxe(szyfrpom10); sboxe(szyfrpom11);

for(int i=0; i<4; i++)                //przestawienie ZK
 szyfr[i]=szyfrpom00[i];
for(int i=0; i<4; i++)
 szyfr[i+4]=szyfrpom10[i];
for(int i=0; i<4; i++)
 szyfr[i+12]=szyfrpom01[i];
for(int i=0; i<4; i++)
 szyfr[i+8]=szyfrpom11[i];

cout<<endl<<endl<<"Krok 6 i 7 SBoxE i ZK: "<<endl<<endl;
for(int i=0; i<16; i++)
 cout<<szyfr[i]<<" ";

cout<<endl<<endl<<"Krok 8 dodawanie klucza rundy II - OTRZYMANY SZYFROGRAM: "<<endl<<endl;
for(int i=0; i<16; i++)
 {
     szyfr[i]=(szyfr[i]+k2[i])%2;          //dodawanie klucza II rundy
     cout<<szyfr[i]<<" ";
 }

cout<<endl<<endl;
return 0;
}


int sboxe(int *tab)
{
      if(tab[0]==0 && tab[1]==0 && tab[2]==0 && tab[3]==0)
      {
          tab[0]=1; tab[1]=1;
          tab[2]=1; tab[3]=0;
      }
      else if(tab[0]==0 && tab[1]==0 && tab[2]==0 && tab[3]==1)
      {
          tab[0]=0; tab[1]=1;
          tab[2]=0; tab[3]=0;
      }
      else if(tab[0]==0 && tab[1]==0 && tab[2]==1 && tab[3]==0)
      {
          tab[0]=1; tab[1]=1;
          tab[2]=0; tab[3]=1;
      }
      else if(tab[0]==0 && tab[1]==0 && tab[2]==1 && tab[3]==1)
      {
          tab[0]=0; tab[1]=0;
          tab[2]=0; tab[3]=1;
      }
      else if(tab[0]==0 && tab[1]==1 && tab[2]==0 && tab[3]==0)
      {
          tab[0]=0; tab[1]=0;
          tab[2]=1; tab[3]=0;
      }
      else if(tab[0]==0 && tab[1]==1 && tab[2]==0 && tab[3]==1)
      {
          tab[0]=1; tab[1]=1;
          tab[2]=1; tab[3]=1;
      }
      else if(tab[0]==0 && tab[1]==1 && tab[2]==1 && tab[3]==0)
      {
          tab[0]=1; tab[1]=0;
          tab[2]=1; tab[3]=1;
      }
      else if(tab[0]==0 && tab[1]==1 && tab[2]==1 && tab[3]==1)
      {
          tab[0]=1; tab[1]=0;
          tab[2]=0; tab[3]=0;
      }
      else if(tab[0]==1 && tab[1]==0 && tab[2]==0 && tab[3]==0)
      {
          tab[0]=0; tab[1]=0;
          tab[2]=1; tab[3]=1;
      }
      else if(tab[0]==1 && tab[1]==0 && tab[2]==0 && tab[3]==1)
      {
          tab[0]=1; tab[1]=0;
          tab[2]=1; tab[3]=0;
      }
      else if(tab[0]==1 && tab[1]==0 && tab[2]==1 && tab[3]==0)
      {
          tab[0]=0; tab[1]=1;
          tab[2]=1; tab[3]=0;
      }
      else if(tab[0]==1 && tab[1]==0 && tab[2]==1 && tab[3]==1)
      {
          tab[0]=1; tab[1]=1;
          tab[2]=0; tab[3]=0;
      }
      else if(tab[0]==1 && tab[1]==1 && tab[2]==0 && tab[3]==0)
      {
          tab[0]=0; tab[1]=1;
          tab[2]=0; tab[3]=1;
      }
      else if(tab[0]==1 && tab[1]==1 && tab[2]==0 && tab[3]==1)
      {
          tab[0]=1; tab[1]=0;
          tab[2]=0; tab[3]=1;
      }
      else if(tab[0]==1 && tab[1]==1 && tab[2]==1 && tab[3]==0)
      {
          tab[0]=0; tab[1]=0;
          tab[2]=0; tab[3]=0;
      }
      else if(tab[0]==1 && tab[1]==1 && tab[2]==1 && tab[3]==1)
      {
          tab[0]=0; tab[1]=1;
          tab[2]=1; tab[3]=1;
      }
      return *tab;
}



int mnoz(int *wynik, int *a, int *b)
{
    int sumowanie[7];

     for(int i=0;i<8;i++)
        sumowanie[i]=0;

    int redukc[5]={1,0,0,1,1};

    for(int i=0;i<4;i++)
        if(b[i]==1)
    {
        sumowanie[0+i]=((sumowanie[0+i]+a[0])%2);
        sumowanie[1+i]=((sumowanie[1+i]+a[1])%2);
        sumowanie[2+i]=((sumowanie[2+i]+a[2])%2);
        sumowanie[3+i]=((sumowanie[3+i]+a[3])%2);
    }

    for(int i=0;i<3;i++)
        if(sumowanie[i]==1)
    {
        sumowanie[0+i]=((sumowanie[0+i]+redukc[0])%2);
        sumowanie[1+i]=((sumowanie[1+i]+redukc[1])%2);
        sumowanie[2+i]=((sumowanie[2+i]+redukc[2])%2);
        sumowanie[3+i]=((sumowanie[3+i]+redukc[3])%2);
        sumowanie[4+i]=((sumowanie[4+i]+redukc[4])%2);
    }

    for(int i=0;i<4;i++)
        wynik[i]=sumowanie[i+3];

    return *wynik;
}


