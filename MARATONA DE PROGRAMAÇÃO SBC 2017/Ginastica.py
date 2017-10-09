mod = 1000000007
time, min, max = [int(x) for x in raw_input("").split(" ")]

matriz = [[1 for x in range(max-min+1)] for y in range(2)]
old = 0
curr = 1

for t in range(1,time):
    for d in range(1,max-min):
        matriz[curr][d]=(matriz[old][d-1] + matriz[old][d+1]) % mod

    matriz[curr][0]=matriz[old][1]
    matriz[curr][max-min]=matriz[old][max-min-1]

    aux=old
    old=curr
    curr=aux

res=0
for value in matriz[old]:
    res = (res + value) % mod

print res
