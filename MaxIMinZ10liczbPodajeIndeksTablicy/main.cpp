#include <iostream>

using namespace std;

int t_intow[100],maximum, minimum;

int main()
{
    for (int i=0; i<10; i++)
    {
        cin>>t_intow[i];

        if (i==0)
        {
            maximum=i;
            minimum=i;
        }

        if (t_intow[i] < t_intow[minimum])
            minimum=i;
        if (t_intow[i] > t_intow[maximum])
            maximum=i;
    }

    cout<<"Maximum "<<maximum + 1<<endl;
    cout<<"Minimum "<<minimum + 1;


    return 0;
}
