#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef struct variavel
{
    string nome;
    int valor;
} variavel;

map<string,variavel>desconehcido = map<string,variavel>();
map<string,variavel>conhecido = map<string,variavel>();

int main()
{
    int n,m;

    cin>>n>>m;

    variavel tabela[n+1][m+1];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>tabela[i][j].nome;
            if(desconehcido.find(tabela[i][j].nome)==desconehcido.end())
                desconehcido[tabela[i][j].nome]=tabela[i][j];
        }
        cin>>tabela[i][m].valor;
    }
    for(int j=0; j<m; j++)
        cin>>tabela[n][j].valor;

    while(conhecido.size()<desconehcido.size())
    {
        //procura linha
        for(int i=0; i<n; i++)
        {
            bool flag = false;
            bool resultado = true;
            int cont =0;
            int total=tabela[i][m].valor;
            variavel x;

            for(int j=0; j<m; j++)
            {
                if(conhecido.find(tabela[i][j].nome)!=conhecido.end()){
                    total-=conhecido[tabela[i][j].nome].valor;
                }
                else if(flag==false || (x.nome == tabela[i][j].nome)){
                    flag=true;
                    cont++;
                    x.nome = tabela[i][j].nome;
                }
                else{
                    resultado=false;
                    break;
                }
            }
            if(resultado && cont!=0){
                x.valor = total/cont;
                conhecido[x.nome]=x;
            }
        }

        //procura coluna
        for(int j=0; j<m; j++)
        {
            bool flag = false;
            bool resultado = true;
            int cont =0;
            int total=tabela[n][j].valor;
            variavel x;

            for(int i=0; i<n; i++)
            {
                if(conhecido.find(tabela[i][j].nome)!=conhecido.end()){
                    total-=conhecido[tabela[i][j].nome].valor;
                }
                else if(flag==false || (x.nome == tabela[i][j].nome)){
                    flag=true;
                    cont++;
                    x.nome = tabela[i][j].nome;
                }
                else{
                    resultado=false;
                    break;
                }
            }
            if(resultado && cont!=0){
                x.valor=total/cont;
                conhecido[x.nome]=x;
            }
        }
    }
    map<string, variavel>::iterator it = conhecido.begin();

    while(it!=conhecido.end()){
        cout<<it->second.nome<<" "<<it->second.valor<<endl;
        it++;
    }

    return 0;
}
