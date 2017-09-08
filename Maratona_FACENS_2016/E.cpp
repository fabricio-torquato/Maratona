#include <bits/stdc++.h>

using namespace std;

int main()
{
    int l,m;

    while(1)
    {
        cin>>l;
        cin>>m;

        if(l==0 && m==0)
            break;

        bool flag = true;
        int matriz[l][l];

        for(int i=0; i<l; i++)
            for(int j=0; j<l; j++)
                matriz[i][j]=0;

        while(m--)
        {
            char op;
            int tam,x,y;

            cin>>op;
            cin>>tam;
            cin>>x;
            cin>>y;

            if(op=='H' && flag)
            {
                if(x+tam<=l)
                {
                    for(int j=x; j<x+tam; j++)
                    {
                        if(matriz[y][j]==0)
                            matriz[y][j]=1;
                        else
                            flag=false;
                    }
                }
                else
                {
                    flag=false;
                }
            }
            else if(flag)
            {
                if(y+tam<=l)
                {
                    for(int j=y; j<y+tam; j++)
                    {
                        if(matriz[j][x]==0)
                            matriz[j][x]=1;
                        else
                            flag=false;
                    }
                }
                else
                {
                    flag=false;
                }
            }
        }
        if(flag)
        {
            for(int i=0; i<l; i++)
            {
                for(int j=0; j<l; j++)
                {
                    cout<<matriz[i][j];
                }
                cout<<endl;
            }
        }
        else
        {
            cout<<"ERRO DE MAPEAMENTO"<<endl;
        }
    }
    return 0;
}
