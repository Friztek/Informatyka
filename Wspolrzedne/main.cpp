#include <cstdlib>
#include <iostream>
#include <ctype.h>
#include <cstring>
#include <cmath>


/*
Do zrobenia:
2 punkty w jednej liczbie
Optymalizacja kodu


*/
using namespace std;

 int main()
{
    int pomoc=0, pomoc_2, h, mn=1, help=2;
    float tab[100]={NULL}, tmp=0;
    bool warunek_1=true, warunek=true;

    while(warunek_1)
    {
        int licznik=0;
        char ciag[100]="", ciag_pom[100]="";
        cin.getline(ciag_pom, 100);
        // usuwanie przednich i srodkowych spacji
        for (int i=0; i<strlen(ciag_pom); i++)
        {
            if (isdigit(ciag_pom[i]))
                warunek=false;

            if ((isspace(ciag_pom[i]) && isspace(ciag_pom[i+1])) || (ispunct(ciag_pom[i]) && ispunct(ciag_pom[i+1])) || warunek)
            {
                for (int j=i; j<strlen(ciag_pom); j++)
                    ciag_pom[j]=ciag_pom[j+1];
                i--;
            }
        }

        warunek=true;

        // spawdza, czy na koncu programu znajduja sie spacje
        if (isspace(ciag_pom[strlen(ciag_pom)-1]))
            h=1;
        else
            h=0;

        // usuwa koncowe spacje
        for (int i=h; i<strlen(ciag_pom); i++)
        {
            if ((isspace(ciag_pom[i]) && ispunct(ciag_pom[i+1]) && isspace(ciag_pom[i+2]))  &&  (isspace(ciag_pom[i]) && ispunct(ciag_pom[i+1]) && isspace(ciag_pom[i+2]))  && isalpha(i))
            {
                help=i;
                warunek=false;
                break;
            }
            if (isspace(ciag[i-h]) && !isdigit(ciag[i]))
                break;
            ciag[i-h]=ciag_pom[i-h];
        }



        //sprawdza ile jest spacji w ciagu
        for (int i=0; i<strlen(ciag); i++)
            if (!isdigit(ciag[i]) && !isspace(ciag[i]) && !ispunct(ciag[i]))
            {
                tmp=1;
                break;
            }
            else if (isspace(ciag[i]))
                    licznik++;

        //sprawdza czy nasz ciag jest czworokatem czy trojkatem
        if (!tmp && (licznik==5 || licznik==7) && warunek)
            {
            if (licznik==7 && ((tab[0]==tab[2] && tab[1]==tab[3]) || (tab[0]==tab[4] && tab[1]==tab[5]) || (tab[0]==tab[6] && tab[1]==tab[7]) || (tab[2]==tab[4] && tab[3]==tab[5]) || (tab[2]==tab[6] && tab[3]==tab[7]) || (tab[4]==tab[6] && tab[5]==tab[7])))
                pomoc=1;
            if (licznik==5 && ((tab[0]==tab[2] && tab[1]==tab[3]) || (tab[0]==tab[4] && tab[1]==tab[5]) || (tab[0]==tab[6] && tab[1]==tab[7]) || (tab[2]==tab[4] && tab[3]==tab[5]) || (tab[2]==tab[6] && tab[3]==tab[7]) || (tab[4]==tab[6] && tab[5]==tab[7])))
                pomoc=2;

            tmp = 0;

        // dostosowuje wartosci do ciagu
            for (int i = strlen(ciag)-1; i >= 0; i--)
            {
                //cout<<"i: "<<i<<ciag[i]<<endl;
                if (!isspace(ciag[i]) && !ispunct(ciag[i]))
                {
                    tmp+=(ciag[i]-48)*mn;
                    mn*=10;
                }
                else if (ispunct(ciag[i]))
                {
                    tmp=tmp/mn;
                    mn=1;
                }
                else
                {
                    tab[licznik--] = tmp;
                    tmp=0;
                    mn=1;
                }
            }


            tab[licznik--] = tmp;

            warunek_1=false;
        }
	else
        cout<<"Prosze poprawic "<<endl;
    }


    //       A     B     C     D
    // tab 0  1  2  3  4  5  6  7
    //     3  4  0  0  3  0
    //     3  4  0  0  3  0  0  4
    float a,b,c,d,e,f;


            a=sqrt(pow(tab[0]-tab[2],2) + pow(tab[1]-tab[3],2));
            b=sqrt(pow(tab[2]-tab[4],2) + pow(tab[3]-tab[5],2));

        //trojkaty


            if (pomoc==2)
        {

            c=sqrt(pow(tab[0]-tab[4],2) + pow(tab[1]-tab[5],2));

            cout<<a<<endl;
            cout<<b<<endl;
            cout<<c<<endl;

            if ((a+b-0.0001<=c && a+b+0.0001>=c ) || (a+c-0.0001<=b && a+c+0.0001>=b) || (c+b-0.0001<=a && c+b+0.0001>=a))
                cout<<"To nie trojkat :((("<<endl;
            else
            {

                    cout<<"To jest trojkat :D"<<endl;

                if (a==b && b==c)
                    cout<<"Toz to trojkat rownoboczny !"<<endl;

                if ((a-0.0001 <= sqrt(pow(b,2)+pow(c,2)) && a+0.0001>=sqrt(pow(b,2)+pow(c,2))) || (b-0.0001 <= sqrt(pow(a,2)+pow(c,2)) && b+0.0001>=sqrt(pow(a,2)+pow(c,2))) || (c-0.0001 <= sqrt(pow(b,2)+pow(a,2)) && c+0.0001>=sqrt(pow(b,2)+pow(a,2))))
                {

                    cout<<"Toz to trojkat prostokatny !"<<endl;
                }

                if (a!=b && b!=c && c!=a)
                    cout<<"Toz to trojkat roznoboczny !"<<endl;

                if ((a==b && a!=c) || (a==c && a!=b) || (b==c && b!=a))
                    cout<<"Toz to trojkat rownoramienny !"<<endl;
            }

        }

        //czworokaty
        if (pomoc==1)
        {

            //       A     B     C     D
            // tab 0  1  2  3  4  5  6  7
            //     3  4  0  0  3  0
            //     0  0  4  0  4  4  0  4

            c=sqrt(pow(tab[4]-tab[6],2) + pow(tab[5]-tab[7],2));
            d=sqrt(pow(tab[6]-tab[0],2) + pow(tab[7]-tab[1],2));
            e=sqrt(pow(tab[0]-tab[4],2) + pow(tab[1]-tab[5],2));
            f=sqrt(pow(tab[2]-tab[6],2) + pow(tab[3]-tab[7],2));
            cout<<a<<endl;
            cout<<b<<endl;
            cout<<c<<endl;
            cout<<d<<endl;

            if ((a+b+c-0.0001<d && a+b+c+0.0001>=d ) || (a+d+b-0.0001<=c && a+d+b+0.0001>=c) || (c+b+a-0.0001<=b && c+b+a+0.0001>=b) || (c+b+d-0.0001<=a && c+b+d+0.0001>=a))
                cout<<"Prosze nie podawac co najmniej 3 punktow znajdujacych sie na 1 prostej, dziekuje :)"<<endl;

            else if (b!=c && b!=d && d!=a && c!=a)
                cout<<"Toz to czworokat dziwny"<<endl;
            else
            {
                if (b==c && c==d & d==a)
                {
                    if (e-0.0001 <= sqrt(pow(b,2)+pow(c,2)) && e+0.0001>=sqrt(pow(b,2)+pow(c,2)))
                        cout<<"Toz to kwadrat"<<endl;
                    else
                        cout<<"Toz to romb"<<endl;
                }

                else if ((a==b && b!=c && c==d && d!=a) || (a!=b && b==c && c!=d && d==a))
                        cout<<"Toz to deltoid"<<endl;
                else
                {
                    if (e-0.0001 <= sqrt(pow(b,2)+pow(c,2)) && e+0.0001>=sqrt(pow(b,2)+pow(c,2)))
                        cout<<"Toz to prostokat"<<endl;
                    else
                        cout<<"Toz to rownoleglobok"<<endl;
                }

            }
        }

	return 0;
    }
