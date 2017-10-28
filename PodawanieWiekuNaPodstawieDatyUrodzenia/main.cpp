#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    int d[2], m[2], r[2];

    SYSTEMTIME st;
    GetLocalTime(&st);

    d[0] = st.wDay;
    m[0] = st.wMonth;
    r[0] = st.wYear;

    cout<<"Podaj swoja date urodzin (dd mm rrrr): ";
    cin>>d[1]>>m[1]>>r[1];

    if (m[1]>=m[0])
    {
        if (m[1]==m[0] && d[1]<=d[0])
            cout<<r[0]-r[1];
        else
            cout<<r[0]-r[1]-1;
    }
    else
        cout<<r[0]-r[1];

}

