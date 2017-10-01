#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;
    vector<int> valores;
    valores.push_back(b*2+c*4);
    valores.push_back(a*2+c*2);
    valores.push_back(a*4+b*2);
    sort(valores.begin(),valores.end());
    cout<<valores[0]<<endl;
    return 0;
}
