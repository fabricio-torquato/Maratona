#include <bits/stdc++.h>

using namespace std;

typedef struct ordem
{
    int forca;
    int joia[6];
} ordem;

typedef struct personagem
{
    int atributos[4];
} personagem;

int pedras[6][4];
string nome[6];

bool compare (const ordem a,const ordem b);
bool compararThanos(personagem a);
void pedraInit();

int main()
{
    pedraInit();
    while(true)
    {
        list<ordem> resposta;

        personagem thanos;
        for(int i=0; i<4; i++)
            cin>>thanos.atributos[i];

        if(compararThanos(thanos))
            break;

        personagem heroi[6];

        for(int i=0; i<6; i++)
            for(int j=0; j<4; j++)
                cin>>heroi[i].atributos[j];

        int valor[] = {0,1,2,3,4,5};

        do
        {
            int total =0;
            bool flag = false;
            personagem thanos_aumentado = thanos;

            for(int i=0; i<6; i++)
            {
                int forca = 0;
                for(int j=0; j<4; j++)
                {
                    forca+= thanos_aumentado.atributos[j]-heroi[valor[i]].atributos[j];
                }
                if(forca<0)
                {
                    flag=true;
                    break;
                }
                total+=forca;
                for(int j=0; j<4; j++)
                {
                    thanos_aumentado.atributos[j]+=pedras[valor[i]][j];
                }
            }

            if(!flag)
            {
                ordem aux;
                aux.forca=total;
                for(int i=0; i<6; i++)
                    aux.joia[i]=valor[i];
                resposta.push_back(aux);
            }

        }
        while(next_permutation(valor,valor+6));

        if(resposta.size()>0)
        {
            resposta.sort(compare);

            ordem aux = resposta.front();
            for(int i=0; i<6; i++)
            {
                if(i==0)
                    cout<<nome[aux.joia[i]];
                else
                    cout<<" "<<nome[aux.joia[i]];
            }
            cout<<endl;

        }
        else
        {
            cout<<"Precisamos de mais poder antes dessa guerra!"<<endl;
        }
    }
    return 0;
}
bool compararThanos(personagem a)
{
    if(a.atributos[0]<0 && a.atributos[1]<0 && a.atributos[2]<0 && a.atributos[3]<0)
        return true;
    return false;
}
void pedraInit()
{
    pedras[0][0]=80;
    pedras[0][1]=80;
    pedras[0][2]=40;
    pedras[0][3]=0;
    nome[0]="espaco";

    pedras[1][0]=0;
    pedras[1][1]=0;
    pedras[1][2]=100;
    pedras[1][3]=60;
    nome[1]="mente";

    pedras[2][0]=0;
    pedras[2][1]=0;
    pedras[2][2]=60;
    pedras[2][3]=100;
    nome[2]="alma";

    pedras[3][0]=0;
    pedras[3][1]=40;
    pedras[3][2]=80;
    pedras[3][3]=80;
    nome[3]="realidade";

    pedras[4][0]=50;
    pedras[4][1]=100;
    pedras[4][2]=20;
    pedras[4][3]=0;
    nome[4]="tempo";

    pedras[5][0]=100;
    pedras[5][1]=40;
    pedras[5][2]=20;
    pedras[5][3]=10;
    nome[5]="poder";
}
bool compare (const ordem a,const ordem b)
{
    if(a.forca>b.forca)
        return true;
    if(a.forca<b.forca)
        return false;
    else
    {
        for(int i=0; i<6; i++)
        {
            if(nome[a.joia[i]][0]!=nome[b.joia[i]][0])
                return nome[a.joia[i]][0]< nome[b.joia[i]][0];
        }
    }
    return false;
}
