#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <string>
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
    _Menu[0].element =PL( "Wprowadzenie do C++");
    _Menu[1].element =PL( "Zmienne i tablice"); //ZROOOOBIONE L:DDDD
    _Menu[2].element =PL( "Wpisywanie i wczytywanie"); // ZROOOBIONE
    _Menu[3].element =PL( "Funkcje warunkowe i logiczne");
    _Menu[4].element =PL( "Pętle"); // ZROBIONEEE
    _Menu[5].element =PL( "Funkcje");
    _Menu[6].element =PL( "Pseudolosowość"); //Zrobione
    _Menu[7].element =PL( "Biblioteki");
    _Menu[8].element =PL( "Przykładowe programy"); //Norbert ZROOOOBIONE

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
    cout << PL("Hej, ten program nauczy Cię podstaw C++. \nNajpierw jednak zadajmy  sobie pytanie, czym jest program? \nProgram (inaczej kod) to szereg symboli i komend w języku, który komputer może zrozumieć - czyli w języku programowania.");
    cout << PL("\nbTakie języki to na przykład Python, HTML, Ruby czy C++, którego możesz się nauczyć w naszej szkole ;) ");
    cout << PL("\nW świecie programowania jest kilka podstawowych terminów, które warto sobie przyswoić:");
    cout << PL("\nKompilacja - komputer odczytuje i wykonuje program");
    cout << PL("\nŚrodowisko programistyczne - aplikacja, dzięki której możesz tworzyć i kompilować swój kod, np Code::Blocks");
    cout << PL("\nLog kompilacji - informacje o przebiegu kompilacji. Komputer może ci w nim powiedzieć co mu się nie spodobało jeśli wystąpiły błędy");
    cout << PL("\nInput - wartości pobrane do programu z zewnątrz");
    cout << PL("\nOutput - wartości zwrócone przez program");
    cout << PL("\nKod piszemy w linijkach. Po niemal każdej linijce MUSISZ pamiętać o średniku, czyli \";\" znajdziesz go na prawo od litery L na klawiaturze.");
    cout << PL("\nJeśli o tym zapominsz, program nie zadziała!");
    cout << PL("\nStaraj się też zapomineć o polskim, w szczególności o polskich znakach. Komputer ich nie zrozumie. ");
    cout << PL("\nNaciśnij dowolny przycisk aby kontynuować...");
    getch();
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
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    system("CLS");
    cout << PL(" Aby wypisać tekst na ekran w programie, należy użyć strumienia "); SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << "std::cout "; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL (" Używa się go w ten sposób:  \n \n ");  SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << "std::cout <<  \"Tekst do wyswietlenia\"; \n "; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL("\n Po strumieniu należy wpisać operator \"<< \". Należy pamiętać o nieużywaniu \n polskich znaków. W strumień można wpisać też nazwy zmiennych, by wyświetlić ich watość, np: ");
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
    cout << " cout << \"\\n\"; \n ";
    cout << " cout << std::endl; ";
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(" \n \n Podobnie, tabulację wapisuje się ");SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << " cout << \"\\t\" "; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(", a niektóre znaki specjalne, \n typu backslash czy cudzysłowie poprzedza się backslaschem. ");
    cout <<PL(" \n \n \n ...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    cout << PL(" Jednym ze sposobów, by do zmiennej przypisać wartość, jest użycie innego strumienia - ");SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << " std::cin"; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN ); cout << PL(", któego operatorem jest \" >>\". Używa się go, by w programie podać liczbę: ");
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
    cout << "\n \n int a; \n std::cout << \" Podaj liczbe: \"; \n std::cin >> a; ";
    cout << PL(" \n \n Tego strumienia używa się, by później na wczytanej liczbie wykonywać operacje. ");
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(" By uniknąć ciągłego wpisywania std::, można wpisać na początek ");  SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << "using namespace  std; ";
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN);

    cout << "\n \n \n";
    cout<<PL("...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");

    int wynik=0;
    char klik;
    while (klik!='a' && klik!='b' && klik!='c'){
        system("cls");
        cout << PL(" Czas na test! Wsićnij klawisz a, b lub c na klawiaturze. \n") << endl;
        cout << PL(" Pytanie numer 1: Jaki operator jest stosowany przy strumieniu std::cout? ") << endl;
        cout << PL (" a) << ") << endl;
        cout << PL (" b) >> ") << endl;
        cout << PL (" c) std:: ") << endl;
        klik=getch();
    }

    if (klik=='a') cout << PL("Dobra odpowiedź! \n \n"), wynik++;
    else cout << PL("Źle! Przy strumieniu std::cout stosuje się operator << \n \n");
    cout<<PL("...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    klik=0;

    while (klik!='a' && klik!='b' && klik!='c'){
        system("cls");
        cout << PL(" Czas na test! Wsićnij klawisz a, b lub c na klawiaturze. \n") << endl;
        cout << PL(" Pytanie numer 2: W jaki sposób nie przechodzi się do kolejnego wiersza w strumieniu std::cout? ") << endl;
        cout << PL (" a) cout << endl; ") << endl;
        cout << PL (" b) cout << \"\\n\" ") << endl;
        cout << PL (" c) cout << \"\\t\" ") << endl;
        klik=getch();
    }

    if (klik=='c') cout << "Dobra odpowiedź! \n \n", wynik++;
    else cout << PL("Źle! \"\\t\" powoduje wyświetlenie tabulacji. \n \n");
    cout<<PL("...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    klik=0;

    while (klik!='a' && klik!='b' && klik!='c'){
        system("cls");
        cout << PL(" Czas na test! Wsićnij klawisz a, b lub c na klawiaturze. \n") << endl;
        cout << PL(" Pytanie numer 3: Co zostanie wyświetlone? \n int a=112; \n std::cout << (a+3)/5+6; ") << endl;
        cout << PL (" a) 30") << endl;
        cout << PL (" b) 29 ") << endl;
        cout << PL (" c) (4+3)/5+6 ") << endl;
        klik=getch();
    }

    if (klik=='b') cout << "Dobra odpowiedź! \n \n", wynik++;
    else cout << PL("Źle! Po podstawieniu za a 112 i obliczniu, wynik wynosi 29 \n \n");
    cout<<PL("...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    klik=0;

    while (klik!='a' && klik!='b' && klik!='c'){
        system("cls");
        cout << PL(" Czas na test! Wsićnij klawisz a, b lub c na klawiaturze. \n") << endl;
        cout << PL(" Pytanie numer 4:  \n") << endl;
        cout << PL (" a) 2,5 ") << endl;
        cout << PL (" b) 4,99 ") << endl;
        cout << PL (" c) 5 ") << endl;
        klik=getch();
    }

    if (klik=='a') cout << "Dobra odpowiedź! \n \n", wynik++;
    else cout << PL("Źle!  \n \n");
    cout<<PL("...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    klik=0;

    while (klik!='a' && klik!='b' && klik!='c'){
        system("cls");
        cout << PL(" Czas na test! Wsićnij klawisz a, b lub c na klawiaturze. \n") << endl;
        cout << PL(" Pytanie numer 5:  \n") << endl;
        cout << PL (" a) c=rand(8)%34;") << endl;
        cout << PL (" b) c=rand()%33+8") << endl;
        cout << PL (" c) c=rand()%35+8; ") << endl;
        klik=getch();
    }

    if (klik=='c') cout << "Dobra odpowiedź! \n \n", wynik++;
    else cout << PL("Źle!  \n \n");
    cout<<PL("...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    cout << PL( " Koniec testu! Twój wynik to ") << wynik << PL("/5.");


}

void FunkcWarunLogiczne(){
    system("CLS");
    cout<<3;
}
struct menu{
    string el;
} menuuu[4];

int licz=4, po=0;

void drukuj2()
{
    menuuu[0].el =PL( "FOR");
    menuuu[1].el =PL( "WHILE");
    menuuu[2].el =PL( "DO WHILE");
    menuuu[3].el =PL("QUIZ");

        system("CLS");
        cout<<PL("---PĘTLE--- \n Istnieją 3 podstawowe pętle: FOR, WHILE i DO WHILE.\n Dzięki nim możemy powtarzać jakąś czynność tyle razy ile potrzebujemy. \n \n WYBIERZ PĘTLE, KTÓRĄ CHCESZ POZNAĆ: \n \n");

        for(int i=0; i<licz; i++)
        {
                if(i==po)
                    cout<<">";
                else
                    cout<<" ";
                cout << i+1 << ". ";
                cout<<menuuu[i].el<<endl;
        }
}

void FOR(){
        system("CLS");
                 system("CLS");
    //cout<<4;
    cout<<PL("-------FOR------- \n \n Używamy np.: gdy chcemy wpisać 20 liczb do tablicy - zamiast piać 20 razy \n \"cin>>tab[...]\" \n można to zapisać w petli FOR wykonującej się 20 razy.\n\n\nJAK STWORZYĆ PĘTLE FOR: \n \n (od jakiej wartości liczbowej zaczynamy - dowolna liczba całkowita np:4 \n do jakiej wartości chcemy dojść \n co się dzieje z tą liczbą (maleje czy rośnie o jeden)\n \n \" for (int liczba ; do jakiej watrości ; maleje czy rośnie){\n  \n        KOD KTÓRY MA SIĘ POWTARZAĆ }\" \n \n \n ");
    cout<<PL("...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");

    cout<<PL(" PRZYKŁAD: \n \n     for (int i=4; i<=23; i++){ \n cin>>a; } \n\n Kod ten powtarza się 19 razy - zaczyna się kiedy i=4, z każdym kolejnym wykonaniem rośnie o jeden (i++ to inaczej i=i+1). \n \n DODATKOWE INFORMACJE: \n \n 1) można pomniejszać tą liczbę (zamiast i++ -> i--). \n Wtedy deklarujemy wykonywanie pętli dopóki i jest WIĘKSZE od jakieś wartości. \n \n 2. nieskończona pętla (wykonuje się w nieskończoność -> for ( ; ; ){ \nkod } \n \n \n");
    cout<<PL("...wciśnij dowolny klawisz aby kontynuować.");
    getch();

}

void WHILE(){
        system("CLS");
                cout<<PL("---JAK STWORZYĆ PĘTLE WHILE---\n while (pętla wykonuje się dopóki warunek jest spełniony){ \n    KOD KTÓRY MA SIĘ POWTARZAĆ} \n \n PRZYKŁAD: \n int i=0; \n while (i<=5){ \n cout<<i<<endl; \n i++; } \n \n \n");
     cout<<PL("...wciśnij dowolny klawisz aby kontynuować.");
    getch();

}

void DO_WHILE(){
                system("cls");
                cout<<PL("JAK STWORZYĆ PĘTLE DO WHILE:\n do {KOD KTÓRY MA SIĘ POWTARZAĆ} \n while(warunek); \n PRZYKŁAD: \n int i=0; \n do {cout<<i<<endl; \n i++} \n while (i<=5); \n \n RÓŻNICA MIĘDZY WHILE I DO WHILE: \n");
                getch();

}

void TEST(){
    char odp;
    int punkty =0;

    system("cls");
    cout<<PL("Zróbmy mały QUIZ: \n  (wybierz poprawną odpowiedź - wciśnij odpowiednią literkę) \n \n");
    cout<<PL("1) W funkcji FOR w nawiasach mówiącyh o warunkach w jakich powtarza się ta petla, są potrzebne: \n \n a) trzy warunki \n b) dwa warunki \n c) jednen warunek \n ");
        cin>>odp;

    if (odp=='a' || odp=='A'){
        cout<<PL("POPRAWNA ODPOWIEDŹ! \n \n \n");
        punkty++;
    }
    else cout<<PL("ŹLE! poprawna odpowiedź: a \n \n \n");

    cout<<PL("...kliknij dowolny klawisz aby kontynuować");
    getch();
    system ("cls");

    cout<<PL("2) Do rozdzielenia warunkóww funkcji FOR używamy: \n \n a) , \n b) : \n c) ; \n ");
        cin>>odp;

    if (odp=='c' || odp=='C'){
        cout<<PL("POPRAWNA ODPOWIEDŹ! \n \n \n");
        punkty++;
    }
    else cout<<PL("ŹLE! poprawna odpowiedź: c \n \n \n");

    cout<<PL("...kliknij dowolny klawisz aby kontynuować");
    getch();
    system ("cls");

     cout<<PL("3) Kod ,,właściwy\" każdej pętli znajdyje się w nawiasach: \n \n a) () \n b) {} \n c) [] \n ");
        cin>>odp;

    if (odp=='b' || odp=='B'){
        cout<<PL("POPRAWNA ODPOWIEDŹ! \n \n \n ");
        punkty++;
    }
    else cout<<PL("ŹLE! poprawna odpowiedź: b \n \n \n");

    cout<<PL("...kliknij dowolny klawisz aby kontynuować");
    getch();
    system ("cls");

     cout<<PL("4) Liczbę zadeklarowaną w warunku pętli FOR można: \n \n a) dodawać \n b) odejmować \n c) obie odpowiedzi są poprawne \n ");
        cin>>odp;

    if (odp=='c' || odp=='C'){
        cout<<PL("POPRAWNA ODPOWIEDŹ! \n \n \n");
        punkty++;
    }
    else cout<<PL("ŹLE! poprawna odpowiedź: c \n \n \n ");

    cout<<PL("...kliknij dowolny klawisz aby kontynuować");
    getch();
    system ("cls");

     cout<<PL("5) Czym rózni się pętla WHILE od DO WHILE? \n \n a) niczym \n b) pętla DO WHILE wykonuje się zawsze przynajmniej raz* \n c) pętla WHILE wykonuje się zawsze przynajmniej raz* \n \n \n \n *ze względu na swoją budowę \n \n \n");
        cin>>odp;

    if (odp=='b' || odp=='B'){
        cout<<PL("POPRAWNA ODPOWIEDŹ! \n \n \n");
        punkty++;
    }
    else cout<<PL("ŹLE! poprawna odpowiedź: b \n \n \n");

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
{
    po=0;
    char klik;
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
void Funkcje(){
    system("CLS");
    cout<<5;
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
                cout<<PL("...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    cout << PL (" Używanie tej funkcji ma jednak poważną wadę: zawsze losuje te same liczby. \n Po uruchomieniu programu ponownie, można zauważyć że liczby nie zmieniły się. \n Jednak istnieje też inna funkcja - ");
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << PL("srand(),");
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
    cout << PL(" która ustawia punkt startowy dla \n losowania. Po użyciu jej, dalej korzysta się z funkcji rand, by losować liczby: ");
    SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
                cout << PL(" \n srand(wartość); \n cout << rand(); \n ") << endl; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
                cout << PL(" Oznacza to tylko tyle, że liczby będą inne. Korzystając z biblioteki ctime, \n można pod warość w funkcji srand podstawić funckję");
                SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
                cout << " time(NULL); "; SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
                cout << PL("co uzależna \n punkt startowy od czasu. Dzięki temu punkt startowy zawsze będzie inny. \n \n");
                SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN | FOREGROUND_INTENSITY );
                cout << "srand(time(NULL)); \n cout << rand(); \n \n";
                cout << "\n \n";
                SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_BLUE |FOREGROUND_GREEN );
                cout<<PL("...wciśnij dowolny klawisz aby kontynuować.");
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
                cout<<PL("...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    cout << PL (" Oczywiście można w ten sposób uzyskać różne przedziały, na przykład: \n \n srand(time(NULL)); \n (rand()%36)+5; wylosuje liczbę od 5 do 41, \n (rand()%13)-9; wylosuje liczbę od -9 do 4, a \n (rand()%51)*(-1) wylosuje liczbę od -50 do 0. \n");
    cout << PL ("\n ...Czas na test! Wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");

    int wynik=0;
    char klik;
    while (klik!='a' && klik!='b' && klik!='c'){
                        system("cls");
                        cout << PL(" Czas na test! Wsićnij klawisz a, b lub c na klawiaturze. \n") << endl;
                        cout << PL(" Pytanie numer 1: w jakiej bibliotece znajduje się funckjca rand()? ") << endl;
                        cout << PL (" a) ctime ") << endl;
                        cout << PL (" b) cstdlib ") << endl;
                        cout << PL (" c) conio.h ") << endl;
                        klik=getch();
    }

    if (klik=='b') cout << PL("Dobra odpowiedź! \n \n"), wynik++;
    else cout << PL("Źle! Funkcja rand() znajduje się w bibliotece cstdlib. \n \n");
    cout<<PL("...wciśnij dowolny klawisz aby kontynuować.");
    getch();
    system("cls");
    klik=0;

    while (klik!='a' && klik!='b' && klik!='c'){
                        system("cls");
                        cout << PL(" Czas na test! Wsićnij klawisz a, b lub c na klawiaturze. \n") << endl;
                        cout << PL(" Pytanie numer 2: Która funkcja ustawia punkt startowy dla losowanych liczb?") << endl;
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
                        cout << PL(" Czas na test! Wsićnij klawisz a, b lub c na klawiaturze. \n") << endl;
                        cout << PL(" Pytanie numer 3: Jaka jest możliwa największa wartość dla zmiennej a? \n int a; \n srand(time(NULL)); \n a=(rand()%40)+1; \n") << endl;
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
        cout << PL(" Czas na test! Wsićnij klawisz a, b lub c na klawiaturze. \n") << endl;
        cout << PL(" Pytanie numer 4: Jaka jest możliwa najmniejsza wartość dla zmiennej b? \n float b; \n srand(time(NULL)); \n b=((rand()%250)+250)/100; \n") << endl;
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
    cout << PL(" Czas na test! Wsićnij klawisz a, b lub c na klawiaturze. \n") << endl;
    cout << PL(" Pytanie numer 5: Która funkcja wylosuje dla zmiennej c liczbę z przedziału od 8 do 46? \n srand(time(NULL); \n int c; \n") << endl;
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
    system("CLS");
    cout<<PL("Biblioteki są niezbędne w programowaniu, dzięki nim możemy uzyskać dostęp do \nróżnych funkcjii. Poczynając od cout'ow, kończąć na funkcjach sortujących\n\n");
    cout<<PL("Deklarujemy je zawsze na początku kodu, \"#include <NazwaBiblioteki>\",\nmożemy dodać ich dowolną ilość, ale dla lepszej wydajności deklarujemy tylko te używane\n\n");
    cout<<PL("Najczęściej stosowane biblioteki: \n1. iostream - umożliwia nam korzystanie z wypisywanie i wczytywania (cout, cin)\n");
    cout<<PL("2. fstream - pozwala nam na wczytywanie i zapisywanie do pliku\n");
    cout<<PL("3. conio.h - w niej mamy przydatna funkcje getch(), ktora odczytuje 1 znak \npodany przez użytkownika, jest to niezbędne przy tworzeniu menu itp\n");
    cout<<PL("4. ctime - pobiera lokalny czas z komputerka\n");
    cout<<PL("5. windows.h - przydatna jest funckja sleep(CzasWMilisekundach),\nktóra zatrzymujedziałanie programu na określony czas\n");
    cout<<PL("6. math.h - pozwala na stosowanie funkcji matematycznych,\nnp sqr() - kwadrat danej liczby lub sqrt() - pierwiastek");
    getch();
    cout<<7;
}

void PrzykladoweProgramyPomoc(string NazwaPliku){
        system("CLS");
        fstream plik;
        string pomoc;
        plik.open(NazwaPliku, ios::in);
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
