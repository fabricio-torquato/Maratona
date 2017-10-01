#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin>>n;
    cin>>k;
    map<int,int> mapa;
    for(int i=0;i<n;i++){
        int aux;
        cin>>aux;
        if(mapa.find(aux)==mapa.end())
            mapa[aux]=0;
        mapa[aux]++;
    }
    int cont=0;
    for(map<int,int>::reverse_iterator it = mapa.rbegin();it!=mapa.rend();it++){
        cont+=it->second;
        if(cont>=k)
            break;
    }
    cout<<cont<<endl;
    return 0;
}
