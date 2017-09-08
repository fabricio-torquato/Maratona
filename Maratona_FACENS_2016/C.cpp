#include <iostream>
#include<math.h>

using namespace std;

int main()
{
    int ovo,tempo;
    while(1){
        cin>>ovo;
        cin>>tempo;
        if(ovo<0 || tempo<0)
            break;
        if(ovo<=30 && tempo<=20 ){
            int valor = 4*(int)pow(2,ovo);
            if(tempo!=0)
                valor/=(int)pow(2,tempo);
            if(valor>=1)
                cout<<"Pessoas: "<<valor<<endl;
            else
                cout<<"Erro na receita"<<endl;
        }
    }
    return 0;
}
