#include <bits/stdc++.h>

using namespace std;

int sena,quina,quadra;
vector<int> correto;

int existe(vector<int>correto,vector<int> tentando);
int combinacao(int n, int p);
int arranjo(int n, int p);
int fatorial(int n);

int main()
{
    int sena,quina,quadra;
    vector<int> correto;
    vector<int> tentativa;

    int n;
    for(int i=0; i<6; i++)
    {
        int aux;
        cin>>aux;
        correto.push_back(aux);
    }
    cin>>n;
    while(n--)
    {
        sena=0,quina=0,quadra=0;
        tentativa.clear();
        for(int i=0; i<15; i++)
        {
            int aux;
            cin>>aux;
            if(aux==0)
                break;
            tentativa.push_back(aux);
        }
        int certo = existe(correto,tentativa);
        int tam = (int)tentativa.size();
        sena = combinacao(certo,6);
        quina = combinacao(certo,5) * combinacao(tam-certo,1);
        quadra = combinacao(certo,4) * combinacao(tam-certo,2);
        printf("Quadras: %d\nQuinas: %d\nSena: %d\n",quadra,quina,sena);
    }
    return 0;
}
int existe(vector<int>correto,vector<int> tentando)
{
    int cont =0;
    for(int i=0; i<(int)tentando.size(); i++)
    {
        if(find(correto.begin(),correto.end(),tentando[i])!=correto.end())
            cont++;
    }
    return cont;
}
int fatorial(int n)
{
    if (n>0)
        return n*fatorial(n-1);
    else
        return 1;
}
int permutacao(int n)
{
    return fatorial(n);
}
int arranjo(int n, int p)
{
    if (p>1)
        return n*arranjo(n-1,p-1);
    else
        return n;
}
int combinacao(int n, int p)
{
    return arranjo(n,p)/fatorial(p);
}
