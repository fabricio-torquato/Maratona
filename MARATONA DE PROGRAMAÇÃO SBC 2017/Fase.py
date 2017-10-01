n=int(input())
k=int(input())
d=dict()
for i in range(0,n):
   key=int(input())
   d[key] = d.get(key, 0) + 1
cont = 0
for i in sorted(d.keys(), reverse=True):
    cont += d[i]
    if cont >=k : 
        break
print(cont)