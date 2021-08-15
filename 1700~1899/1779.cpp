#include <stdio.h>
char c[100010];
int main(){
    int i,s=0;
    scanf("%s",c+1);
    for(i=1;c[i];++i)if(c[i]!=c[i-1])++s;
    printf("%d",s-1);
    return 0;
}
