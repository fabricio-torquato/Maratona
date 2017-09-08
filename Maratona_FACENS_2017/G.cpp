#include <bits/stdc++.h>
#define MAXN 50

using namespace std;

typedef struct aeroporto
{
    string nome;
    int id;
    int tempo;
} aeroporto;

int G[MAXN][MAXN];
map<string,aeroporto> vetor;
int n,q;

long long int dijktra(int a,int b);

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        aeroporto aux;
        cin>>aux.nome;
        cin>>aux.tempo;
        aux.id=i;
        vetor[aux.nome]=aux;
    }

    memset(G,0,sizeof(G));

    cin>>q;

    while(q--)
    {
        string origem,destino;
        int distancia;
        cin>>origem;
        cin>>destino;
        cin>>distancia;
        if(distancia<=12000)
        {
            G[vetor[origem].id][vetor[destino].id]=distancia;
            G[vetor[destino].id][vetor[origem].id]=distancia;
        }
    }
    cin>>q;

    while(q--)
    {
        string origem,destino;
        int hi,hf;
        cin>>origem;
        cin>>destino;
        cin>>hi;
        cin>>hf;
        long long int cust = dijktra(vetor[origem].id,vetor[destino].id);

        int tempoReal = (int)((cust/1000.0)+0.5);
        //cout<<(cust/1000.0)+0.5<<endl;
        //tempoReal += ((int)( tempoReal / 12 )) * 3;

        int tempoEstimado = (hf-vetor[destino].tempo) - (hi-vetor[origem].tempo);

        if((cust!=-1) && ( tempoEstimado >= tempoReal ) )
            cout<<"SIM"<<endl;
        else
            cout<<"NAO"<<endl;
    }
    return 0;
}
long long int dijktra(int a,int b)
{
    long long int dist[MAXN];
    queue<int> q;

    memset(dist,-1,sizeof(dist));
    dist[a]=0;
    q.push(a);
    while(q.size()>0)
    {
        int index = q.front();
        q.pop();
        for(int i=0; i<n; i++)
        {
            if(G[index][i]>0 && (dist[i]==-1|| dist[i]>dist[index]+G[index][i]))
            {
                dist[i]=dist[index]+G[index][i] + 3000;
                q.push(i);
            }
        }
    }
    dist[b]-=3000;
    return dist[b];
}
