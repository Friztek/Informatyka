#include <iostream>
#include <string.h>

using namespace std;

void ToBinary (int a, int tB[]={NULL})
{
    int i=0;
    while (a>0)
    {
        tB[i]=a%2;
        a=a/2;
        i++;
    }
    for (int j=i-1; j>=0; j--)
        cout<<tB[j];

}

//prosze dzia³aj =)
//prosze dzia³aj =)
//prosze dzia³aj =)
//prosze dzia³aj =)
//prosze dzia³aj =)
//prosze dzia³aj =)

int ToDecimal (int a, int tD[]={NULL})
{
    int mn=1,help=0,pomoc[10]={NULL}, wynik=0,ab=a;
    while(a>0)
    {
        a=a/10;
        help++;
    }

    for (int i=help; i>0; i--)
    {
        pomoc[i]=ab%10;
        ab=ab/10;
        wynik+=pomoc[i]*mn;
        mn*=2;
    }

    cout<<wynik;

}


int main()
{
    int tB[10]={NULL}, tD[10]={NULL};
    //ToBinary(65,tB);
    ToDecimal(1010,tD);
    return 0;
}
