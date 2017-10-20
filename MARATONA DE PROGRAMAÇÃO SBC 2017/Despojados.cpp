#include<bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long n;
    cin>>n;
    unsigned long long f = 2;
    int factors = 0;
    while (f*f <= n)
    {
        if (n % f == 0)
        {
            factors++;
            while (n % f == 0) n /= f;
        }
        f++;
    }
    if (n != 1) factors++;
    cout<<pow(2,factors)<<endl;
    cout<<((unsigned long long)pow(2,factors)) - (factors + 1)<<endl;
    return 0;
}
