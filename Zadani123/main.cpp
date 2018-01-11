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



int main()
{
    fstream plik,plik1,plik2;
    int ile=0;
    plik.open("ciagi.txt",ios::in);
    while(!plik.eof())
    {
        plik>>ciag;
        bool warunek=true;
        for (int i=0; i<strlen(ciag)-1; i++)
            if (ciag[i]!=ciag[(strlen(ciag)-1)/2])
                warunek=false;

        if (warunek)
            ile++;
    }
    cout<<ile;


    return 0;
}
