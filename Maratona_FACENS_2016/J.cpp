#include <bits/stdc++.h>

using namespace std;

struct Point
{
    int x, y;
};

int calcular(Point p, Point q, Point r);
vector<Point> procura(Point points[], int n);
bool comparator(Point a,Point b);

int main()
{
    int n;
    while(1)
    {
        cin>>n;
        if(n==0)
            break;
        Point vetor [n];

        for(int i=0; i<n; i++)
        {
            scanf("%d,%d",&vetor[i].x,&vetor[i].y);
        }

        vector<Point> resp = procura(vetor,n);
        sort(resp.begin(),resp.end(),comparator);

        for(int i=0; i<(int)resp.size(); i++)
        {
            if(i==0)
                cout<<resp[i].x<<","<<resp[i].y;
            else
                cout<<" "<<resp[i].x<<","<<resp[i].y;
        }
        cout<<endl;
    }
    return 0;
}

int calcular(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -(q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0;
    if(val > 0)
        return 1;
    else
        return 2;
}

vector<Point> procura(Point points[], int n)
{
    vector<Point> v;
    if (n < 3)
        return v;

    int l = 0;

    for (int i = 1; i < n; i++)
        if (points[i].x < points[l].x)
            l = i;

    int p = l, q;

    do
    {
        v.push_back(points[p]);
        q = (p+1)%n;
        for (int i = 0; i < n; i++)
        {
            if (calcular(points[p], points[i], points[q]) == 2)
                q = i;
        }
        p = q;
    }
    while (p != l);
    return v;
}
bool comparator(Point a,Point b)
{
    if(a.x<b.x)
        return true;
    else if(a.x>b.x)
        return false;
    return (a.y<b.y);
}
