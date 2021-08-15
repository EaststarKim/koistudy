#include <stdio.h>
char a[20],t[]="nprcvmxzbs";
int main(){
    int i,j;
    scanf("%s",a);
    for(i=0;a[i];i+=2){
        for(j=0;j<10;++j)if(a[i]==t[j])break;
        printf("%d",j);
    }
    return 0;
}
