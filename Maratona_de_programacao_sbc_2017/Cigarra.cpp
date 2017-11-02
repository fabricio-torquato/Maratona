#include<bits/stdc++.h>

using namespace std;

unsigned long long mdc(unsigned long long num1, unsigned long long num2);
unsigned long long mmc(unsigned long long num1, unsigned long long num2);

int main()
{
	unsigned long long n,l;
	cin>>n;
	cin>>l;
	unsigned long long aux=1;
	for(unsigned long long i=0;i<n;i++){
		unsigned long long x;
		cin>>x;
		aux=mmc(aux,x);
	}
	unsigned long long maior=aux;
	unsigned long long valor = 1;
	for(unsigned long long i=2;i<=l;i++){
		unsigned long long curr = mmc(aux,(unsigned long long)i);
		if(curr <= l && curr>maior){
			maior=curr;
			valor = i;
		}
	}
	cout<<valor<<endl;
	return 0;
} unsigned long long mdc(unsigned long long num1,unsigned long long num2){
    if(num2 == 0)
        return num1;
    return mdc(num2,num1%num2);
}
unsigned long long mmc(unsigned long long num1,unsigned long long num2){
    return num1*num2/mdc(num1,num2);
}
