#include <iostream>
#include <cstring>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <fstream>

using namespace std;

struct _menu{
    string element;
} _Menu[5];

struct _wspolrzedne{
   int x;
   int y;
} _Wspolrzedne[25000];

struct _bomby{
    int x;
    int y;
} _listap[2500];

struct _odkryte{
    int x;
    int y;
} _Odkryte[2500];


//konfiguracja
int N=10;
int poziom=3; //2, 5, 8
int bomby=N*N*poziom/10;
int zycia=4;

// zmienne
bool wygrana=false;
bool czyzaczeta=false;
int x1=0, y1=0;
int ile=0;
int poz=0;
int liczba_elementow = 5;


void drukuj()
{
    _Menu[0].element = "Nowa gra";
    _Menu[1].element = "Kontynuacja";
    _Menu[2].element = "Zapis";
    _Menu[3].element = "Odczyt";
    _Menu[4].element = "Koniec";

        system("CLS");
        for(int i=0; i<liczba_elementow; i++)
        {
                if(i==poz)
                    cout<<"*";
                else
                    cout<<" ";
                cout<<_Menu[i].element<<endl;
        }
}

void czysc()
{
    for (int i=0; i<N*N; i++)
    {
        _Wspolrzedne[i].x=0;
        _Wspolrzedne[i].y=0;
        _Odkryte[i].x=0;
        _Odkryte[i].y=0;
        _listap[i].x=0;
        _listap[i].y=0;
    }
        x1=0;
        y1=0;
        zycia=4;
        ile=0;
        bomby=N*N*poziom/10;
}

void koniec()
{
    system("CLS");
    if (poz==4)
    {
        cout<<"Dziekuje za gre!"<<endl;
        cout<<"GRA WYKONANA PRZEZ ELITARNYCH UCZNIOW ZSA, CZYLI NORBERTA SZTYK I MADZIE SLIWKE :)";
    }
    else if(wygrana)
        cout<<"Wygrales!";
    else
        cout<<"Przegrales!";
    czyzaczeta=false;
    czysc();
    Sleep(2000);
}

void losuj_sciezke()
{

    int x=0,y=0;
    for (int i=1; i<2*N-1; i++)
        {
            int ran=rand()%2;
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

void losuj_bomby()
{
    bool warunek;

    for (int i=0; i<=bomby; i++)
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
                if ((_listap[i].y == _Wspolrzedne[j].x) && (_listap[i].x == _Wspolrzedne[j].y))
                    warunek=true;

        } while(warunek);
    }


}
/*
void sortuj_bomby()
{
    bool warunek;

    do
    {
       warunek=false;
        for (int i=0; i<bomby; i++)
        {
            if ((_listap[i].y > _listap[i+1].y) || ((_listap[i].y == _listap[i+1].y) && (_listap[i].x  > _listap[i+1].x)))
            {
                swap(_listap[i].x,_listap[i+1].x);
                swap(_listap[i].y,_listap[i+1].y);
                warunek=true;
            }
        }
    } while(warunek);

}

void rysuj_sciezke()
{
    int k=0;
    int f=0;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
            if (_listap[k].x==j && _listap[k].y==i)
            {
                k++;
                cout<<"B";
            }
            else if (_Wspolrzedne[f].y==j  && _Wspolrzedne[f].x==i)
            {
                f++;
                cout<<"#";
            }
            else
                cout<<"*";
        cout<<endl;
    }

}
*/

void rysuj_plansze()
{
    HANDLE hOut;
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    system("CLS");
    SetConsoleTextAttribute(hOut,7);
    for (int i=0; i<zycia; i++)
        cout<<char(3)<<" ";
    cout<<endl;

    cout<<char(218);
    for (int i=0; i<N; i++)
        cout<<char(196);
    cout<<char(191)<<endl;

    for (int i=0; i<N; i++)
    {
        cout<<char(179);
        for (int j=0; j<N; j++)
        {
            bool warunek=false;

            for (int k=0; k<ile; k++)
                if ((_Odkryte[k].x==j)&&(_Odkryte[k].y==i))
                {
                    warunek=true;
                    break;
                }


            if ((N-1==j)&&(N-1==i))
                cout<<"M";

            else if ((x1==j)&&(y1==i))
                cout<<"#";

            else if (warunek)
            {
                SetConsoleTextAttribute(hOut,4);
                cout<<"B";
                SetConsoleTextAttribute(hOut,7);
            }
            else
                cout<<" ";
        }
        cout<<char(179);
        cout<<endl;
    }
    cout<<char(192);
    for (int i=0; i<N; i++)
        cout<<char(196);
    cout<<char(217);
}

void zapis()
{
    fstream plik;
    plik.open("save.txt",ios::out);
    plik<<N<<endl;
    plik<<zycia<<endl;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            bool warunek=false;
            bool warunek1=false;

            for (int k=0; k<ile; k++)
                if ((_Odkryte[k].x==j)&&(_Odkryte[k].y==i))
                {
                    warunek=true;
                    break;
                }
            for (int k=0; k<bomby; k++)
                if ((_listap[k].x==j)&&(_listap[k].y==i))
                {
                    warunek1=true;
                    break;
                }

            if ((x1==j)&&(y1==i))
                plik<<"G"; //GRACZ
            else if(warunek)
                plik<<"O"; //ODKRTTE
            else if(warunek1)
                plik<<"B"; //BOMBA
            else
                plik<<"*"; //PUSTE
        }
            plik<<endl;
    }
    cout<<"ZAPISANO";
    Sleep(1000);

}


void wczytaj()
{
    czysc();
    czyzaczeta=true;
    ile=0;
    bomby=0;
    char znak;
    fstream plik;
    plik.open("save.txt",ios::in);
    plik>>N;
    plik>>zycia;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            plik>>znak;
            switch (znak)
            {
                case 'G':
                    x1=j;
                    y1=i;
                    break;
                case 'O':
                    _Odkryte[ile].x=j;
                    _Odkryte[ile].y=i;
                    ile++;
                    break;
                case 'B':
                    _listap[bomby].x=j;
                    _listap[bomby].y=i;
                    bomby++;
                    break;
                default:
                    break;
            }
        }
    }
    cout<<"Wczytano";
    Sleep(1000);


}

void wybieranie()
{
    poz=0;
    char klik;
    bool warunek=true;
    drukuj();
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
            drukuj();
        if(klik==13)
        {
            cout<<"Wcisnieto: "<<_Menu[poz].element<<endl;
            Sleep(1000);
            warunek = false;
        }

    } while(warunek);


    if (poz==0)
    {
        czysc();
        losuj_sciezke();
        losuj_bomby();
        rysuj_plansze();
    }
    else if (poz==1)
    {
        if (!czyzaczeta)
        {
            cout<<"Prosze na poczatku rozpoczac gre lub ja wczytac!";
            Sleep(2000);
            wybieranie();
        }
    }
    else if (poz==2)
    {
        zapis();
        wybieranie();
    }
    else if (poz==3)
    {
        wczytaj();
        wybieranie();
    }
    else if (poz==4)
    {
        koniec();
        exit(0);
    }
}

void poruszanie_sprawdzanie()
{
    system("CLS");
    czyzaczeta=true;
    //rysuj_sciezke();
    while(zycia>=0)
        {
            rysuj_plansze();
            char klik=getch();
            switch (klik)
            {
            case 27:
                wybieranie();
                break;
            case 80:
                if (y1<N-1)
                    y1++;
                break;
            case 72:
                if (y1>0)
                    y1--;
                break;
            case 75:
                if (x1>0)
                    x1--;
                break;
            case 77:
                if (x1<N-1)
                    x1++;
                break;
            }
            for (int i=0; i<bomby; i++)
                if ((y1==_listap[i].y)&&(x1==_listap[i].x))
                {
                    _Odkryte[ile].y=_listap[i].y;
                    _Odkryte[ile].x=_listap[i].x;
                    ile++;
                    _listap[i].y=-1;
                    _listap[i].x=-1;
                    zycia--;
                    bomby--;

                }
            if ((x1==N-1)&&(y1==N-1))
            {
                wygrana=true;
                break;
            }
        }
}



int main()
{
        srand(time(NULL));
        while(poz!=4)
        {
            wybieranie();
            poruszanie_sprawdzanie();
            koniec();
        }
        return 0;
}



