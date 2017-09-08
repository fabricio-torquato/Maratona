#include <bits/stdc++.h>

#define MAX LLONG_MAX

using namespace std;

long long int m [250][250];

long long int Matrix(long long int dims[],int n);
int main()
{
    int n;
    while(true)
    {
        cin>>n;
        if(n==0)
            break;
        long long int dims[n+1];
        long long aux;

        cin>>dims[0];

        for(int i=1; i<n; i++)
        {
            cin>>dims[i];
            cin>>aux;
        }
        cin>>dims[n];

        cout<<Matrix(dims,n)<<endl;
    }
    return 0;
}
long long int Matrix(long long int dims[],int n)
{
    for (int i = 1; i <= n; i++)
        m[i][i+1] = 0;
    for (int l = 2; l <= n; l++)
    {
        for (int i = 0; i <= n - l; i++)
        {
            int j = i + l;
            m[i][j] = MAX;
            for (int k = i+1; k <= j - 1; k++){
                m[i][j] = min(m[i][j],m[i][k] + m[k][j] + dims[i]*dims[k]*dims[j]);
                //cout<<"aqui "<<i<<" "<<j<<" "<<m[i][j]<<endl;
            }
        }
    }
    return m[0][n];
}
