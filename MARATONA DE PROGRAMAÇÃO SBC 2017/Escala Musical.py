tabela = [2,2,1,2,2,2,1]
mapa=dict()
notas= ["do","do#","re","re#","mi","fa","fa#","sol","sol#","la","la#","si"]
escala = [[0 for x in range(12)] for y in range(12)] 
tam=12
for i in range(0,12):
    k=0
    j=i
    proxNota=i
    flag=True
    while(True):
        if j==i and flag:
            flag=False
        elif j==i and not(flag):
            break;
        if j==proxNota:
            escala[i][j]=1
            proxNota+=tabela[k]
            k+=1
        j+=1
        if j==12:
            j=0
            proxNota-=12

n = int(input())
for i in range(0,n):
    aux = int(input())
    aux-=1
    if aux>=12:
        aux=aux%12
    for j in range(0,12):
        if escala[j][aux]==1:
            mapa[j] = mapa.get(j, 0) + 1

flag = False
for key, value in mapa.items():
    if value==n:
        print(notas[key])
        flag=True
        break
if not(flag):
    print("desafinado")