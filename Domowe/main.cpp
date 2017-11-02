#include <iostream>
#include <math.h>
#include <ctype.h>
#define M_PI 3.14159265358979323846

using namespace std;

struct PolaObwody(double a=0, double b=0, double c=0)
{
    double pole, obwod;
    string figura;

    //puste dane
    if ((a<0 || b<0 || c<0) || (a==0 && b==0 && c==0))
    {
        cout<<"Boki nie moga byc ujemne lub puste!";
        return 2;
    }

    // okrag
    else if (a!=0 && b==0 && c==0)
    {
        pole=M_PI*a*a;
        obwod=M_PI*2*a;
        figura="Okrag";
    }

    // prostokat
    else if (a!=0 && b!=0 && c==0)
    {
        pole=a*b;
        obwod=a*2+b*2;
        figura="Prostokat";
    }

    // trojkat
    else
    {
        // wzor herona
        pole=sqrt((a+b+c)*(a+b-c)*(a-b+c)*(b-a+c))/4;
        obwod=a+b+c;
        figura="Trojkat";
    }
    if (pole>0 && !isalpha(pole))
        {
            cout<<"Figura "<<figura<<endl;
            cout<<"Pole "<<pole<<endl;
            cout<<"Obwod: "<<obwod;
        }
    else
        cout<<"Taki trojkat nie istnieje!";


    return 1;
}

int main()
{
    if (PolaObwody(3,1)==1)
        return 0;
}
