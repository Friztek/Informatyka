#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <algorithm>
#include <sstream>


using namespace std;

struct _menu{
    string element;
    bool ding=false;
} _Menu[20];

int licz_el=9, poz=0;

void drukuj()
{
    _Menu[0].element = "Wprowadzenie do C++";
    _Menu[1].element = "Zmienne + Tablice";
    _Menu[2].element = "Wpisywanie i wczytywanie";
    _Menu[3].element = "Funkcje warunkowe i logiczne";
    _Menu[4].element = "Petle";
    _Menu[5].element = "Funkcje";
    _Menu[6].element = "Pseudolosowosc";
    _Menu[7].element = "Biblioteki";
    _Menu[8].element = "Przykladowe programy";

        system("CLS");
        cout<<"    Wybierz lekcje: "<<endl<<endl;
        for(int i=0; i<licz_el; i++)
        {
                if(i==poz)
                    cout<<">";
                else
                    cout<<" ";
                cout << i+1 << ". ";
                cout<<_Menu[i].element<<endl;
        }
}
int wybieranie()
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
            poz+=licz_el;
        else poz%=licz_el;
            drukuj();
        if(klik==13)
        {
            cout<<"Wybrano: "<<_Menu[poz].element<<endl;
            Sleep(600);
            warunek = false;
        }
    } while(warunek);
    return poz+1;
}

int main()
{
    int res = wybieranie();
    cout << res << endl;
    return 0;
}
