def mdc(num1, num2):
    if num2 == 0:
        return num1
    return mdc(num2,num1%num2)

def mmc(num1, num2):
    if num2 == 0:
        return num1
    return (num1*num2)/mdc(num1,num2)

n,l = [int(x) for x in raw_input("").split(" ")]
aux=1
for x in raw_input("").split(" "):
    aux=mmc(aux,int(x))
maior =aux
list_mul=[]
for x in range(2,l):
    list_mul.append(maior*x)

last_value=list_mul[len(list_mul)-1]
valor = 1
for x in range(2,l+1):
    if last_value%x==0:
        curr = mmc(aux,x)
        if curr <= l and curr>maior:
            maior=curr
            valor = x

print valor
