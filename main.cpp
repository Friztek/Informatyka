#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <ctime>


using namespace std;

struct _menu{
    string element;
    bool ding=false;
} _Menu[20];

int licz_el=9, poz=0, res, pozPrzyklad=0;

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
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    _Menu[0].element =PL( "Wprowadzenie do C++");
    _Menu[1].element =PL( "Zmienne i tablice"); //ZROOOOBIONE L:DDDD
    _Menu[2].element =PL( "Wpisywanie i wczytywanie"); // ZROOOBIONE
    _Menu[3].element =PL( "Funkcje warunkowe i logiczne");
    _Menu[4].element =PL( "Pętle"); // ZROBIONEEE
    _Menu[5].element =PL( "Funkcje");
    _Menu[6].element =PL( "Pseudolosowość"); //Zrobione
    _Menu[7].element =PL( "Biblioteki");
    _Menu[8].element =PL( "Przykładowe programy"); //Norbert ZROOOOBIONE

        system("CLS"); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout<<PL("    Wybierz lekcję: ")<<endl<<endl; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
        for(int i=0; i<licz_el; i++)
        {
                if(i==poz){
                   SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY); cout<<">";
                   SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
                }
                else
                    cout<<" ";
                SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                cout << i+1 << ". "; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
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
            cout<<" Wybrano: "<<_Menu[poz].element<<endl;
            Sleep(600);
            warunek = false;
        }
    } while(warunek);
    return poz;
}

void Wprowadzenie(){
    int key;
    system("CLS");
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );  SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << PL(" Hej, ten program nauczy Cię podstaw C++!"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL("\n\n Najpierw jednak zadajmy  sobie pytanie, czym jest");  SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << PL(" program");  SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL("?");  SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << PL("\n Program "); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(" (inaczej kod) to szereg symboli i komend w języku,\n który komputer może zrozumieć - czyli w"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << PL(" języku programowania"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(".\n\n Takie języki to na przykład Python, HTML, Ruby czy właśnie C++,\n którego możesz się nauczyć w naszej szkole ;) ");
    cout << PL("\n\n Naciśnij dowolny przycisk aby kontynuować...");
    key=getch();
    if (key==0 || key==224)
        key=getch();
    system("cls");
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << PL(" W świecie programowania jest kilka podstawowych terminów,\n które warto sobie przyswoić:"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << PL("\n\n Kompilacja"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(" - komputer odczytuje i wykonuje program"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << PL("\n\n Środowisko programistyczne"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(" - aplikacja, dzięki której \n możesz tworzyć i kompilować swój kod, np Code::Blocks"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << PL("\n\n Log kompilacji"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(" - informacje o przebiegu kompilacji. Komputer może Ci \n w nim powiedzieć co mu się nie spodobało jeśli wystąpiły błędy"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << PL("\n\n Input"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(" - wartości pobrane do programu z zewnątrz"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << PL("\n\n Output"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(" - wartości zwrócone przez program");
    cout << PL("\n\n Naciśnij dowolny przycisk aby kontynuować...");
    key=getch();
    if (key==0 || key==224)
        key=getch();
    system("cls");
    cout << PL(" Kod piszemy w linijkach. Po niemal każdej linijce MUSISZ pamiętać o"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << PL(" średniku"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(",\n czyli \""); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << PL(";"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL("\" znajdziesz go na prawo od litery L na klawiaturze.");
    cout << PL("\n Jeśli o tym zapominsz, program nie zadziała!");
    cout << PL("\n\n Staraj się też"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << PL(" zapomineć o polskim"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(", w szczególności o polskich znakach.\n Komputer ich nie zrozumie. ");
    cout << PL("\n\n Naciśnij dowolny przycisk aby kontynuować...");
    getch();
    system("cls");
}


void ZmienneTab(){
    int key;
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    string PytOdp[20]={"1. Jak deklaruje"};
    system("CLS"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout<<PL(" Zmienna służy do przechowywania danych: \n"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << PL(" 1. INT (liczba całkowita)\n 2. CHAR (pojedynczy znak)\n 3. FLOAT (liczba zmiennoprzecinkowa)\n 4. STRING (tekst)\n 5. BOOL (prawda/fałsz)\n \n"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << PL(" Przykłady deklarowania zmiennych:"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << PL( "\n int liczba = 4; \n char plec = k; \n float srednia = 3,56; \n string imie = 'Basia'; \n bool = true; \n \n "); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN);
    cout << PL("można nie przypisywać wartości dla zmiennej, np.: \n int a; \n char b; \n \n \n \n" );
    cout<<PL(" ...wciśnij dowolny klawisz aby kontynuować.");
    key=getch();
    if (key==0 || key==224)
        key=getch();
    system("cls");
    cout<<PL(" Do każdej zmiennej można stworzyć "); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << PL("tablicę"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(" - oznacza to, że to jednej zmiennej \n można zadeklarować wiele wartości (odpowiednie to typu zmiennej!). \n Ilość zmienneych wpisujemy przy nazwie tablicy w nawiasy kwadratowe. \n \n"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << PL(" Przykładowe tablice:"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << PL("\n int temperatury[4]; \n char imie[8]; \n \n \n");  SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout<<PL(" ...wciśnij dowolny klawisz aby kontynuować.");
    key=getch();
    if (key==0 || key==224)
        key=getch();
    system("cls"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout<<PL(" Przypisywanie zmiennych do tablicy:" ); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << PL("\n int temperatury[3];" ); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL("---> deklaracja tablicy gdzie można wpisać 3 liczby.");SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << PL("\n temperatury[0]=23; \n temperatury[1]=-9; \n temperatury[2]=13; \n \n *UWAGA! Indeks tablicy zaczynamy liczyć od pozycji nr 0! "); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout<<PL(" \n \n ...wciśnij dowolny klawisz aby kontynuować.");
    getch();
}

void WpisWczyt(){
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    system("CLS");
    cout << PL(" Aby wypisać tekst na ekran w programie, należy użyć strumienia "); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << "std::cout "; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL ("\n Używa się go w ten sposób:  \n \n ");  SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << "std::cout <<  \"Tekst do wyswietlenia\"; \n "; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL("\n Po strumieniu należy wpisać operator \"<< \". Należy pamiętać o nieużywaniu \n polskich znaków. W strumień można wpisać też nazwy zmiennych, by wyświetlić\n ich watość, np: ");
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << " \n \n int wartosc; \n warosc=4; \n cout << wartosc << \"  \" << wartosc+4; ";
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(" \n \n Na ekranie wyświetli się wtedy: \"4   8\" ");
    cout <<PL(" \n \n \n ...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    cout << PL(" Aby w wyświetleniu przejść do nowego wiersza, można użyć albo "); SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << "\\n\""; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN ); cout << " \n albo ";
    SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY ); cout << " << std::endl; \n \n"; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << " cout << \"\\n\"; \n";
    cout << " cout << std::endl; ";
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(" \n \n Podobnie, tabulację wapisuje się ");SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << " cout << \"\\t\" "; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(", a niektóre znaki specjalne, \n typu backslash czy cudzysłowie poprzedza się backslaschem. ");
    cout <<PL(" \n \n \n ...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    cout << PL(" Jednym ze sposobów, by do zmiennej przypisać wartość, jest użycie innego\n strumienia - ");SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << " std::cin"; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN ); cout << PL(", którego operatorem jest \" >>\". Używa się go,\n by w programie podać liczbę: ");
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << "\n \n int a; \n std::cout << \" Podaj liczbe: \"; \n std::cin >> a; ";
    cout << PL(" \n \n Tego strumienia używa się, by później na wczytanej liczbie wykonywać operacje. ");
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(" By uniknąć ciągłego wpisywania std::, można wpisać na początek ");  SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << "using namespace  std; ";
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN);

    cout << "\n \n \n";
    cout<<PL(" ...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");

    int wynik=0;
    char klik='0';
    while (klik!='a' && klik!='b' && klik!='c'){
        system("cls");
        cout << PL(" Czas na test! Wciśnij klawisz a, b lub c na klawiaturze. \n") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
        cout << PL(" Pytanie numer 1: \n Jaki operator jest stosowany przy strumieniu std::cout? \n") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN);
        cout << PL (" a) << ") << endl;
        cout << PL (" b) >> ") << endl;
        cout << PL (" c) std:: ") << endl;
        klik=getch();
    }

    if (klik=='a') cout << PL(" \n Dobra odpowiedź! \n \n"), wynik++;
    else cout << PL(" \n Źle! Przy strumieniu std::cout stosuje się operator << \n \n");
    cout<<PL(" ...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    klik=0;

    while (klik!='a' && klik!='b' && klik!='c'){
        system("cls");
        cout << PL(" Czas na test! Wciśnij klawisz a, b lub c na klawiaturze. \n") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
        cout << PL(" Pytanie numer 2: W jaki sposób nie przechodzi się do kolejnego wiersza w \n strumieniu std::cout? \n") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN);
        cout << PL (" a) cout << endl; ") << endl;
        cout << PL (" b) cout << \"\\n\" ") << endl;
        cout << PL (" c) cout << \"\\t\" ") << endl;
        klik=getch();
    }

    if (klik=='c') cout <<PL(" \n Dobra odpowiedź! \n \n"), wynik++;
    else cout << PL(" \n Źle! \"\\t\" powoduje wyświetlenie tabulacji. \n \n");
    cout<<PL(" ...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    klik=0;

    while (klik!='a' && klik!='b' && klik!='c'){
        system("cls");
        cout << PL(" Czas na test! Wciśnij klawisz a, b lub c na klawiaturze. \n") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
        cout << PL(" Pytanie numer 3: Co zostanie wyświetlone? \n int a=112; \n std::cout << (a+3)/5+6; \n") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN);
        cout << PL (" a) 30") << endl;
        cout << PL (" b) 29 ") << endl;
        cout << PL (" c) (4+3)/5+6 ") << endl;
        klik=getch();
    }

    if (klik=='b') cout << PL(" \n Dobra odpowiedź! \n \n"), wynik++;
    else cout << PL(" \n Źle! Po podstawieniu za a 112 i obliczniu, wynik wynosi 29 \n \n");
    cout<<PL(" ...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    klik=0;

    while (klik!='a' && klik!='b' && klik!='c'){
        system("cls");
        cout << PL(" Czas na test! Wciśnij klawisz a, b lub c na klawiaturze. \n") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
        cout << PL(" Pytanie numer 4: Która komenda nie zawiera błędu? \n int blad; \n") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN);
        cout << PL (" a) std::cin >> blad; ") << endl;
        cout << PL (" b) std::cin << blad; ") << endl;
        cout << PL (" c) std::cout << \"blad\" ") << endl;
        klik=getch();
    }

    if (klik=='a') cout << PL(" \n Dobra odpowiedź! \n \n"), wynik++;
    else cout << PL(" \n Źle! Operatorem strumienia std::cin jest \">>\", a w odpowiedzi c brakuje \n średnika. \n \n");
    cout<<PL(" ...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    klik=0;

    while (klik!='a' && klik!='b' && klik!='c'){
        system("cls");
        cout << PL(" Czas na test! Wciśnij klawisz a, b lub c na klawiaturze. \n") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
        cout << PL(" Pytanie numer 5: Która komenda służy do przejścia do następnego wiersza? \n") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN);
        cout << PL (" a) std:: cout << \"ednl\"; ") << endl;
        cout << PL (" b) std:: cout << endl;") << endl;
        cout << PL (" c) std:: cout << ednl; ") << endl;
        klik=getch();
    }

    if (klik=='b') cout << PL(" \n Dobra odpowiedź! \n \n"), wynik++;
    else cout << PL(" \n Źle! W odpowiedzi a wyświetli się tekst, a w c jest literówka. \n \n");
    cout<<PL(" ...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    cout << PL( " Koniec testu! Twój wynik to ") << wynik << PL("/5.");


}

void FunkcWarunLogiczne(){
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    system("CLS");
    cout << PL(" Funkcje warunkowe mówią nam o tym, co ma się stać, jeśli coś zostanie \n spełnione. ");SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << "if(???)...; \n "; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL("W miejsce znaków zapytania wpisuje się warunek, czyli funkcje \n logiczne, a w miejsce kropek - co ma się stać, gdy będzie on spełniony. Funkcje \n logiczne działają w c++ tak samo jak w matematyce: \n");
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << " int a; \n \n if (a>4) a=a-3; "; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(" Jeśli a jest większe niż 4, zmniejsz a o 3. \n "); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << "if (a<=4) a=a/2;; "; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(" Jeśli a jest mniejsze lub równe 4, a podziel przez 2. \n "); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << "if (a==4) a=0; "; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(" Jeśli a jest równe 4, za a podstaw 0. \n \n \n "); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN);
    cout<<PL(" ...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    cout << PL(" Po funkcji if można dodać funkcję "); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY ); cout << "else... ";SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(" Funkcja else mówi o tym, co zrobić,  gdy warunek w if nie zostanie spełniony: \n"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << " \n int m; \n if (m>30) cout << m; \n else cout << m/2;"; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(" Czyli: jeśli m jest większe od 30, wyświetl m. \n W przeciwnym razie wyświetl m podzielone przez 2. \n Do else można dodawać if, "); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY ); cout << "else if (???) ...";
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << "\n \n int l; \n if (l>0) cout << \"dodatnia\"; \n else if (l==0) cout << \"zero\"; \n else cout << \"ujemna\"; "; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL( "\n \n Czyli: Jeśli l jest większe od 0, wyświetl \"dodatnia\", w przeciwnym razie, \n jeśli l jest równe 0 wyświetl \"zero\", w przeciwnym razie wyświetl \"ujemna\". ");
    cout<< PL("\n \n \n ...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    cout << PL(" W jednej funkcji warunkowej można zmieścić kilka różnych warunków: "); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << "\n int a; if (a==0 || a==2) cout << a; "; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(" \n Czyli: jeśli a jest równe 0 lub a jest równe 2 wyświetl a. ");SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << " \n \n int b; \n if (b>0 && b<100) b=b/2; "; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL( "\n Czyli: jeśli b jest większe od 0 i jeśli jest mniejsze od 100, \n podziel b przez 2. ");
    cout << "\n \n \n";
    cout<<PL(" ...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");


    int wynik=0;
    char klik='0';
    while (klik!='a' && klik!='b' && klik!='c'){
        system("cls");
        cout << PL(" Czas na test! Wciśnij klawisz a, b lub c na klawiaturze. \n") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
        cout << PL(" Pytanie numer 1: Jak zapisuje się pierwszą funkcję warunkową?\n") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
        cout << PL (" a) else (warunek) instrukcja; ") << endl;
        cout << PL (" b) else if (warunek) instrukcja; ") << endl;
        cout << PL (" c) if(warunek) instrukcja; ") << endl;
        klik=getch();
    }

    if (klik=='c') cout << PL("\n Dobra odpowiedź! \n \n"), wynik++;
    else cout << PL("\n Źle! Else i else if nie mogą występować bez uprzedniej funkcji warunkowej. \n \n");
    cout<<PL(" ...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    klik=0;

    while (klik!='a' && klik!='b' && klik!='c'){
        system("cls");
        cout << PL(" Czas na test! Wciśnij klawisz a, b lub c na klawiaturze. \n") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
        cout << PL(" Pytanie numer 2: Jaka będzie wartość końcowa dla a równego 3?\n") ; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY);
       cout << "\n int a; \n if (a==0) a=a+2; \n else if (a>7) a=2; \n else a=a*2; " << endl << endl; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
        cout << PL (" a) 5 ") << endl;
        cout << PL (" b) 6 ") << endl;
        cout << PL (" c) 2 ") << endl;
        klik=getch();
    }

    if (klik=='b') cout <<PL("\n Dobra odpowiedź! \n \n"), wynik++;
    else cout << PL("\n Źle! 3 nie jsst równe 0 i nie jest większe od 7, więc zostanie spełniony trzeci warunek. \n \n");
    cout<<PL(" ...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    klik=0;

    while (klik!='a' && klik!='b' && klik!='c'){
        system("cls");
        cout << PL(" Czas na test! Wciśnij klawisz a, b lub c na klawiaturze. \n") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
        cout << PL(" Pytanie numer 3: Jak zapisuje się \"lub\" funkcją logiczną? \n") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
        cout << PL (" a) || ") << endl;
        cout << PL (" b) && ") << endl;
        cout << PL (" c) &| ") << endl;
        klik=getch();
    }

    if (klik=='a') cout <<PL("\n Dobra odpowiedź! \n \n"), wynik++;
    else cout << PL("\n Źle! \"lub\" Zapisuje się poprzez dwie kreski pionowe \n \n");
    cout<<PL(" ...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    klik=0;

    while (klik!='a' && klik!='b' && klik!='c'){
        system("cls");
        cout << PL(" Czas na test! Wciśnij klawisz a, b lub c na klawiaturze. \n") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
        cout << PL(" Pytanie numer 4: Która komenda zawiera błąd? \n"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << " int blad; \n" << endl; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
        cout << PL (" a) if (blad>0) cout << blad; ") << endl;
        cout << PL (" b) if (blad<0) cout << blad; ") << endl;
        cout << PL (" c) if (blad=0) cout << blad; ") << endl;
        klik=getch();
    }

    if (klik=='c') cout <<PL("\n Dobra odpowiedź! \n \n"), wynik++;
    else cout << PL("\n Źle! Aby stworzyć warunek równości należy wspisać podwójnie znak równości. \n \n");
    cout<<PL(" ...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    klik=0;

    while (klik!='a' && klik!='b' && klik!='c'){
        system("cls");
        cout << PL(" Czas na test! Wciśnij klawisz a, b lub c na klawiaturze. \n") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
        cout << PL(" Pytanie numer 5: Jak zapisuje się \"i\" w funkcją logiczną? \n") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
        cout << PL (" a) %% ") << endl;
        cout << PL (" b) && ") << endl;
        cout << PL (" c) $$ ") << endl;
        klik=getch();
    }

    if (klik=='b') cout <<PL("\n Dobra odpowiedź! \n \n"), wynik++;
    else cout << PL("\n Źle! \"i\" zapisuje się przez \"&&\". \n \n");
    cout<<PL(" ...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    cout << PL( " Koniec testu! Twój wynik to ") << wynik << PL("/5.");


}

struct menu{
    string el;
} menuuu[4];

int licz=4, po=0;

void drukuj2()
{
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );

    menuuu[0].el =PL( "FOR");
    menuuu[1].el =PL( "WHILE");
    menuuu[2].el =PL( "DO WHILE");
    menuuu[3].el =PL("QUIZ");

        system("CLS");
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
        cout<<PL(" ---PĘTLE---"); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
        cout << PL(" \n Istnieją 3 podstawowe pętle: FOR, WHILE i DO WHILE.\n Dzięki nim możemy powtarzać jakąś czynność tyle razy ile potrzebujemy. \n "); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << PL("\n WYBIERZ PĘTLE, KTÓRĄ CHCESZ POZNAĆ: \n \n"); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);

        for(int i=0; i<licz; i++)
        {
                if(i==po)
                    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY), cout<<">", SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
                else
                     cout<<" ";
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY); cout << i+1 << ". "; SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
                cout<<menuuu[i].el<<endl;
        }

        cout<<PL("\n \n \n ...aby wrócić do menu wciśnij klawisz Esc");
}

void FOR(){
    system("CLS");
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout<<PL(" -------FOR-------"); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
    cout << PL(" \n \n Używamy np.: gdy chcemy wpisać 20 liczb do tablicy - zamiast piać 20 razy \n \"cin>>tab[0]\n cin>>tab[1] \n cin>>tab[2]...\" \n można to zapisać w petli FOR wykonującej się 20 razy.\n \n \n");
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << PL(" JAK STWORZYĆ PĘTLE FOR:");  SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
    cout << PL( "\n \n (od jakiej wartości liczbowej zaczynamy - dowolna liczba całkowita np:4 ; \n do jakiej wartości chcemy dojść ; \n co się dzieje z tą liczbą (maleje czy rośnie o jeden)\n \n"); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << PL(" for (int liczba ; do jakiej watrości ; maleje czy rośnie) ){\n  \n        KOD KTÓRY MA SIĘ POWTARZAĆ } \n \n \n \n"); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
    cout<<PL(" ...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");

    cout<<PL(" PRZYKŁAD:"); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << PL("\n \n for (int i=4; i<=23; i++){ \n       cin>>a; } "); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
    cout << PL("\n\n Kod ten powtarza się 19 razy - zaczyna się kiedy i=4, z każdym kolejnym \n wykonaniem rośnie o jeden (i++ to inaczej i=i+1). \n \n"); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << " DODATKOWE INFORMACJE:"; SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
    cout << PL(" \n \n 1) można pomniejszać tą liczbę (zamiast i++ -> i--). \n Wtedy deklarujemy wykonywanie pętli dopóki i jest WIĘKSZE od jakieś wartości. \n \n 2. nieskończona pętla (wykonuje się w nieskończoność -> for ( ; ; ){ \n kod } \n \n \n");
    cout<<PL(" ...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    drukuj();

}

void WHILE(){
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    system("CLS");
    cout<<PL(" ---JAK STWORZYĆ PĘTLĘ WHILE---"); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
    cout << PL("\n while (pętla wykonuje się dopóki warunek jest spełniony){ \n    KOD KTÓRY MA SIĘ POWTARZAĆ} \n \n "); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << PL("PRZYKŁAD:"); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
    cout << PL(" \n int i=0; \n while (i<=5){ \n cout<<i<<endl; \n i++; } \n \n \n");

     cout<<PL(" ...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    drukuj();

}

void DO_WHILE(){
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    system("cls");
    cout<<PL(" JAK STWORZYĆ PĘTLE DO WHILE:"); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
    cout << PL("\n do {KOD KTÓRY MA SIĘ POWTARZAĆ} \n while(warunek); \n"); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << PL(" PRZYKŁAD: "); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
    cout << PL("\n int i=0; \n do {cout<<i<<endl; \n i++} \n while (i<=5); \n \n \n"); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << PL(" RÓŻNICA MIĘDZY WHILE I DO WHILE: "); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
    cout << PL("\n \n WHILE sprawdza najpierw warunek, który ma być spełniony. Dopiero kiedy jest \n on spełniony wykonuje czynność zawartą w nawiasach {}. \n DO WHILE przez swoją budowę, najpierw wykonuje się czynność zapisana \n w nawiasach, a gdy warunek, który znajduje się po kodzie jest spełniony, pętla  wykonuje się jeszcze raz. \n \n Ostatecznie, różnica między nimi jest taka, że DO WHILE zawsze wykona się \n przynajmniej raz,gdyż sprawdza warunek dopiero po wykonaniu się kodu.");
    getch();
    drukuj();

}

void TEST(){
    char odp;
    int punkty =0;
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    system("cls");
    cout<<PL("Zróbmy mały QUIZ: \n  (wybierz poprawną odpowiedź - wciśnij odpowiednią literkę) \n \n"); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout<<PL("1) W funkcji FOR w nawiasach mówiącyh o warunkach w jakich powtarza się ta \n petla, są potrzebne: \n \n"); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
    cout << PL(" a) trzy warunki \n b) dwa warunki \n c) jednen warunek \n ");
        cin>>odp;

    if (odp=='a' || odp=='A'){
        cout<<PL(" POPRAWNA ODPOWIEDŹ! \n \n \n");
        punkty++;
    }
    else cout<<PL(" \n ŹLE! poprawna odpowiedź: a \n \n \n");

    cout<<PL("...kliknij dowolny klawisz aby kontynuować");
    getch();
    system ("cls");

    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout<<PL("2) Do rozdzielenia warunkóww funkcji FOR używamy: "); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
    cout << PL("\n \n a) , \n b) : \n c) ; \n ");
        cin>>odp;

    if (odp=='c' || odp=='C'){
        cout<<PL(" POPRAWNA ODPOWIEDŹ! \n \n \n");
        punkty++;
    }
    else cout<<PL(" \n ŹLE! poprawna odpowiedź: c \n \n \n");

    cout<<PL("...kliknij dowolny klawisz aby kontynuować");
    getch();
    system ("cls");

    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
     cout<<PL("3) Kod ,,właściwy\" każdej pętli znajdyje się w nawiasach: "); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
     cout << PL("\n \n a) () \n b) {} \n c) [] \n ");
        cin>>odp;

    if (odp=='b' || odp=='B'){
        cout<<PL("POPRAWNA ODPOWIEDŹ! \n \n \n ");
        punkty++;
    }
    else cout<<PL(" \n ŹLE! poprawna odpowiedź: b \n \n \n");

    cout<<PL("...kliknij dowolny klawisz aby kontynuować");
    getch();
    system ("cls");

    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
     cout<<PL("4) Liczbę zadeklarowaną w warunku pętli FOR można:"); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
     cout << PL(" \n \n a) dodawać \n b) odejmować \n c) obie odpowiedzi są poprawne \n ");
        cin>>odp;

    if (odp=='c' || odp=='C'){
        cout<<PL(" POPRAWNA ODPOWIEDŹ! \n \n \n");
        punkty++;
    }
    else cout<<PL(" \n ŹLE! poprawna odpowiedź: c \n \n \n ");

    cout<<PL("...kliknij dowolny klawisz aby kontynuować");
    getch();
    system ("cls");

    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
     cout<<PL("5) Czym rózni się pętla WHILE od DO WHILE? "); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
     cout << PL("\n \n a) niczym \n b) pętla DO WHILE wykonuje się zawsze przynajmniej raz* \n c) pętla WHILE wykonuje się zawsze przynajmniej raz* \n \n \n \n *ze względu na swoją budowę \n \n \n");
        cin>>odp;

    if (odp=='b' || odp=='B'){
        cout<<PL(" POPRAWNA ODPOWIEDŹ! \n \n \n");
        punkty++;
    }
    else cout<<PL(" \n ŹLE! poprawna odpowiedź: b \n \n \n");

    cout<<PL("...kliknij dowolny klawisz aby kontynuować");
    getch();
    system ("cls");

    cout<<PL("-----KONIEC QUIZU!-----");

    if(punkty>=3){
        cout<<PL("Brawo! udało Ci się przejść pomyślnie test - odpowiedziałeś dobrze na minimalnie 3 odpowiedzi");
    }
    else {cout<<PL("Niestety, Twój wynik nie jest za dobry - odpowiedziałeś źle na więcej nż 2 odpowiedzi \n \n RADZIMY - przejrzyj informacje o pętlach jeszcze raz");
    }
}

void petle_wyb()
{  char klik;
    while (klik!=27){
    po=0;

    bool warunek=true;
    drukuj2();
    do{
        klik=getch();
        switch (klik)
        {
            case 72:
                po--;
                break;
            case 80:
                po++;
                break;
            case 27:
                po=0;
                return;
                break;
        }
        if(po<0)
            po+=licz;
        else po%=licz;
            drukuj2();
        if(klik==13)
        {
            warunek = false;
        }
    } while(warunek);
     switch (po)
    {
        case 0: FOR();
        break;
        case 1: WHILE();
        break;
        case 2: DO_WHILE();
        break;
        case 3: TEST();
        break;

    }

}

}
void Funkcje(){
    HANDLE hOut;
                hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    system("CLS");
    cout << PL(" Funkcja jest nazwanym fragmentem programu. Podobnie jak zmienne, są różne typy  funkcji, takie jak int, char, bool, void (kiedy funkcja nie zwraca wartości). \n W zależności od tego różny typ zmiennej będzie zwracany. Funkcje zapisuje się\n w ten sposób: "); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << " \n \n typ_zmiennej nazwa_funkcji (argumenty_funkcji) { return zwracana_wartosc; }  \n \n"; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout <<" np: \n" ; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << " int obwod_kwadratu (int dlugosc_boku) { return dlugosc_boku*4; } \n \n"; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(" Return zwraca wartośc odpowiednią dla typu funkcji, czyli int zwraca liczbę, \n bool prawdę lub fałsz, a void nie zwraca nic. Liczba argumentów w funkcji jest  dowolna, zapisuje się wtedy zawsze typ zmiennej i kończy średnikiem. Funkcja \n może też nie mieć żadnego argumentu. Od momentu deklaracji w dalszym kodzie \n korzystać z funkcji. ");
    cout<<PL(" \n \n ...kliknij dowolny klawisz aby kontynuować");
    getch();
    system ("cls");
    cout << PL(" Aby skorzystać z napisanej funkcji trzeba napisać jej nazwę i potrzebne argumenty. Jeśli zwraca warość daje się ją jako zwracaną warość zmeinnej, np: \n \n");
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << " int bok; int obwod; \n cin >> bok; \n pole=obwod_kwadratu(bok);";SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );


    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
}

void Pseudolosowosc(){
                HANDLE hOut;
                hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    system("CLS");
    cout << PL(" W niektórych programach przydatne może być losowanie liczb. W bibliotece \n cstdlib znajduje się funkcja ");
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << PL("rand();");
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(" która losuje liczbę całkowitą nieujemną. \n Używa jej się w ten sposób: \n \n ");
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << PL("cout << rand(); \n \n");
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
                cout << PL(" Podane poniżej wartości są wygenerowane właśnie przez losowanie: ");
                cout << endl;
                cout << " Pierwsze losowanie: " << rand()<< endl;
                cout << " Pierwsze losowanie: "<< rand()<< endl;
                cout << " Pierwsze losowanie: "<< rand()<< endl;
                cout << "\n \n";
                cout<<PL(" ...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    cout << PL (" Używanie tej funkcji ma jednak poważną wadę: zawsze losuje te same liczby. \n Po uruchomieniu programu ponownie, można zauważyć że liczby nie zmieniły się. \n Jednak istnieje też inna funkcja - ");
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << PL("srand(),");
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(" która ustawia punkt startowy dla \n losowania. Po użyciu jej, dalej korzysta się z funkcji rand, by losować liczby: ");
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
                cout << PL(" \n srand(wartość); \n cout << rand(); \n ") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
                cout << PL(" Oznacza to tylko tyle, że liczby będą inne. Korzystając z biblioteki ctime, \n można pod wartość w funkcji srand podstawić funckję");
                SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
                cout << " time(NULL); "; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
                cout << PL("co uzależnia \n punkt startowy od czasu. Dzięki temu punkt startowy zawsze będzie inny. \n \n");
                SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
                cout << " srand(time(NULL)); \n cout << rand(); \n \n";
                cout << "\n \n";
                SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
                cout<<PL(" ...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    cout << PL( " Połączenie tych dwóch funkcji nazywane jest pseudolosowością. \n");
                cout << PL(" \n By ustalić zakres losowania, można skorzystać z reszty z dzielenia (modulo). \n W C++ zapisuje się to na przykład w ten sposób: \n \n 10%6; wynikiem będzie 4, bo 10:6 to 1 reszty 4. \n 7%7; wynikiem będzie 0, bo 7:7 to 1 reszty 0. \n \n");
    cout << PL(" W ten sposób można uzyskać losową liczbę z przedziału od 0 do 99: ");
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << PL("\n \n srand(time(NULL)); \n rand()%100; \n \n");
    srand(time(NULL));
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << " Pierwsze losowanie: " << rand()%100<< endl;
                cout << " Pierwsze losowanie: "<< rand()%100<< endl;
                cout << " Pierwsze losowanie: "<< rand()%100<< endl;
                cout << "\n \n";
                cout<<PL(" ...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    cout << PL (" Oczywiście można w ten sposób uzyskać różne przedziały, na przykład: \n \n srand(time(NULL)); \n (rand()%36)+5; wylosuje liczbę od 5 do 41, \n (rand()%13)-9; wylosuje liczbę od -9 do 4, a \n (rand()%51)*(-1) wylosuje liczbę od -50 do 0. \n");
    cout << PL ("\n ...Czas na test! Wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");

    int wynik=0;
    char klik='0';
    while (klik!='a' && klik!='b' && klik!='c'){
                        system("cls");
                        cout << PL(" Czas na test! Wsićnij klawisz a, b lub c na klawiaturze. \n") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
                        cout << PL(" Pytanie numer 1: w jakiej bibliotece znajduje się funkcja rand()? ") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
                        cout << PL (" a) ctime ") << endl;
                        cout << PL (" b) cstdlib ") << endl;
                        cout << PL (" c) conio.h ") << endl;
                        klik = getch();
    }

    if (klik=='b') cout << PL("Dobra odpowiedź! \n \n"), wynik++;
    else cout << PL("Źle! Funkcja rand() znajduje się w bibliotece cstdlib. \n \n");
    cout<<PL("...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    klik=0;

    while (klik!='a' && klik!='b' && klik!='c'){
                        system("cls");
                        cout << PL(" Czas na test! Wsićnij klawisz a, b lub c na klawiaturze. \n") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
                        cout << PL(" Pytanie numer 2: Która funkcja ustawia punkt startowy dla losowanych liczb?") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
                        cout << PL (" a) srand(); ") << endl;
                        cout << PL (" b) time(NULL); ") << endl;
                        cout << PL (" c) start(); ") << endl;
                        klik=getch();
    }

    if (klik=='a') cout << "Dobra odpowiedź! \n \n", wynik++;
    else cout << PL("Źle! Funkcja srand() ustawia punkt startowy dla losowanych liczb. \n \n");
    cout<<PL("...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    klik=0;

    while (klik!='a' && klik!='b' && klik!='c'){
                        system("cls");
                        cout << PL(" Czas na test! Wsićnij klawisz a, b lub c na klawiaturze. \n") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
                        cout << PL(" Pytanie numer 3: Jaka jest możliwa największa wartość dla zmiennej a? \n int a; \n srand(time(NULL)); \n a=(rand()%40)+1; \n") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
                        cout << PL (" a) 39 ") << endl;
                        cout << PL (" b) 40 ") << endl;
                        cout << PL (" c) 41 ") << endl;
                        klik=getch();
    }

    if (klik=='b') cout << "Dobra odpowiedź! \n \n", wynik++;
    else cout << PL("Źle! Reszta z dzielenia przez 40 jest w przedziale od 0 do 39, a po dodaniu liczby 1 przedział zmienia się na od 1 do 40. \n \n");
    cout<<PL("...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    klik=0;

    while (klik!='a' && klik!='b' && klik!='c'){
        system("cls");
        cout << PL(" Czas na test! Wsićnij klawisz a, b lub c na klawiaturze. \n") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
        cout << PL(" Pytanie numer 4: Jaka jest możliwa najmniejsza wartość dla zmiennej b? \n float b; \n srand(time(NULL)); \n b=((rand()%250)+250)/100; \n") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
        cout << PL (" a) 2,5 ") << endl;
        cout << PL (" b) 4,99 ") << endl;
        cout << PL (" c) 5 ") << endl;
        klik=getch();
    }

    if (klik=='a') cout << "Dobra odpowiedź! \n \n", wynik++;
    else cout << PL("Źle! Liczba losowana jest z przedziału <0; 249>, po dodaniu zmienia się on na <250; 499>, a po podzieleniu na <2,5; 4,99>. \n \n");
    cout<<PL("...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    klik=0;

    while (klik!='a' && klik!='b' && klik!='c'){
    system("cls");
    cout << PL(" Czas na test! Wsićnij klawisz a, b lub c na klawiaturze. \n") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << PL(" Pytanie numer 5: Która funkcja wylosuje dla zmiennej c liczbę z przedziału od 8 do 46? \n srand(time(NULL); \n int c; \n") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL (" a) c=rand(8)%34;") << endl;
    cout << PL (" b) c=rand()%33+8") << endl;
    cout << PL (" c) c=rand()%35+8; ") << endl;
    klik=getch();
    }

    if (klik=='c') cout << "Dobra odpowiedź! \n \n", wynik++;
    else cout << PL("Źle! rand()%35 wylosuje liczbę od 0 do 34, po dodaniu 8 będzie to liczba od 8 do 42. \n \n");
    cout<<PL("...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    cout << PL( " Koniec testu! Twój wynik to ") << wynik << PL("/5.");

}


void Biblioteki(){
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    system("CLS");
    cout<<PL("Biblioteki są niezbędne w programowaniu, dzięki nim możemy uzyskać dostęp do \nróżnych funkcjii. Poczynając od cout'ów, kończąc na funkcjach sortujących\n\n");
    cout<<PL("Deklarujemy je zawsze na początku kodu, "); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << "\"#include <NazwaBiblioteki>\","; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL("\nmożemy dodać ich dowolną ilość, ale dla lepszej wydajności deklarujemy tylko te używane\n\n");
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout<<PL("Często stosowane biblioteki: "); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout <<PL("\n1. iostream "); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL("- umożliwia korzystanie z wypisywania i wczytywania (cout, cin)\n"); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout<<PL("2. fstream "); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL("- pozwala na wczytywanie z i zapisywanie do pliku\n"); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout<<PL("3. conio.h "); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL("- znajduje się w niej przydatna funkcja getch(),\nktora odczytuje 1 znak podany przez użytkownika,\njest to niezbędne przy tworzeniu menu itp.\n"); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout<<PL("4. ctime "); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL("- pobiera lokalny czas z komputera\n"); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout<<PL("5. windows.h"); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(" - przydatna funkcja sleep(CzasWMilisekundach),\nktóra zatrzymuje działanie programu na określony czas\n"); SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout<<PL("6. math.h "); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL("- pozwala na stosowanie funkcji matematycznych, np. sqr() - kwadrat\ndanej liczby lub sqrt() - pierwiastek");
    cout<<PL("\n\n...wciśnij dowolny klawisz aby kontynuować.");
    getch();
}

void PrzykladoweProgramyPomoc(string NazwaPliku){
        system("CLS");
        fstream plik;
        string pomoc;
        plik.open(NazwaPliku.c_str(), ios::in);
        cout<<char(218);
        for (int i=0; i<78; i++)
            cout<<char(196);
        cout<<char(191)<<endl;
        while (!plik.eof())
        {
            getline(plik,pomoc);
            cout<<pomoc<<endl;
        }
        cout<<char(192);
        for (int i=0; i<78; i++)
            cout<<char(196);
        cout<<char(217);
        plik.close();
        cout<<PL("Wciśnij dowolny klawisz aby kontynuować...");
        char klik = getch();
        if (klik==77 && pozPrzyklad<4)
            pozPrzyklad++;
        if (klik==75 && pozPrzyklad>0)
            pozPrzyklad--;

        system("cls");
}

void PrzykladoweProgramy(){
    while(pozPrzyklad<4)
    {
        if (pozPrzyklad==0)
            PrzykladoweProgramyPomoc("program1.txt");
        else if  (pozPrzyklad==1)
            PrzykladoweProgramyPomoc("program2.txt");
        else if  (pozPrzyklad==2)
            PrzykladoweProgramyPomoc("program3.txt");
        else if  (pozPrzyklad==3)
            PrzykladoweProgramyPomoc("program3_2.txt");
    }
    pozPrzyklad=0;
}

int main()
{

    while(true)
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
            case 4: petle_wyb();
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
    }
    return 0;
}
