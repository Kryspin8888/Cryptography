#include<iostream>

using namespace std;

int licz=0,r1,r2,a,b,d;

float x,y,pom_x,u,q,pom_u,pom_r;

int main ()
{
cout<<"ALGORYTM ROZSZERZONY EUKLIDESA: NWD"<<endl<<endl;
cout<<"Podaj a:"<<endl;
cin>>a;
cout<<"Podaj b:"<<endl;
cin>>b;

pom_x=1;
u=0;

r1=a;
r2=b;

while (r2>0)
{
q=r1/r2;

pom_u=pom_x;
pom_x=u;
pom_r=r1;
r1=r2;
u=pom_u-q*u;
r2=pom_r-q*r2;
cout<<"Dla "<<"r"<<licz<<" = "<<r1<<"  x"<<licz<<" = "<<pom_x<<"  y"<<licz<<" = "<<(r1-pom_x*a)/b<<endl;
licz++;
}

d=r1;
x=pom_x;
y=(r1-pom_x*a)/b;

cout<<endl<<"NWD wynosi : "<<d<<endl<<endl;
cout<<"x wynosi : "<<x<<endl<<endl;
cout<<"y wynosi : "<<y<<endl<<endl;

return 0;
}
