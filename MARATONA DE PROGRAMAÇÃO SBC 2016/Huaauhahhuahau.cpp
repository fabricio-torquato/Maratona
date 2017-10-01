#include <stdio.h>
#include <string.h>


int main(){
    char txt1[100];
    char txt2[100];
    int i,j,tam;

    scanf(" %s",txt1);
    tam=strlen(txt1);

    for(i=0,j=0;i<=tam;i++){
        if(txt1[i]=='a' || txt1[i]=='e' ||txt1[i]=='i' ||txt1[i]=='o' ||txt1[i]=='u' || txt1[i]=='\0')
            txt2[j++]=txt1[i];
    }
    tam=strlen(txt2);
    txt1[tam]='\0';
    for(i=0,j=tam-1;i<tam;i++,j--){
            txt1[j]=txt2[i];
    }
    if(strcmp(txt1,txt2)==0)
        printf("S\n");
    else
        printf("N\n");
    return 0;
}
