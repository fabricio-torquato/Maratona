#include <stdio.h>

int  Fatorial(int x);

int main(){
    int n,i,maximo=0,cont;
    int vetor[11];

    for(i=1;i<11;i++)
        vetor[i]=Fatorial(i);

    scanf("%d",&n);
    i=1;

    while(n>vetor[i])
        i++;
    maximo=vetor[--i];
    cont=1;
    while(maximo<n){
        if(maximo+vetor[i]<=n){
            maximo+=vetor[i];
            cont++;
        }
        else if(i==1){
            maximo+=vetor[i];
            cont++;
        }
        else if(i!=1)
            i--;
    }
    printf("%d\n",cont);
    return 0;
}

int Fatorial(int x){
    if(x==1)
        return 1;
    else
        return x*Fatorial(x-1);

}
