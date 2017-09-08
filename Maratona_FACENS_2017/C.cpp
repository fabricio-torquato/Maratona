#include <bits/stdc++.h>

using namespace std;

int pascal[20][20];

void calcular();

int main()
{
    int n;
    calcular();
    while(1)
    {
        cin>>n;
        if(n==-1)
            break;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=i; j++)
                cout<<pascal[i][j]<<" ";
            printf("=> ");
            int a=i;
            int b=0;
            for(int j=0; j<=i; j++)
            {
                if(j==0)
                    printf("%d*(A^%d*B^%d)",pascal[i][j],a,b);
                else
                    printf(" + %d*(A^%d*B^%d)",pascal[i][j],a,b);
                a--;
                b++;
            }
            cout<<endl;
        }
    }
    return 0;
}
void calcular()
{
    for(int i=0; i<20; i++)
    {
        for(int j=0; j<=i; j++)
        {
            if(i==j)
                pascal[i][j]=1;
            else if(j==0)
                pascal[i][j]=1;
            else
                pascal[i][j]=pascal[i-1][j-1]+pascal[i-1][j];
        }
    }
}
