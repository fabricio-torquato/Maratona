import sys

def search(city):
    cash_curr=0
    global dist_total
    for i in G[city]:
        if G[city][i]!=0 and G[i][city]!=0 :
            G[i][city]=0
            search(i)
            cash[city]+=cash[i]
            dist = int(cash[i]/c) * G[city][i]
            if cash[i]%c != 0:
                dist+=G[city][i]
            dist*=2
            dist_total+=dist
    pass


n,c = [int(x) for x in raw_input("").split(" ")]
cash = [int(x) for x in raw_input("").split(" ")]
cash.insert(0,0)

sys.setrecursionlimit(n+10)

# G = [[0 for x in xrange(n+2)] for y in xrange(n+2)]
G=dict()
for i in range(n-1):
    begin,end,cost = [int(x) for x in raw_input("").split(" ")]
    G[begin] = G.get(begin, {})
    G[begin][end]=cost
    G[end] = G.get(end, {})
    G[end][begin]=cost

dist_total=0
search(1)
print dist_total
