#include <iostream>
#include <fstream>
#include <cstring>
// 0 1 2 3 4 5 6 7
// 1 1 0 1 1 0 1 1

using namespace std;

char ciag[20]="";
int l;

bool sprawdzczy ()
{
    if (strlen(ciag)%2==0)
    {
        int i=0;
        while(i<strlen(ciag)/2)
        {
                if (ciag[i]!=ciag[(strlen(ciag)/2)+i])
                    return false;
                if (i+1==l/2)
                    return true;
                i++;
        }
    }else return false;
}
/*
bool sprawdz (char tb[], int l)
{
    bool warunek=true;
    for (int i=0; i<l-1; i++)
        if (tb[i]=='1' && tb[i+1]=='1')
                warunek=false;
    if (warunek)
    {
        return true;
    }
    else
        return false;
}

bool Parzyste (char tb[], int l)
{
    if (tb[l-1]=='1')
        return false;
    else
        return true;

}
*/

int main()
{
    int ile=0;
    fstream plik;
    plik.open("ciagi.txt",ios::in);
    if (plik.good())
    {
        while(!plik.eof())
        {
            plik>>ciag;
            l=strlen(ciag);
            /*
            if (sprawdz(ciag,l))
            {
                ile++;
                cout<<ciag<<endl;
            }
            */

            /*
            if (Parzyste(ciag,l))
            {
                ile++;
                cout<<ciag<<endl;
            }
            */
            /*
            if (sprawdzczy(ciag,l)==true){
                cout<<ciag<<endl;
                ile++;
            }
            */
            if(sprawdzczy()){
                cout << ciag << endl;
                ile++;
            }

        }
        cout<<ile;
    }
    else cout<<"Nie otwarto pliku";
    return 0;
}
