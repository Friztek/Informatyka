#include <iostream>
#include <time.h>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    int losuj,zgadywana,ile=0;
    srand(time(NULL));

    losuj=(rand()%100)+1;
    cout<<losuj<<endl;

    while(losuj!=zgadywana)
    {
        cin>>zgadywana;
        if (zgadywana<losuj)
            cout<<"Za malo!"<<endl;
        else if (zgadywana>losuj)
            cout<<"Za duzo!"<<endl;
        ile++;
    }
    cout<<"Wygrales, zajelo to "<<ile<<" prob!";
    return 0;
}
