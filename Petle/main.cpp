#include <iostream>

using namespace std;

int main()
{
    int a,b,pomoc;
    cout<<"Podaj A: ";
    cin>>a;
    cout<<"Podaj B: ";
    cin>>b;
    cout<<endl;

    if (b>a)
    {
        pomoc=b;
        b=a;
        a=pomoc;
    }

    for (int i=a; i>=b; i--)
        cout<<i<<" ";
        cout<<endl;

    for (int i=a; i>=b; i=i-2)
        cout<<i<<" ";
        cout<<endl;

    for (int i=b; i<=a; i=i+2)
        cout<<i<<" ";
        cout<<endl;



    return 0;

}
