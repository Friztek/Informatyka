#include <iostream>

using namespace std;

int main()
{
    float suma=0, srednia;
    int i=0, max_parzyste=0, minimum, liczba=0;
    do {
        i++;
        cin>>liczba;
        if (liczba>0)
        {
            if (i==1)
                minimum=liczba;

            if (liczba%2==0 && liczba>=max_parzyste)
                max_parzyste=liczba;

            if (liczba < minimum)
                minimum = liczba;

            suma+=liczba;
        }
    } while(liczba>0);
    srednia=suma/(i-1);
    cout<<"Srednia "<<srednia<<endl;
    if (max_parzyste==0)
        cout<<"Nie ma najwiekszej liczby parzystej !"<<endl;
    else
        cout<<"Max parzyste "<<max_parzyste<<endl;
    cout<<"Minimum "<<minimum<<endl;
}
