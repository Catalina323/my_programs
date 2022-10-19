#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

float functie (float x,int g, int v[50])
{float s=0;
int i,a=1;
for(i=(g+1);i>=1;i--)
{
    s=v[a]*pow(x,(i-1))+s;
    a++;
}
    return(s);
}

int main()
{int v[50],m,n,nrzec,g,i,a=2,sw=0;
double maxim, minim;
long nr;
cout<<"introduceti gradul functiei"<<endl;
cin>>g;
cout<<"introduceti valorile coeficientilor ecuatiei (primul diferit de 0)"<<endl;

//do
//{sw=0;
for(i=1;i<=(g+1);i++)
    {
    cin>>v[i];
    //if(!(v[i]<=999999 && v[i]>=-9999999))// 48 57
       // {sw=1;}
    }
//if(sw==1)
   // cout<<"rescrieti coeficientii folosind doar numere";
//}while(sw==1);

cout<<"ecuatia citita este: ";

if(v[1]<0)
    {if(v[1]==-1)
        cout<<"-x^"<<g;
        else
            cout<<v[1]<<"*x^"<<g;
    }
if(v[1]>0)
    {if(v[1]==1)
        cout<<"x^"<<g;
        else
            cout<<v[1]<<"*x^"<<g;
    }

for(i=(g-1);i>=1;i--)
    {if(v[a]<0)
        {if(i!=1)
            {cout<<v[a]<<"*x^"<<i;}
            else
                {cout<<v[a]<<"*x";}
        }
    if(v[a]>0)
        {if(i!=1)
            {if(v[a]==1)
                cout<<"+"<<"x^"<<i;
                else
                    cout<<"+"<<v[a]<<"*x^"<<i;
            }
        else
            {if(v[a]==1)
                cout<<"+"<<"x";
                else
                    cout<<"+"<<v[a]<<"*x";
            }
        }
    a++;
    }

if(v[a]<0)
    cout<<v[a];
if(v[a]>0)
    cout<<"+"<<v[a];

cout<<endl;
cout<<"introduceti intervalul [m,n]"<<endl;
cin>>m>>n;
cout<<"introduceti numarul de zecimale dorit"<<endl;
cin>>nrzec;

nr=pow(10,nrzec);

if((functie(m,g,v)*functie(n,g,v))<0)
{cout<<"Se poate aplica Lema Bolzano => exista o solutie x care apartine ["<<m<<","<<n<<"] ";

minim=m;
maxim=n;

while((int(minim*nr) != int(maxim*nr)))
{   if(functie(((maxim+minim)/2),g,v)<0)
        {minim=(maxim+minim)/2;}
        else
           {if(functie(((maxim+minim)/2),g,v)>0)
            {maxim=(maxim+minim)/2;}
            else
                {minim=(maxim+minim)/2;
                maxim=minim;}
            }
}

cout<<"solutia este: "<<endl<<endl<<(int (minim*nr))/nr<<"."<<(int (minim*nr))%nr;
cout<<endl;
}
else
    {cout<<"Nu se poate aplica Lema Bolzano";}

    return 0;
}
