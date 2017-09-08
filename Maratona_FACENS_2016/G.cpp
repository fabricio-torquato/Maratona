#include <bits/stdc++.h>

using namespace std;

typedef struct poste
{
    bool visited;
    int parent;
    map<int,int>cabos;
} poste;

vector<poste>postes;

int corteMin(int init,int target);
bool largura(int init, int target);
void zerar();

int main()
{
    int n,m;
    while(1)
    {
        int resp =0;

        cin>>n;
        cin>>m;
        postes.clear();

        if(n==0 && m==0)
            break;

        for(int i=0; i<n; i++)
        {
            poste aux;
            postes.push_back(aux);
        }

        while(m--)
        {
            int a,b,c;

            cin>>a;
            cin>>b;
            cin>>c;
            postes[a-1].cabos[b-1]=c;
            postes[b-1].cabos[a-1]=c;
        }
        while(1)
        {
            int atual = corteMin(0,n-1);
            if(atual==-1)
                break;
            resp+=atual;
        }
        cout<<resp<<endl;
    }
    return 0;
}
int corteMin(int init,int target)
{
    if(largura(init,target))
        return -1;

    int i = target;
    int menor = 999999;

    vector<int> resp;
    resp.push_back(i);

    while(i!=init)
    {
        int pr = postes[i].parent;
        resp.push_back(pr);
     //   cout<<pr<<" ["<<postes[pr].cabos[i]<<"] ";
        if(menor == 999999 || menor > (postes[pr].cabos[i]))
            menor = postes[pr].cabos[i];
        i = postes[i].parent;

    }
//    cout<<"Menor: "<<menor<<endl;
    for(i = 0; i<resp.size()-1; i++)
    {
        postes[resp[i+1]].cabos[resp[i]]-=menor;
        if(postes[resp[i+1]].cabos[resp[i]]<0)
            postes[resp[i+1]].cabos[resp[i]]=0;
        if(postes[resp[i]].cabos.find(resp[i+1])==postes[resp[i]].cabos.end())
            postes[resp[i]].cabos[resp[i+1]] = 0;
        postes[resp[i]].cabos[resp[i+1]]+=menor;
    }

    return menor;
}
void zerar()
{
    for(int i = 0; i<(int)postes.size(); i++)
    {
        postes[i].visited=false;
        postes[i].parent=-1;
    }
}
bool largura(int init, int target)
{
    zerar();
    queue<int> q;
    postes[init].visited=true;
    q.push(init);

    while(q.size()>0)
    {
        int atual = q.front();
        q.pop();
        if(atual == target)
            return false;
        for(map<int,int>::iterator it = postes[atual].cabos.begin(); it != postes[atual].cabos.end(); it++)
        {
            int aux = it->first;
            if(!postes[aux].visited && postes[atual].cabos[aux]>0)
            {
                postes[aux].visited=true;
                postes[aux].parent=atual;
                q.push(aux);
            }
        }
    }
    return true;
}
