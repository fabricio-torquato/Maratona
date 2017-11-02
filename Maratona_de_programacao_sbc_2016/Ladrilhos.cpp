#include<stdio.h>
#include <list>

using namespace std;

typedef struct bloco
{
    int cor;
    int i;
    int j;
} bloco;

list<bloco> lista = list<bloco>();

bool compara (int cor,bloco m);

int main()
{
    int linha,coluna,cor,cont=0,menor=0;
    bool primeira = true;


    scanf("%d%d",&linha,&coluna);
    bloco matriz[linha][coluna];

    for(int i=0; i<linha; i++)
    {
        for(int j=0; j<coluna; j++)
        {
            scanf("%d",&matriz[i][j].cor);
            matriz[i][j].i=i;
            matriz[i][j].j=j;
        }
    }

    for(int i=0; i<linha; i++)
    {
        for(int j=0; j<coluna; j++)
        {
            if(matriz[i][j].cor!=-1)
            {
                lista.push_back(matriz[i][j]);
                cor=matriz[i][j].cor;
                matriz[i][j].cor=-1;

                while(lista.empty()==false)
                {
                    bloco ladrilho = lista.front();
                    lista.pop_front();
                    cont++;

                    if(ladrilho.i+1<linha && compara(cor,matriz[ladrilho.i+1][ladrilho.j]))
                    {
                        matriz[ladrilho.i+1][ladrilho.j].cor=-1;
                    }
                    if(ladrilho.i-1>=0 && compara(cor,matriz[ladrilho.i-1][ladrilho.j]))
                    {
                        matriz[ladrilho.i-1][ladrilho.j].cor=-1;
                    }
                    if(ladrilho.j+1<coluna && compara(cor,matriz[ladrilho.i][ladrilho.j+1]))
                    {
                        matriz[ladrilho.i][ladrilho.j+1].cor=-1;
                    }
                    if(ladrilho.j-1>=0 && compara(cor,matriz[ladrilho.i][ladrilho.j-1]))
                    {
                        matriz[ladrilho.i][ladrilho.j-1].cor=-1;
                    }
                }
                if(primeira)
                {
                    menor=cont;
                    primeira=false;
                }
                else if(cont<menor)
                    menor=cont;
                cont=0;
            }
        }
    }
    printf("%d\n",menor);
    return 0;
}
bool compara (int cor,bloco m)
{
    if(cor==m.cor)
    {
        lista.push_back(m);
        return true;
    }
    return false;
}
