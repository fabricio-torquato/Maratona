#include <bits/stdc++.h>

using namespace std;

typedef struct node{
    int x;
    int y;
    int cont;
}node;
int main()
{
    int n,m,x,y,z;

    while(1)
    {
        cin>>n;
        cin>>m;
        cin>>x;
        cin>>y;
        cin>>z;

        if(n==0 && m==0 && x==0 && y==0 && z==0)
            break;

        int matriz[n][m];
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
              matriz[j][i]=0;

        bool flag =false;

        while(z--){
            int i,j;
            cin>>i;
            cin>>j;
            matriz[j-1][i-1]=1;
        }

        queue<node> q;

        node nd;
        nd.x=x-1;
        nd.y=y-1;
        nd.cont=0;
        matriz[nd.y][nd.x]=3;
        q.push(nd);

        while(q.size()>0){

            nd = q.front();
            q.pop();

            if(nd.x==0 || nd.y==0 || nd.y==n-1 || nd.x==m-1){
                flag=true;
                break;
            }

            if(matriz[nd.y][nd.x+1]==0)
            {
                matriz[nd.y][nd.x+1]=2;
                node aux;
                aux.x=nd.x+1;
                aux.y=nd.y;
                aux.cont=(nd.cont)+1;
                q.push(aux);
            }
            if(matriz[nd.y][nd.x-1]==0)
            {
                matriz[nd.y][nd.x-1]=2;
                node aux;
                aux.x=nd.x-1;
                aux.y=nd.y;
                aux.cont=(nd.cont)+1;
                q.push(aux);
            }
            if(matriz[nd.y+1][nd.x]==0)
            {
                matriz[nd.y+1][nd.x]=2;
                node aux;
                aux.x=nd.x;
                aux.y=nd.y+1;
                aux.cont=(nd.cont)+1;
                q.push(aux);
            }
            if(matriz[nd.y-1][nd.x]==0)
            {
                matriz[nd.y-1][nd.x]=2;
                node aux;
                aux.x=nd.x;
                aux.y=nd.y-1;
                aux.cont=(nd.cont)+1;
                q.push(aux);
            }
        }
        if(flag)
            cout<<nd.cont<<endl;
        else
            cout<<"Vitoria"<<endl;
    }
    return 0;
}
