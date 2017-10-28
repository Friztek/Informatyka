#include <iostream>

using namespace std;

int main()
{
    int t_intow[999],k,mniejsze,wieksze;
    bool warunek=true;

    cin>>k;

    for (int i=0; i<k*2+1; i++)
        cin>>t_intow[i];

    while(warunek)
    {
        for (int j=0; j<k*2+1; j++)
        {
            mniejsze=0;
            wieksze=0;

            for (int m=j+1; m<k*2+1; m++)
            {
                if (t_intow[j]<t_intow[m])
                    mniejsze++;
                else
                    wieksze++;
            }
            cout<<"Mniejsze "<<mniejsze<<endl;
            cout<<"Wieksze "<<wieksze<<endl;

            if (wieksze==mniejsze)
            {
                cout<<t_intow[j];
                warunek=false;
            }
        }
    }
}
