#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

char ciag[200]="";
char liczba[30]="";
char ciag1[200]="";
char liczba1[30]="";
char ciag2[200]="";
char liczba2[30]="";
char pomoccc[20]="-";
int pomoc=0, pomoc1=0, pomoc2=0, mini=-999, mini1=-999, mini2=-999;
int wynik=999;
string odp1, odp2, odp3;

int ToDecimal(char l[20], int s)
{
    int wynik=0, mn=0, pom=0;
    bool warunek1=false;

    if (l[0]=='-')
    {
        warunek1=true;
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
    if (warunek1)
        wynik=wynik*(-1);
    return wynik;
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
        plik1>>liczba1;
        plik2>>ciag2;
        plik2>>liczba2;
        pomoc = ToDecimal(liczba, 2);
        pomoc1 = ToDecimal(liczba1, 4);
        pomoc2 = ToDecimal(liczba2, 8);
        bool warunek=false;

        if (pomoc>mini)
        {
            mini=pomoc;
            warunek=true;
        }

        if (pomoc1>mini1)
        {
            mini1=pomoc1;
            warunek=true;
        }

        if (pomoc2>mini2)
        {
            mini2=pomoc2;
            warunek=true;
        }

        if (warunek)
            ile++;
    }
    cout<<ile;


    return 0;
}
