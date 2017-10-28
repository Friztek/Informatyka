#include <iostream>

using namespace std;

int main()
{
    int a,b,x,y,z,pomoc,ile=0;
    cout<<"Podaj A: ";
    cin>>a;
    cout<<"Podaj B: ";
    cin>>b;
    cout<<"Podaj x: ";
    cin>>x;
    cout<<"Podaj y: ";
    cin>>y;
    cout<<"Podaj z: ";
    cin>>z;
    cout<<endl;

    if (b>a)
    {
        pomoc=b;
        b=a;
        a=pomoc;
    }

    for (int i=b; i<=a; i++)
    {
        if (i%x==0 && i%y==0 && i%z!=0)
        {
            ile++;
            cout<<i<<" ";
        }
    }
    cout<<endl<<endl;
    cout<<ile<<" liczb";



    return 0;

}
