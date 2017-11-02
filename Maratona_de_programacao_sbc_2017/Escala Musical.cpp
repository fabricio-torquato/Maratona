#include <bits/stdc++.h>

using namespace std;

int tabela [] = {2,2,1,2,2,2,1};
map<int,int> mapa;
string notas[]= {"do","do#","re","re#","mi","fa","fa#","sol","sol#","la","la#","si"};
int escala [12][12];
int main()
{
    memset(escala,0,sizeof(escala));
    for(int i=0; i<12; i++)
    {
        int k=0;
        int j=i;
        int proxNota=i;
        bool flag=true;
        while(true)
        {

            if(j==i && flag)
                flag=false;
            else if(j==i && !flag)
                break;
            if(j==proxNota)
            {
                escala[i][j]=1;
                proxNota+=tabela[k++];
            }
            j++;
            if(j==12)
            {
                j=0;
                proxNota-=12;
            }
        }
    }

    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int aux;
        cin>>aux;
        aux-=1;
        if(aux>12)
            aux=aux%12;
        for(int j=0; j<12; j++)
        {
            if(escala[j][aux]==1)
            {
                if(mapa.find(j)==mapa.end())
                    mapa[j]=0;
                mapa[j]=mapa[j]+1;
            }
        }
    }
    bool flag = false;
    for(map<int,int>::iterator it=mapa.begin(); it!=mapa.end(); it++)
    {
        if(it->second==n)
        {
            cout<<notas[it->first]<<endl;
            flag=true;
            break;
        }
    }
    if(!flag)
        cout<<"desafinado"<<endl;
    return 0;
}
