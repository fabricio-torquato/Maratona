#include <iostream>

using namespace std;

int main()
{
    int n,m;
    int cont=0;
    bool flag=true;

    cin>>n>>m;
    int gol[m];

    for(int i=0;i<n;i++){
            flag=true;
        for(int j=0;j<m;j++){
            cin>>gol[j];
            if(gol[j]==0)
                flag=false;
        }
        if(flag)
            cont++;
    }
    cout<<cont<<endl;
    return 0;
}
