#include <bits/stdc++.h>

using namespace std;

typedef struct box
{
    long long int x, y;
} box;

bool verific(box new_box);
box item;
int main()
{
    long long int t;
    while (cin >> item.x >> item.y >> t)
    {
        for (long long int i = 0; i < t; i++)
        {
            box aux;
            cin >> aux.x >> aux.y;
            if (verific(aux))
                cout << "Sim" << endl;
            else
                cout << "Não" << endl;
        }
    }

    return 0;
}

bool verific(box new_box)
{

    if (new_box.x <= item.x && new_box.y <= item.y)
        return true;

    if (new_box.y <= item.x && new_box.x <= item.y)
        return true;

    return false;
}