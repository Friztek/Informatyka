#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

char ciag[20]="";
char liczba[20]="";
char pomoccc[20]="-";
int pomoc=0;
int wynik=999;
string odp1, odp2, odp3;

int ToDecimal(char l[20], int s)
{
    int wynik=0, mn=0, pom=0;
    bool warunek=false;

    if (l[0]=='-')
    {
        warunek=true;
        pom=1;
    }

    for(int i=strlen(l)-1; i>=pom; i--)
    {
        if(isalpha(l[i]))
        {
            l[i]=toupper(l[i]);
            l[i]-=7;
        }
        wynik+=(l[i]-48)*pow(s, mn);
        mn++;
    }
    if (warunek)
        wynik=wynik*(-1);
    return wynik;
}

string konwersja_na_k(int n, int s)
{
    bool warunek=false;
    if (n<0)
        warunek=true;

    char wynik[100]={NULL};
    for (int i=0; n!=0; i++)
    {
        if(n!=0)
        wynik[i]=(n%s)+48;
        if(wynik[i]>57)
            wynik[i]+=7;
        n=n/s;
    }

    for (int i=0; i<strlen(wynik)/2; i++)
        swap(wynik[i],wynik[strlen(wynik)-1-i]);

    for (int i=0; i<strlen(wynik); i++)
        if (wynik[i]=='/')
            wynik[i]='1';


    int pom=strlen(wynik);
    if (warunek)
    {
        for (int i=1; i<=pom; i++)
            pomoccc[i]=wynik[i-1];

    }
    return pomoccc;
}


int main()
{
    fstream plik,plik1,plik2;
    plik.open("dane_systemy1.txt",ios::in);
    if (plik.good())
    {
        while(!plik.eof())
        {
            plik>>ciag;
            plik>>liczba;
            pomoc = ToDecimal(liczba, 2);
            if (pomoc<wynik)
                wynik=pomoc;
        }
        odp1=konwersja_na_k(wynik, 2);
        cout<<odp1<<endl;
    }
    wynik=999;
    plik1.open("dane_systemy2.txt",ios::in);
    if (plik1.good())
    {
        while(!plik1.eof())
        {
            plik1>>ciag;
            plik1>>liczba;
            pomoc = ToDecimal(liczba, 4);
            if (pomoc<wynik)
                wynik=pomoc;
        }
        odp2=konwersja_na_k(wynik, 2);
        cout<<odp2<<endl;
    }
    wynik=999;
    plik2.open("dane_systemy3.txt",ios::in);
    if (plik2.good())
    {
        while(!plik2.eof())
        {
            plik2>>ciag;
            plik2>>liczba;
            pomoc = ToDecimal(liczba, 8);
            if (pomoc<wynik)
                wynik=pomoc;
        }
        odp3=konwersja_na_k(wynik, 2);
        cout<<odp3;
    }
    fstream zapis;
    zapis.open("wyniki_systemy.txt",ios::out);
    zapis<<"dane_systemy1.txt"<<endl;
    zapis<<odp1<<endl;
    zapis<<"dane_systemy2.txt"<<endl;
    zapis<<odp2<<endl;
    zapis<<"dane_systemy3.txt"<<endl;
    zapis<<odp3;

    return 0;
}
