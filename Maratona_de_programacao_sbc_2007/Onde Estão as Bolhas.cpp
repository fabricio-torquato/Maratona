#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        int vetor[n];
        vector<int> space_free;
        vector<int>::iterator it;
        int i = 1;
        int aux;

        for (int f = 0; f < n; f++)
        {
            space_free.push_back(f);
            vetor[f]=0;
        }
        
        for (; i <= m; i++)
        {
            cin >> aux;
            vetor[space_free[aux]] = i;
            space_free.erase (space_free.begin()+aux);
        }

        for (int j = 0; j < n; j++)
        {
            if (vetor[j] == 0)
            {
                vetor[j] = i++;
            }
            if (j == n - 1)
                cout << vetor[j] << endl;
            else
                cout << vetor[j] << " ";
        }
    }

    return 0;
}
