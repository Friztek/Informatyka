#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
    int liczba, ile=0;
    fstream plik;
    plik.open("Liczby.txt",ios::in);
    if (plik.good())
    {
        while(!plik.eof())
        {
            int dzielniki[20]={NULL}, i=0, dzielnik=2, dzielniki_bez_powtorzen[20]={NULL}, x=0, pomoc;
            bool warunek=true;
            plik>>liczba;
            pomoc=liczba;
            while(pomoc>1)
            {
                if (pomoc%dzielnik==0)
                {
                    dzielniki[i++]=dzielnik;
                    pomoc=pomoc/dzielnik;
                    if (dzielnik==2)
                    {
                        warunek=false;
                        break;
                    }
                }
                else
                dzielnik++;
            }

            for (int j=0; j<i; j++)
            {
                bool warunek2=true;
                for (int k=0; k<j; k++)
                    if (dzielniki[j]==dzielniki_bez_powtorzen[k])
                        warunek2=false;
                if (warunek2)
                    dzielniki_bez_powtorzen[x++]=dzielniki[j];
            }
            if (x==3 && warunek)
                ile++;
        }
        cout<<ile;
    }
    else cout<<"Nie otwarto pliku";
    return 0;
}
