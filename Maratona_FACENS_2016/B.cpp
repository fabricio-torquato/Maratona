#include <bits/stdc++.h>

using namespace std;

int main()
{
    double x,y,vm,vc,teta;
    while(1){

        cin>>x;
        cin>>teta;
        cin>>vm;
        cin>>y;
        cin>>vc;

        if(x==0 && teta==0 && vm==0 && y==0 &&vc==0)
            break;
        teta = teta*3.141592654/180;
        double vmY = vm*sin(teta);
       // cout<<vmY<<endl;
        double tempoY = y/vmY;
      //  cout<<tempoY<<endl;
        double vmX = vm*cos(teta);
     //   cout<<vmX<<endl;
        double distancMisX = vmX*tempoY;
    //    cout<<distancMisX<<endl;
        double tempoCen = (x-distancMisX)/vc;

        if(abs(tempoCen-tempoY)<0.1)
            cout<<"PERIGO"<<endl;
        else
            cout<<"CONTINUE EM FRENTE"<<endl;

    }
    return 0;
}
