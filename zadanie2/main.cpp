#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

char ciag[200]="";
char liczba[20]="";
char ciag1[200]="";
char ciag2[200]="";
char pomoccc[20]="-";
int pomoc=0, pomoc1=0, pomoc2=0;
int wynik=999;
string odp1, odp2, odp3;

int ToDecimal(char l[20], int s)
{
    int wynik=0, mn=0, pom=0;

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
    int ile=0;
    plik.open("dane_systemy1.txt",ios::in);
    plik1.open("dane_systemy2.txt",ios::in);
    plik2.open("dane_systemy3.txt",ios::in);
    while(!plik.eof())
    {
        plik>>ciag;
        plik>>liczba;
        plik1>>ciag1;
        plik1>>liczba;
        plik2>>ciag2;
        plik2>>liczba;
        pomoc = ToDecimal(ciag, 2);
        pomoc1 = ToDecimal(ciag1, 4);
        pomoc2 = ToDecimal(ciag2, 8);
        if (pomoc%12!=0 && pomoc1%12!=0 && pomoc2%12!=0)
            ile++;
    }
    cout<<ile;


    return 0;
}
