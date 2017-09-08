#include <bits/stdc++.h>

using namespace std;

vector<int> neuronios;
vector< vector<double> > mapa;

int condicao(double valor,int numb);
int recursiva(int numb,set<int> tree);
void somatoria(int numb,vector<double> v);
void catchValor(int numb,char c);
bool calcular(int tam);
void init();

int main()
{
    int n,q,e;
    bool flag;
    cin>>n;
    while(n--)
    {
        init();
        flag=false;
        cin>>q;
        for(int i=1; i<=q; i++)
        {
            char c;
            cin>>c;
            catchValor(i,c);
        }
        cin>>e;
        if(calcular(q))
            cout<<"ciclo!"<<endl;
        else
            cout<<neuronios[e]<<endl;
    }
    return 0;
}
bool calcular(int tam)
{
    for(int i=1; i<=tam; i++)
    {
        if(recursiva(i,set<int>()) == -2)
        {
            return true;
        }
    }
    return false;
}
void catchValor(int numb,char c)
{
    vector<double> v;
    double x;
    do
    {
        cin>>x;
        v.push_back(x);
    }
    while(getchar()!='\n');
    if(c=='E')
        somatoria(numb,v);
    else
        mapa[numb]=v;
}
void somatoria(int numb,vector<double> v)
{
    int tam =(int)(v.size()/2);
    double total =0;
    for(int i=0; i<tam; i++)
        total+=(v[i]*v[tam+i]);
    condicao(1.0+total,numb);
}
int condicao(double valor,int numb)
{
    if(valor<0)
        neuronios[numb]=0;
    else
        neuronios[numb]=1;
    return neuronios[numb];
}
int recursiva(int numb,set<int> tree)
{
    if(tree.find(numb)!= tree.end())
        return -2;
    tree.insert(numb);

    if(neuronios[numb]!=-1)
        return neuronios[numb];

    vector<double> valor = mapa[numb];
    int tam =(int)(valor.size()/2);
    double total =0;
    for(int i=0; i<tam; i++)
    {
        double res = recursiva((int)valor[i],tree);
        if(res==-2)
            return -2;
        total+=(res*valor[tam+i]);
    }
    return condicao(1.0+total,numb);
}
void init()
{
    mapa.clear();
    neuronios.clear();
    for(int i=0; i<150; i++)
    {
        neuronios.push_back(-1);
        vector<double> aux;
        mapa.push_back(aux);
    }
}
