#include <iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
    int n,m;
    map<string,int> tree;
    map<string,int>::iterator it;
    cin>>n;
    cin>>m;
    int planos[n][4];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<4; j++)
        {
            cin>>planos[i][j];
        }
    }
    while(m--)
    {
        int planeta[3];
        for(int i=0; i<3; i++)
            cin>>planeta[i];
        string texto="";
        for(int i=0; i<n; i++)
        {
            if(planeta[0]*planos[i][0]+planeta[1]*planos[i][1]+planeta[2]*planos[i][2]>=planos[i][3])
                texto+="1";
            else
                texto+="0";
        }
        if(tree.find(texto)==tree.end())
            tree[texto]=1;
        else
            tree[texto]++;
    }
    it=tree.begin();
    int maior = it->second;
    for(it=tree.begin(); it!=tree.end(); it++)
    {
        if(maior<it->second)
            maior=it->second;
    }
    cout<<maior<<endl;
    return 0;
}
