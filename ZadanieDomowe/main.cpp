#include <iostream>
#include <string.h>
#include <ctype.h>
#include <cmath>

using namespace std;


int ToDecimal(char l[20], int s)
{
    int wynik=0, mn=0;

    for(int i=strlen(l)-1; i>=0; i--)
    {
        if(isalpha(l[i]))
        {
            l[i]=toupper(l[i]);
            l[i]-=7;
        }
        wynik+=(l[i]-48)*pow(s, mn);
        mn++;
    }
    return wynik;
}

string konwersja_na_k(int n, int s)
{
    char wynik[100]={NULL};
    for (int i=0; n!=0; i++)
    {
        if(n!=0) wynik[i]=(n%s)+48;
            if(wynik[i]>57) wynik[i]+=7;
                n=n/s;
    }

    for (int i=0; i<strlen(wynik)/2; i++)
        swap(wynik[i],wynik[strlen(wynik)-1-i]);

    return wynik;
}

int main()
{
    char liczba1[100], liczba2[100];
    unsigned long long dz1, dz2, pomocINT;
    float float1, float2, pomocFLOAT;
    unsigned int system;

    cout<<"Podaj 1 liczbe: ";
        cin.getline(liczba1,20);
    cout<<"Podaj 2 liczbe: ";
        cin.getline(liczba2,20);

    do
    {
    cout<<"System liczbowy: ";
    cin>>system;
    if(system>36)
        cout<<"Max. 36!"<< endl;
    }
    while(system>36);

    dz1=ToDecimal(liczba1, system);
    dz2=ToDecimal(liczba2, system);

    float1=dz1;
    float2=dz2;

    pomocFLOAT=(float1/float2)-(dz1/dz2);
    pomocINT=pomocFLOAT*10000;

    cout<<"Suma: "<<konwersja_na_k(dz1+dz2,system)<<endl;

    if (dz1==dz2)
        cout<<"Roznica: 0"<<endl;
    else if (dz1>dz2)
        cout<<"Roznica: "<<konwersja_na_k(dz1-dz2, system)<<endl;
    else
        cout<<"Roznica: -"<<konwersja_na_k(dz2-dz1, system)<<endl;


    cout<<"Iloczyn: "<<konwersja_na_k(dz1*dz2, system)<<endl;

    if (dz1==0 && dz2==0)
        cout<<"Iloraz: Nie mozna dzielic przez 0!"<<endl;
    else if (dz1>=dz2)
    {
        cout<<"Iloraz: "<<konwersja_na_k(dz1/dz2, system);
        if (pomocINT!=0)
            cout<<"."<<konwersja_na_k(pomocINT, system)<<endl;
        else
            cout<<endl;
    }
    else
    {
        cout<<"Iloraz: 0"<<konwersja_na_k(dz1/dz2, system);
        if (pomocINT!=0)
            cout<<"."<<konwersja_na_k(pomocINT, system)<<endl;
    }
    return 0;
}
