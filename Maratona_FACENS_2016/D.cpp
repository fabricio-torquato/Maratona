#include <iostream>

using namespace std;

int main()
{
    long long int a,b,c;
    while(1){
        cin>>a;
        cin>>b;
        cin>>c;
        if(a==0 && b==0 && c==0)
            break;
        if(b==0)
            b=1;
        if(a<0 || b<0 || c<0)
            cout<<"ERRO"<<endl;
        else
            cout<<(a*600)+((b-1)*600)+(c*600)<<endl;
    }
    return 0;
}
