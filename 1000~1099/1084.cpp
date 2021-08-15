#include <stdio.h>
#include <string.h>
char a[30][99],b[30][99];
int main(){
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;++i)scanf("%s",a[i]);
    for(i=0;i<n;++i)scanf("%s",b[i]);
    for(i=0;i<n;++i){
        if(!strcmp(a[i],b[i]))break;
        for(j=0;j<n;++j)if(!strcmp(b[i],a[j]))break;
        if(j==n)break;
        if(strcmp(a[i],b[j]))break;
    }
    if(i<n)puts("bad");
    else puts("good");
    return 0;
}
