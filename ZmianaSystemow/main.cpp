#include <iostream>
#include <math.h>
#include <string>

using namespace std;

void zamien(int &liczba, int system)
{
    int nrPotegi=0, potega=1, wynikINT[100]={NULL}, i=0;
    char wynikCHAR[100]={NULL};
    while(true)
    {
        potega*=system;
        if (potega>=liczba)
            break;
        nrPotegi++;
    }

    while(liczba>0 || ((system==2) && (nrPotegi>0)))
    {
        wynikINT[i]=liczba/(pow(system,nrPotegi));
        liczba=liczba-wynikINT[i++]*(pow(system,nrPotegi--));
        if (nrPotegi==0 && liczba==0)
            wynikINT[++i]=liczba;
    }

    if (system==2 && wynikINT[0]==2)
    {
        wynikINT[0]=1;
        wynikINT[i++]=0;
    }


    for (int j=0; j<i; j++)
        if (wynikINT[j]<10)
            wynikCHAR[j]=wynikINT[j] + 48;
        else
            wynikCHAR[j]=wynikINT[j] + 55;

    cout<<wynikCHAR;
}

int main()
{
    int liczba, system;
    cout<<"Podaj liczbe zapisana w systeme dziesietnym: ";
    cin>>liczba;
    cout<<"Na jakis system chcesz ja zamienic: ";
    cin>>system;
    cout<<"Ta liczba w systemie "<<system<<" wynosi: ";
    zamien(liczba, system);

    return 0;
}
