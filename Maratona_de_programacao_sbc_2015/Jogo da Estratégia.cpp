#include <stdio.h>
#include <string.h>

int main (){
	int R,J,maior,i,j,jogador,aux;
	
	scanf("%d%d",&J,&R);
	int vida[J];
	memset(vida,0,sizeof(vida));
	maior=0;
	for (i = 0; i < R ; i++){
		for (j = 0; j < J ; j++){
			scanf("%d",&aux);
			vida[j]+=aux;
			if(i==R-1){
				if(vida[j]>=maior){
					maior=vida[j];
					jogador=j+1;
				}
			}	
		}
	}
	printf("%d\n",jogador);
	return 0;
}
