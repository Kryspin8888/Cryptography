#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
char a;
int jaw[8],i;
cout<<"*Wprowadz blok maksymalnie 8 bitow: "<<endl;
cout<<"**Jesli chcesz zakonczyc wprowadzanie wczesniej - wcisnij 'enter': "<<endl;
for(i=0; i<8; i++)
    {
    a=getch();
    cout<<a<<endl;
    if(a==13) break;                                                      //wpisywanie bitow, enter konczy
    if(a!=48 && a!=49 ) {cout<<"Zly znak podaj 0 lub 1 "<<endl; i--;}
    else jaw[i]= (int) ( a-48 );
    }

cout<<endl<<"Twoj blok to :"<<endl;

for(int j=i; j<8; j++)
    jaw[j]=0;

for(int j=0; j<8; j++)
    cout<<jaw[j]<<" ";

cout<<endl<<endl;
cout<<"Wprowadz 10 bitowy klucz poczatkowy :"<<endl;
int kp[10];
for(int j=0; j<10; j++)
    {
    a=getch();
    cout<<a<<endl;
    if(a!=48 && a!=49 ) {cout<<"Zly znak podaj 0 lub 1 "<<endl; j--;}
    else kp[j]= (int) ( a-48 );
    }

cout<<endl<<"Twoj klucz poczatkowy to :"<<endl;

for(int j=0; j<10; j++)
    cout<<kp[j]<<" ";

int kp1[10], kp11[10], kp111[8], kp2[10], kp22[8];
cout<<endl<<endl<<endl;
cout<<"*SZYFROWANIE: "<<endl<<endl<<endl;
cout<<"Wygenerowany klucz 1 rundy: "<<endl;

kp1[0]=kp[2];   kp1[1]=kp[4];  kp1[2]=kp[1];  kp1[3]=kp[6];  kp1[4]=kp[3];  kp1[5]=kp[9];
kp1[6]=kp[0];   kp1[7]=kp[8];  kp1[8]=kp[7];  kp1[9]=kp[5];

kp11[0]=kp1[1];   kp11[1]=kp1[2];  kp11[2]=kp1[3];  kp11[3]=kp1[4];  kp11[4]=kp1[0];  kp11[5]=kp1[6];
kp11[6]=kp1[7];   kp11[7]=kp1[8];  kp11[8]=kp1[9];  kp11[9]=kp1[5];

kp111[0]=kp11[5];   kp111[1]=kp11[2];  kp111[2]=kp11[6];  kp111[3]=kp11[3];  kp111[4]=kp11[7];  kp111[5]=kp11[4];
kp111[6]=kp11[9];   kp111[7]=kp11[8];

for(int j=0; j<8; j++)
    cout<<kp111[j]<<" ";

cout<<endl<<endl;
cout<<"Wygenerowany klucz 2 rundy: "<<endl;

kp2[0]=kp11[2];   kp2[1]=kp11[3];  kp2[2]=kp11[4];  kp2[3]=kp11[0];  kp2[4]=kp11[1];  kp2[5]=kp11[7];
kp2[6]=kp11[8];   kp2[7]=kp11[9];  kp2[8]=kp11[5];  kp2[9]=kp11[6];

kp22[0]=kp2[5];   kp22[1]=kp2[2];  kp22[2]=kp2[6];  kp22[3]=kp2[3];  kp22[4]=kp2[7];  kp22[5]=kp2[4];
kp22[6]=kp2[9];   kp22[7]=kp2[8];

for(int j=0; j<8; j++)
    cout<<kp22[j]<<" ";

int sbox1[4][4], sbox2[4][4],x1,x2,y1,y2;

sbox1[0][0]=1; sbox1[0][1]=0; sbox1[0][2]=3; sbox1[0][3]=2;
sbox1[1][0]=3; sbox1[1][1]=2; sbox1[1][2]=1; sbox1[1][3]=0;
sbox1[2][0]=0; sbox1[2][1]=2; sbox1[2][2]=1; sbox1[2][3]=3;
sbox1[3][0]=3; sbox1[3][1]=1; sbox1[3][2]=3; sbox1[3][3]=2;

sbox2[0][0]=0; sbox2[0][1]=1; sbox2[0][2]=2; sbox2[0][3]=3;
sbox2[1][0]=2; sbox2[1][1]=0; sbox2[1][2]=1; sbox2[1][3]=3;
sbox2[2][0]=3; sbox2[2][1]=0; sbox2[2][2]=1; sbox2[2][3]=0;
sbox2[3][0]=2; sbox2[3][1]=1; sbox2[3][2]=0; sbox2[3][3]=3;

int jaw2[8], jawpermw[8], jaw22[8], jaw222[4], jaw2222[4], jaw22222[4], szyfr1[8], szyfr2[8], szyfr22[8];

//permutacja wstepna

jawpermw[0]=jaw[1];  jawpermw[1]=jaw[5];  jawpermw[2]=jaw[2];  jawpermw[3]=jaw[0];
jawpermw[4]=jaw[3];  jawpermw[5]=jaw[7];  jawpermw[6]=jaw[4];  jawpermw[7]=jaw[6];

cout<<endl<<endl<<"Tekst po permutacji wstepnej: "<<endl;
for(int j=0; j<8; j++)
    cout<<jawpermw[j]<<" ";

//szyfrowanie 1 runda

jaw2[0]=jawpermw[7];  jaw2[1]=jawpermw[4];  jaw2[2]=jawpermw[5];  jaw2[3]=jawpermw[6];
jaw2[4]=jawpermw[5];  jaw2[5]=jawpermw[6];  jaw2[6]=jawpermw[7];  jaw2[7]=jawpermw[4];

for(int k=0; k<8; k++)
{
    jaw22[k]=jaw2[k]+kp111[k];
    if(jaw22[k]==2) jaw22[k]=0;
}

//sbox
if(jaw22[0]==0 && jaw22[3]==0) x1=0;
else if(jaw22[0]==0 && jaw22[3]==1) x1=1;
else if(jaw22[0]==1 && jaw22[3]==0) x1=2;
else if(jaw22[0]==1 && jaw22[3]==1) x1=3;

if(jaw22[1]==0 && jaw22[2]==0) y1=0;
else if(jaw22[1]==0 && jaw22[2]==1) y1=1;
else if(jaw22[1]==1 && jaw22[2]==0) y1=2;
else if(jaw22[1]==1 && jaw22[2]==1) y1=3;

if(jaw22[4]==0 && jaw22[7]==0) x2=0;
else if(jaw22[4]==0 && jaw22[7]==1) x2=1;
else if(jaw22[4]==1 && jaw22[7]==0) x2=2;
else if(jaw22[4]==1 && jaw22[7]==1) x2=3;

if(jaw22[5]==0 && jaw22[6]==0) y2=0;
else if(jaw22[5]==0 && jaw22[6]==1) y2=1;
else if(jaw22[5]==1 && jaw22[6]==0) y2=2;
else if(jaw22[5]==1 && jaw22[6]==1) y2=3;

if(sbox1[x1][y1]==0) {jaw222[0]=0; jaw222[1]=0;}
else if(sbox1[x1][y1]==1) {jaw222[0]=0; jaw222[1]=1;}
else if(sbox1[x1][y1]==2) {jaw222[0]=1; jaw222[1]=0;}
else if(sbox1[x1][y1]==3) {jaw222[0]=1; jaw222[1]=1;}

if(sbox2[x2][y2]==0) {jaw222[2]=0; jaw222[3]=0;}
else if(sbox2[x2][y2]==1) {jaw222[2]=0; jaw222[3]=1;}
else if(sbox2[x2][y2]==2) {jaw222[2]=1; jaw222[3]=0;}
else if(sbox2[x2][y2]==3) {jaw222[2]=1; jaw222[3]=1;}

//sbox

cout<<endl<<endl<<"Runda 1 : sbox1: "<<sbox1[x1][y1]<<"  sbox2: "<<sbox2[x2][y2];

jaw2222[0]=jaw222[1];  jaw2222[1]=jaw222[3];  jaw2222[2]=jaw222[2];  jaw2222[3]=jaw222[0];

for(int k=0; k<4; k++)
{
    jaw22222[k]=jawpermw[k]+jaw2222[k];
    if(jaw22222[k]==2) jaw22222[k]=0;
}
for(int k=0; k<4; k++)
{
    szyfr1[k]=jaw22222[k];
    szyfr1[7-k]=jawpermw[7-k];
}

cout<<endl<<endl<<"Tekst zaszyfrowany kluczem 1 rundy: "<<endl;
for(int j=0; j<8; j++)
    cout<<szyfr1[j]<<" ";

//krzyzowanie
int szyfr11[8];

szyfr11[0]=szyfr1[4];  szyfr11[1]=szyfr1[5];  szyfr11[2]=szyfr1[6];  szyfr11[3]=szyfr1[7];
szyfr11[4]=szyfr1[0];  szyfr11[5]=szyfr1[1];  szyfr11[6]=szyfr1[2];  szyfr11[7]=szyfr1[3];

cout<<endl<<endl<<"Tekst po krzyzowaniu: "<<endl;
for(int j=0; j<8; j++)
    cout<<szyfr11[j]<<" ";

//szyfrowanie 2 runda

jaw2[0]=szyfr11[7];  jaw2[1]=szyfr11[4];  jaw2[2]=szyfr11[5];  jaw2[3]=szyfr11[6];
jaw2[4]=szyfr11[5];  jaw2[5]=szyfr11[6];  jaw2[6]=szyfr11[7];  jaw2[7]=szyfr11[4];

for(int k=0; k<8; k++)
{
    jaw22[k]=jaw2[k]+kp22[k];
    if(jaw22[k]==2) jaw22[k]=0;
}

//sbox
if(jaw22[0]==0 && jaw22[3]==0) x1=0;
else if(jaw22[0]==0 && jaw22[3]==1) x1=1;
else if(jaw22[0]==1 && jaw22[3]==0) x1=2;
else if(jaw22[0]==1 && jaw22[3]==1) x1=3;

if(jaw22[1]==0 && jaw22[2]==0) y1=0;
else if(jaw22[1]==0 && jaw22[2]==1) y1=1;
else if(jaw22[1]==1 && jaw22[2]==0) y1=2;
else if(jaw22[1]==1 && jaw22[2]==1) y1=3;

if(jaw22[4]==0 && jaw22[7]==0) x2=0;
else if(jaw22[4]==0 && jaw22[7]==1) x2=1;
else if(jaw22[4]==1 && jaw22[7]==0) x2=2;
else if(jaw22[4]==1 && jaw22[7]==1) x2=3;

if(jaw22[5]==0 && jaw22[6]==0) y2=0;
else if(jaw22[5]==0 && jaw22[6]==1) y2=1;
else if(jaw22[5]==1 && jaw22[6]==0) y2=2;
else if(jaw22[5]==1 && jaw22[6]==1) y2=3;

if(sbox1[x1][y1]==0) {jaw222[0]=0; jaw222[1]=0;}
else if(sbox1[x1][y1]==1) {jaw222[0]=0; jaw222[1]=1;}
else if(sbox1[x1][y1]==2) {jaw222[0]=1; jaw222[1]=0;}
else if(sbox1[x1][y1]==3) {jaw222[0]=1; jaw222[1]=1;}

if(sbox2[x2][y2]==0) {jaw222[2]=0; jaw222[3]=0;}
else if(sbox2[x2][y2]==1) {jaw222[2]=0; jaw222[3]=1;}
else if(sbox2[x2][y2]==2) {jaw222[2]=1; jaw222[3]=0;}
else if(sbox2[x2][y2]==3) {jaw222[2]=1; jaw222[3]=1;}

//sbox

cout<<endl<<endl<<"Runda 2 : sbox1: "<<sbox1[x1][y1]<<"  sbox2: "<<sbox2[x2][y2];

jaw2222[0]=jaw222[1];  jaw2222[1]=jaw222[3];  jaw2222[2]=jaw222[2];  jaw2222[3]=jaw222[0];

for(int k=0; k<4; k++)
{
    jaw22222[k]=szyfr11[k]+jaw2222[k];
    if(jaw22222[k]==2) jaw22222[k]=0;
}
for(int k=0; k<4; k++)
{
    szyfr2[k]=jaw22222[k];
    szyfr2[7-k]=szyfr11[7-k];
}

cout<<endl<<endl<<"Tekst zaszyfrowany kluczem 2 rundy: "<<endl;
for(int j=0; j<8; j++)
    cout<<szyfr2[j]<<" ";

//permutacja odwrotna

szyfr22[0]=szyfr2[3];  szyfr22[1]=szyfr2[0];  szyfr22[2]=szyfr2[2];  szyfr22[3]=szyfr2[4];
szyfr22[4]=szyfr2[6];  szyfr22[5]=szyfr2[1];  szyfr22[6]=szyfr2[7];  szyfr22[7]=szyfr2[5];

cout<<endl<<endl;
cout<<"Tekst po permutacji odwrotnej - ZASZYFROWANY TEKST: "<<endl;
for(int j=0; j<8; j++)
    cout<<szyfr22[j]<<" ";

cout<<endl;
return 0;
}
