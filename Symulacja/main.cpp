#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

int main()
{
    int win_count=0, lose_count=0, result, czynnik=3;
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    srand(time(NULL));


        while (lose_count !=3)
        {
            SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            //czynnik = ((rand() % 4 ) + 2);
            result = (rand() % czynnik );

            cout<<"Czynnik: "<<czynnik<<endl;
            cout<<"Result: "<<result<<endl;

            if (result==0)
            {
                lose_count++;
                SetConsoleTextAttribute( hOut, FOREGROUND_RED );
                cout << "Przegrales !, Twoj aktualny wynik to: "<<win_count<<" : "<<lose_count<<endl;
            }
            else
            {
                win_count++;
                SetConsoleTextAttribute( hOut, FOREGROUND_GREEN );
                cout << "Wygrales !, Twoj aktualny wynik to: "<<win_count<<" : "<<lose_count<<endl;
            }

        }

    return 0;
}
