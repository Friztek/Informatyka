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

int licz_el=9, poz=0, res;

string PL( const char * text )
{
    string result;
    for(; * text; text++ )
    switch( * text )
    {
    case 'ą': result += static_cast < char >( 0xa5 ); break;
    case 'ć': result += static_cast < char >( 0x86 ); break;
    case 'ę': result += static_cast < char >( 0xa9 ); break;
    case 'ł': result += static_cast < char >( 0x88 ); break;
    case 'ń': result += static_cast < char >( 0xe4 ); break;
    case 'ó': result += static_cast < char >( 0xa2 ); break;
    case 'ś': result += static_cast < char >( 0x98 ); break;
    case 'ż': result += static_cast < char >( 0xbe ); break;
    case 'ź': result += static_cast < char >( 0xab ); break;
    case 'Ą': result += static_cast < char >( 0xa4 ); break;
    case 'Ć': result += static_cast < char >( 0x8f ); break;
    case 'Ę': result += static_cast < char >( 0xa8 ); break;
    case 'Ł': result += static_cast < char >( 0x9d ); break;
    case 'Ń': result += static_cast < char >( 0xe3 ); break;
    case 'Ó': result += static_cast < char >( 0xe0 ); break;
    case 'Ś': result += static_cast < char >( 0x97 ); break;
    case 'Ż': result += static_cast < char >( 0xbd ); break;
    case 'Ź': result += static_cast < char >( 0x8d ); break;
        default: result += * text; break;
    }
    return result;
}
void drukuj()
{
    _Menu[0].element =PL( "Wprowadzenie do C++");
    _Menu[1].element =PL( "Zmienne i tablice"); //ZROOOOBIONE L:DDDD
    _Menu[2].element =PL( "Wpisywanie i wczytywanie");
    _Menu[3].element =PL( "Funkcje warunkowe i logiczne");
    _Menu[4].element =PL( "Pętle"); // Madzia
    _Menu[5].element =PL( "Funkcje");
    _Menu[6].element =PL( "Pseudolosowość"); //Basia
    _Menu[7].element =PL( "Biblioteki");
    _Menu[8].element =PL( "Przykładowe programy"); //Norbert

        system("CLS");
        cout<<PL("    Wybierz lekcję: ")<<endl<<endl;
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
    return poz;
}
void Wprowadzenie(){
    system("CLS");
    //cout
    cout<<PL("Hej, ten program nauczy Cię podstaw c++. \n\n średniki, jezyk polski zakazany, co to deklaracja, INDEKS (?)");
}
void ZmienneTab(){
    string PytOdp[20]={"1. Jak deklaruje"};
    system("CLS");
    cout<<PL("ZMIENNA służy do przechowywania danych: \n 1. INT (liczba całkowita)\n 2. CHAR (pojedynczy znak)\n 3. FLOAT (liczba zmiennoprzecinkowa)\n 4. STRING (tekst)\n 5. BOOL (prawda/fałsz)\n \n PRZYKŁADY DEKLAROWANIA ZMIENNYCH: \n int liczba = 4; \n char plec = k; \n float srednia = 3,56; \n string imie = 'Basia'; \n bool = true; \n \n *można nie przypisywać wartości dla zmiennej, np.: \n int a; \n char b; \n \n \n \n" );
    cout<<PL("...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    cout<<PL(" Do każdej zmiennej można stworzyć TABLICE - oznacza to, że to jednej zmiennej \n można zadeklarować wiele wartości (odpowiednie to typu zmiennej!). \n Ilość zmienneych wpisujemy przy nazwie tablicy w nawiasy kwadratowe. \n \n PRZYKŁADOWE TABLICE: \n int temperatury[4]; \n char imie[8]; \n \n \n");
    cout<<PL("...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    cout<<PL("PRZYPISYWANIE ZMIENNYCH DO TYBLICY: \n int temperatury[3]; ---> deklaracja tablicy gdzie można wpisać 3 liczby. \n temperatury[0]=23; \n temperatury[1]=-9; \n temperatury[2]=13; \n \n *UWAGA! Indeks tablicy zaczynamy liczyć od pozycji nr 0! ");
    cout<<PL("...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    cout<<" Czas na test!"<<endl;
    for (int i=0; i<5; i++)
    {
        cout<<"Pytanie numer "<<i<<endl;

    }

}


void WpisWczyt(){
    system("CLS");
    cout<<2;
}

void FunkcWarunLogiczne(){
    system("CLS");
    cout<<3;
}

void Petle(){
    system("CLS");
    cout<<4;
}

void Funkcje(){
    system("CLS");
    cout<<5;
}

void Pseudolosowosc(){
    system("CLS");
    cout<<6;
}

void Biblioteki(){
    system("CLS");
    cout<<7;
}

void PrzykladoweProgramy(){
    system("CLS");
    cout<<8;
}

int main()
{
    int res = wybieranie();
    switch (res)
    {
        case 0: Wprowadzenie();
        break;
        case 1: ZmienneTab();
        break;
        case 2: WpisWczyt();
        break;
        case 3: FunkcWarunLogiczne();
        break;
        case 4: Petle();
        break;
        case 5: Funkcje();
        break;
        case 6: Pseudolosowosc();
        break;
        case 7: Biblioteki();
        break;
        case 8: PrzykladoweProgramy();
        break;
    }
    return 0;
}
