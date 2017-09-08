#include <bits/stdc++.h>

using namespace std;

int pesos[]= {0,2,3,6,7,8};

int PD(int capacidade);

int main()
{
    int capacidade;
    while(cin>>capacidade)
    {
        int valor = PD(capacidade);
        if(valor==0)
            cout<<"PLACAR INVALIDO!"<<endl;
        else
            cout<<valor<<endl;
    }
    return 0;
}
int PD(int capacidade)
{
    int resultado[6][1050];
    int itens=5;
    memset(resultado,0,sizeof(resultado));
    for(int j=0; j<=capacidade; j++)
    {
        resultado[0][j]=0;
        for(int i=1; i<=itens; i++)
        {
            int a,b;
            a=resultado[i-1][j];
            if(pesos[i]>j)
            {
                resultado[i][j]=a;
            }
            else if(pesos[i]-j==0){
                resultado[i][j]=1+a;
            }
            else
            {
                resultado[i][j]=resultado[i][j-pesos[i]]+a;
            }
        }
    }
    return resultado[itens][capacidade];
}
