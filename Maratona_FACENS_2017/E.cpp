#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while(1){
        cin>>n;
        if(n==0)
            break;
        while(n--){
            int numb[2][3];
            char pos[2];
            for(int i=0;i<2;i++){
                for(int j=0;j<3;j++)
                    scanf("%d%*c",&numb[i][j]);
                scanf("%c",&pos[i]);
            }
            double fisrt = (numb[0][0]*3600.0+numb[0][1]*60.0+numb[0][2])/3600.0;
            if(pos[0]=='S')
                fisrt*=-1;
            double second = (numb[1][0]*3600.0+numb[1][1]*60.0+numb[1][2])/3600.0;
            if(pos[1]=='W')
                second*=-1;
            cout<< setprecision(2)<< fixed<< trunc(fisrt*100)/100 <<" "<<trunc(second*100)/100<<endl;
        }
    }
    return 0;
}
