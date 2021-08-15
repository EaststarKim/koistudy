#include <stdio.h>
#include <string.h>
char a[20],c[20];
int main(){
    FILE *fin=fopen("dict.txt","r");
    int i,flag=0,s,e;
    scanf("%s",a);
    for(;;){
        fscanf(fin,"%s",c);
        if(c[0]=='Z')break;
        if(strlen(a)!=strlen(c))continue;
        for(i=0;c[i];++i)if(c[i]=='Q')continue;
        for(i=0;c[i];++i){
            s=(a[i]-50)*3+65,e=s+2;
            s+=(a[i]>'7'),e+=(a[i]>'6');
            if(c[i]<s||e<c[i])break;
        }
        if(!a[i])puts(c),flag=1;
    }
    if(!flag)puts("NONE");
    return 0;
}
