#include <iostream>

using namespace std;

int main()
{
    int n, c=0;
    cin>>n;


        if (n<11)
            cout<<"Troszke za malo :<";

        if (n>=11)
            for (int i=1; i<10; i++)
            {

                if ((i*10+i)<=n)
                {
                    cout<<i<<i<<endl;
                    c++;
                }
                    for (int j=0; j<10; j++)
                    {
                        if ((i*100+j*10+i)<=n)
                        {
                            cout<<i<<j<<i<<endl;
                            c++;
                        }
                        if ((i*1000+j*100+j*10+i)<=n)
                        {
                            cout<<i<<j<<j<<i<<endl;
                            c++;
                        }
                        for (int z=0; z<10; z++)
                        {

                            if ((i*10000+j*1000+z*100+j*10+i)<=n)
                            {
                                cout<<i<<j<<z<<j<<i<<endl;
                                c++;
                            }
                            if ((i*100000+j*10000+z*1000+z*100+j*10+i)<=n)
                            {
                                cout<<i<<j<<z<<z<<j<<i<<endl;
                                c++;
                            }
                        }
                    }
            }

        cout<<c<<" Palindomow";
    return 0;
}
