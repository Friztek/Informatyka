#include <iostream>
#include <time.h>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    int zgadywana,wylosowana,czynnik_1,czynnik_2, i;
    float ile=0;

    srand(time(NULL));

    for (i=0; i<1000; i++)
    {
    czynnik_1=1000;
    czynnik_2=1;
    zgadywana=(rand()%1000)+1;

    while(zgadywana!=wylosowana)
    {
        wylosowana=(rand()%(czynnik_1-czynnik_2+1))+czynnik_2;
        //cout<<"Wylosowana: "<<wylosowana<<" Zgadywana: "<<zgadywana<<" Czynnik 1: "<<czynnik_1<<" Czynnik 2: "<<czynnik_2<<endl;
        if (wylosowana==zgadywana)
            break;
        if (wylosowana<zgadywana)
        {
            czynnik_2=wylosowana+1;
        }

        else if (wylosowana>zgadywana)
        {
            czynnik_1=wylosowana-1;
        }
        ile++;
    }
    }
    cout<<ile/i;
    return 0;
}
