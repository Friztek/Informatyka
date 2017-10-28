#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char ciag[100],pomoc[100];
    int k=0,b;

    cin.getline(ciag,100);

    for (int i=0; i<=strlen(ciag)-1; i++)
    {
        if (int(ciag[i])>=65 && int(ciag[i]<=90))
        {
            (ciag[i])=(int(ciag[i]))+32;
        }

        if (ciag[i]!=' ')
        {
            pomoc[k]=ciag[i];
            k++;
        }

    }

    if (strlen(ciag) < strlen((pomoc)))
        b=strlen(ciag)-1;
    else
        b=strlen(pomoc)-1;

    k=0;


    while(true)
    {
        if (k>=b)
        {
            cout<<"TAK";
            break;
        }

        if (pomoc[k]!=pomoc[b])
        {
            cout<<"NIE";
            break;
        }
        k++;
        b--;
    }


    return 0;
}
