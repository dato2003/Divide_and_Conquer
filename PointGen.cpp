#include<iostream>
#include<stdlib.h>
#include<time.h>  
using namespace std;
int main()
{
    srand(time(NULL));
    int pair;
    cin>>pair;
    int SOTD;
    cin>>SOTD;
    int PositiveEnd = (SOTD-2)/2;
    int NegativeEnd = -1 * (SOTD-2)/2;
    //cout<<PositiveEnd<<" "<<NegativeEnd<<endl;
    for(int i=0;i<pair;i++)
    {
        //N = rand() % (abs(a)+abs(b)+1) + a;
        int x = rand() % (abs(NegativeEnd)+abs(PositiveEnd)+1) + NegativeEnd;
        int y = rand() % (abs(NegativeEnd)+abs(PositiveEnd)+1) + NegativeEnd;
        cout<<x<<" "<<y<<endl;
    }
}