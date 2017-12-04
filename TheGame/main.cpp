#include <iostream>
#include <conio.h>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include <ctime>

using namespace std;

struct _menu
{
    char element[32];
} _Menu[5];

struct _wspolrzedne
{
   int x;
   int y;
} _Wspolrzedne[2500];

struct bomby
    {
      int x=0;
      int y=0;
} _listap[2500];



void drukuj(_menu t[], int poz, int licz_el)
{
        system("CLS");
        for(int i=0; i<licz_el; i++)
        {
                if(i==poz)
                    cout<<"*";
                else
                cout<<" ";
                cout<<t[i].element<<endl;
        }
}

void wybieranie()
{
    int poz=0, liczba_elementow = 5;
    char klik;
    bool warunek=true;
    drukuj(_Menu, poz, liczba_elementow);
    do{
        klik=getch();
        switch (klik)
        {
            case 72:
                poz--;
                break;
            case 80:
                poz++;
                break;
        }
        if(poz<0)
            poz+=liczba_elementow;
        else poz%=liczba_elementow;
            drukuj(_Menu, poz, liczba_elementow);
        if(klik==13)
        {
            cout<<"Wcisnieto: "<<_Menu[poz].element<<endl;
            warunek = false;
        }

        } while(klik!=27 && warunek);

}

void losuj_sciezke(int N)
{

    int x=0,y=0;
    for (int i=1; i<2*N-2; i++)
        {
            int ran =rand()%2;
            if (ran)
            {
                if (x<N-1)
                {
                    x++;
                    _Wspolrzedne[i].x = x;
                    _Wspolrzedne[i].y = _Wspolrzedne[i-1].y;
                }
                else
                    for (i=i; i<2*N-1; i++)
                    {
                        y++;
                        _Wspolrzedne[i].y = y;
                        _Wspolrzedne[i].x = _Wspolrzedne[i-1].x;
                    }
            }
            else
            {
                if (y<N-1)
                {
                    y++;
                    _Wspolrzedne[i].y = y;
                    _Wspolrzedne[i].x = _Wspolrzedne[i-1].x;
                }
                else
                    for (i=i; i<2*N-1; i++)
                    {
                        x++;
                        _Wspolrzedne[i].x = x;
                        _Wspolrzedne[i].y = _Wspolrzedne[i-1].y;
                    }
            }
        }
}

void losuj_bomby(int N, int poziom)
{
    bool warunek;

    if (poziom==1)
        poziom=N*N*0.2;
    else if (poziom==2)
        poziom=N*N*0.5;
    else
        poziom=N*N*0.8;

    for (int i=0; i<=poziom; i++)
    {
        do
        {
            warunek=false;
            _listap[i].x=rand()%(N);
            _listap[i].y=rand()%(N);

            if ((_listap[i].x==0 && _listap[i].y==0) || (_listap[i].x==N-1 && _listap[i].y==N-1))
                warunek=true;

            for (int j=0; j<i; j++)
                if ((_listap[i].x == _listap[j].x) && (_listap[i].y ==_listap[j].y))
                    warunek=true;

            for (int j=0; j<2*N-2; j++)
                if ((_listap[i].x == _Wspolrzedne[j].x) && (_listap[i].y == _Wspolrzedne[j].y))
                    warunek=true;

        } while(warunek);
    }


}

void sortuj_bomby(int N, int poziom)
{
    bool warunek;
    if (poziom==1)
        poziom=N*N*0.2;
    else if (poziom==2)
        poziom=N*N*0.5;
    else
        poziom=N*N*0.8;

    do
    {
       warunek=false;
        for (int i=0; i<poziom; i++)
        {
            if ((_listap[i].x > _listap[i+1].x) || ((_listap[i].x == _listap[i+1].x) && (_listap[i].y  > _listap[i+1].y)))
            {
                swap(_listap[i].x,_listap[i+1].x);
                swap(_listap[i].y,_listap[i+1].y);
                warunek=true;
            }
        }
    } while(warunek);

}

void rysuj_sciezke(int N)
{
    int k=0;
    int f=0;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
            if (_listap[k].x==i && _listap[k].y==j)
            {
                k++;
                cout<<"B";
            }
            else if (_Wspolrzedne[f].x==i  && _Wspolrzedne[f].y==j)
            {
                f++;
                cout<<"#";
            }
            else
                cout<<"*";
        cout<<endl;
    }

}


int main()
{
        srand(time(NULL));

        strcpy(_Menu[0].element, "Nowa gra");
        strcpy(_Menu[1].element, "Kontynuacja");
        strcpy(_Menu[2].element, "Zapis");
        strcpy(_Menu[3].element, "Odczyt");
        strcpy(_Menu[4].element, "Koniec");

        wybieranie();

        int N=10;
        int stopien_trudnosci=2;
        int x=0, y=0;

        losuj_sciezke(N);
        losuj_bomby(N, stopien_trudnosci);
        sortuj_bomby(N, stopien_trudnosci);
        rysuj_sciezke(N);





        return 0;
}
