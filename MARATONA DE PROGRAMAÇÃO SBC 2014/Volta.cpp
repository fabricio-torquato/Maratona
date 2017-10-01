#include <iostream>

using namespace std;

int main()
{
    int x,y,p1=0,p2=0,volta=1;

    cin>>x>>y;

    while(p2-p1<x){
        p1+=x;
        p2+=y;
        volta++;
       // cout<<p1<<" "<<p2<<endl;
    }
    cout<<volta<<endl;
    return 0;
}
