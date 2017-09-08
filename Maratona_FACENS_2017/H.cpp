#include <bits/stdc++.h>
#define MAXN 150

using namespace std;

int G[MAXN][MAXN];
int n;
long long int dijktra();

int main()
{
    while(1)
    {
        cin>>n;

        if(n==0)
            break;
        memset(G,0,sizeof(G));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>G[i][j];

        long long int cust = dijktra();

        if(cust==-1)
            cout<<"CAMINHO INEXISTENTE"<<endl;
        else
            cout<<cust<<endl;
    }
    return 0;
}
long long int dijktra()
{
    long long int dist[MAXN];
    queue<int> q;

    memset(dist,-1,sizeof(dist));
    dist[0]=0;
    q.push(0);
    while(q.size()>0){
        int index = q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(G[index][i]>0 && (dist[i]==-1|| dist[i]>dist[index]+G[index][i]))
            {
                dist[i]=dist[index]+G[index][i];
                q.push(i);
            }
        }
    }
    return dist[n-1];
}
