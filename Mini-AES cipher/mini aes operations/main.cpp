#include <iostream>
#include <conio.h>
#include<windows.h>

using namespace std;

int sboxe(int *tab);
int sboxd(int *tab);
int mnoz(int *mr1, int *m1, int *t1);

int main()
{
char z;
int a[4];
int b[4],c[4],c1[4];

Beep(4000,700);
Beep(4000,700);
Beep(4000,700);
Beep(4000,700);
Beep(3000,5000);

cout<<"*Wprowadz ciag a 4 bitow: "<<endl;
for(int i=0; i<4; i++)
    {
    z=getch();
    cout<<z<<endl;
    if(z==13) break;                                                      //wpisywanie bitow, enter konczy
    if(z!=48 && z!=49 ) {cout<<"Zly znak podaj 0 lub 1 "<<endl; i--;}
    else a[i]= (int) ( z-48 );
    }

cout<<endl<<"*Wprowadz ciag b 4 bitow: "<<endl;
for(int i=0; i<4; i++)
    {
    z=getch();
    cout<<z<<endl;
    if(z==13) break;                                                      //wpisywanie bitow, enter konczy
    if(z!=48 && z!=49 ) {cout<<"Zly znak podaj 0 lub 1 "<<endl; i--;}
    else b[i]= (int) ( z-48 );
    }

cout<<endl<<"Twoj blok a to :"<<endl;

for(int j=0; j<4; j++)
    {
        cout<<a[j]<<" ";
    }

cout<<endl<<endl<<"Twoj blok b to :"<<endl;

for(int j=0; j<4; j++)
    {
        cout<<b[j]<<" ";
    }

cout<<endl<<endl<<"Mnozenie :"<<endl;
mnoz(c,a,b);

for(int j=0; j<4; j++)
    {
        cout<<c[j]<<" ";
        c1[j]=c[j];

    }


sboxe(c);

cout<<endl<<endl<<"SboxE dla iloczynu to :"<<endl;

for(int j=0; j<4; j++)
    cout<<c[j]<<" ";

cout<<endl<<endl;

cout<<"SboxD dla iloczynu to :"<<endl;

sboxd(c1);

for(int j=0; j<4; j++)
    cout<<c1[j]<<" ";

cout<<endl<<endl<<endl;


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

int sboxd(int *tab)
{
      if(tab[0]==0 && tab[1]==0 && tab[2]==0 && tab[3]==0)
      {
          tab[0]=1; tab[1]=1;
          tab[2]=1; tab[3]=0;
      }
      else if(tab[0]==0 && tab[1]==0 && tab[2]==0 && tab[3]==1)
      {
          tab[0]=0; tab[1]=0;
          tab[2]=1; tab[3]=1;
      }
      else if(tab[0]==0 && tab[1]==0 && tab[2]==1 && tab[3]==0)
      {
          tab[0]=0; tab[1]=1;
          tab[2]=0; tab[3]=0;
      }
      else if(tab[0]==0 && tab[1]==0 && tab[2]==1 && tab[3]==1)
      {
          tab[0]=1; tab[1]=0;
          tab[2]=0; tab[3]=0;
      }
      else if(tab[0]==0 && tab[1]==1 && tab[2]==0 && tab[3]==0)
      {
          tab[0]=0; tab[1]=0;
          tab[2]=0; tab[3]=1;
      }
      else if(tab[0]==0 && tab[1]==1 && tab[2]==0 && tab[3]==1)
      {
          tab[0]=1; tab[1]=1;
          tab[2]=0; tab[3]=0;
      }
      else if(tab[0]==0 && tab[1]==1 && tab[2]==1 && tab[3]==0)
      {
          tab[0]=1; tab[1]=0;
          tab[2]=1; tab[3]=0;
      }
      else if(tab[0]==0 && tab[1]==1 && tab[2]==1 && tab[3]==1)
      {
          tab[0]=1; tab[1]=1;
          tab[2]=1; tab[3]=1;
      }
      else if(tab[0]==1 && tab[1]==0 && tab[2]==0 && tab[3]==0)
      {
          tab[0]=0; tab[1]=1;
          tab[2]=1; tab[3]=1;
      }
      else if(tab[0]==1 && tab[1]==0 && tab[2]==0 && tab[3]==1)
      {
          tab[0]=1; tab[1]=1;
          tab[2]=0; tab[3]=1;
      }
      else if(tab[0]==1 && tab[1]==0 && tab[2]==1 && tab[3]==0)
      {
          tab[0]=1; tab[1]=0;
          tab[2]=0; tab[3]=1;
      }
      else if(tab[0]==1 && tab[1]==0 && tab[2]==1 && tab[3]==1)
      {
          tab[0]=0; tab[1]=1;
          tab[2]=1; tab[3]=0;
      }
      else if(tab[0]==1 && tab[1]==1 && tab[2]==0 && tab[3]==0)
      {
          tab[0]=1; tab[1]=0;
          tab[2]=1; tab[3]=1;
      }
      else if(tab[0]==1 && tab[1]==1 && tab[2]==0 && tab[3]==1)
      {
          tab[0]=0; tab[1]=0;
          tab[2]=1; tab[3]=0;
      }
      else if(tab[0]==1 && tab[1]==1 && tab[2]==1 && tab[3]==0)
      {
          tab[0]=0; tab[1]=0;
          tab[2]=0; tab[3]=0;
      }
      else if(tab[0]==1 && tab[1]==1 && tab[2]==1 && tab[3]==1)
      {
          tab[0]=0; tab[1]=1;
          tab[2]=0; tab[3]=1;
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


