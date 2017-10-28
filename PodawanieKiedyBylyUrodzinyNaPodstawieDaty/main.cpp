#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    int d[2], m[2], r[2], pomoc_przod, pomoc;

    SYSTEMTIME st;
    GetLocalTime(&st);

    d[0] = st.wDay;
    m[0] = st.wMonth;

    cout<<"Podaj swoja date urodzin (dd mm): ";
    cin>>d[1]>>m[1];

    pomoc_przod = 30 * (m[1]-1) + d[1]; // urodziny
    pomoc = 30 * (m[0]-1) + d[0]; // dzisiaj

    if (pomoc==pomoc_przod)
        cout<<"Dzis sa twoje urodziny"<<endl;

    else if (pomoc>pomoc_przod)
    {
        cout<<"Urodziny byly "<<pomoc-pomoc_przod<<" dni temu"<<endl;
    }

    else

    {
        cout<<"Urodziny beda za "<<pomoc_przod-pomoc<<" dni"<<endl;
    }
}
