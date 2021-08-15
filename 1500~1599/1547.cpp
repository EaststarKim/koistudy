#include <stdio.h>
char a[210];
int main(){
    int i;
    fgets(a,sizeof a,stdin);
    for(i=0;a[i];++i)printf("%c",a[i]==' '?' ':97+(a[i]-74)%26);
    return 0;
}
