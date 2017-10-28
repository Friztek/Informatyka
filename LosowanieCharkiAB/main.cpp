#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));
    char tab[100], uzytkownik[10];
    int t,c=0,k;

    cin>>uzytkownik;

    for (int i=0; i<100; i++)
    {
        t=rand()%2;
        if (t==0)
            tab[i]='a';
        else
            tab[i]='b';
        cout<<tab[i]<<" ";
    }

    for (int i=0; i<100; i++)
    {
        if (uzytkownik[0]==tab[i])
        {
            int j;

            for (j=1; j<(strlen(uzytkownik)); j++)
                if (uzytkownik[j]!=tab[i+j])
                    break;

            if (j==strlen(uzytkownik))
                c++;
        }
    }

    cout<<c;

  return 0;
}
