#include <iostream>

using namespace std;

int main()
{
    int a,b,pomoc;

    cin>>a>>b;

    /*for (int i=a; i<b; i++)
        if (i%2==0 && i%7==0)
            cout<<i; */
    while(true)
    {
        if (a%14==0)
        {
            pomoc=a;
            break;
        }
        a++;
    }

    for (pomoc; pomoc<b; pomoc+=14)
        cout<<pomoc<<" ";


    return 0;
}
