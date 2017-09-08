#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string texto;
    while(1){
        cin>>n;
        if(n==0)
            break;
        getchar();
        getline(cin,texto);
        if((int)texto.size()>51)
            cout<<"ERROR"<<endl;
        else if(n<1 || n>20)
            cout<<"ERROR"<<endl;
        else{
            for(int i=0;i<(int)texto.size();i++){
                if(texto[i] == 'A')
                    texto[i]= '@';
                else if(texto[i] == 'S')
                    texto[i]='$';
                else if(texto[i] == 'E')
                    texto[i]='3';
                else if(texto[i] == 'I')
                    texto[i]='!';
                else if(texto[i] == 'O')
                    texto[i]='0';
                else if(texto[i] == ' ')
                    texto[i]='#';
                else{
                    if(texto[i]+n > 'Z')
                        texto[i] = 'A' +(texto[i]+n-'Z') -1;
                    else
                        texto[i]+=n;
                }
            }
            cout<<texto<<endl;
        }
    }
    return 0;
}
