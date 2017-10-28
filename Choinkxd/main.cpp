#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Podaj n: ";
    cin>>n;
    for (int i=0; i<=n; i++)
    {
        cout<<" ";
        for (int j=1; j<=i; j++)
            cout<<"*";

        cout<<endl;
    }

    for (int i=0; i<=n; i++)
    {
        for (int j=0; j<=(n-i); j++)
            cout<<" ";
        for (int j=1; j<=(i*2-1); j++)
            cout<<"*";

        cout<<endl;
    }

    for (int i=0; i<=n; i++)
    {
        for (int j=1; j<=(n-i); j++)
            cout<<" ";
        for (int j=1; j<=(i*2); j++)
        {
            if (j%2==0)
                cout<<"*";
            else
                cout<<" ";
        }
        cout<<endl;
    }

    return 0;
}
