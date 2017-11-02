#include <iostream>

using namespace std;

int ordena(int i,int n);

int main()
{
    int n,cont=1;
    int posicao=1;

    cin>>n;
    posicao=ordena(posicao,n);

    while(posicao!=1)
    {
        posicao=ordena(posicao,n);
        cont++;
    }
    cout<<cont<<endl;
    return 0;
}
int ordena(int i,int n){

    if(i<=(n/2))
        return (i*2);
    else
        return i - (n - i + 1);
}
