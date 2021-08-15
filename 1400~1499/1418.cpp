#include <stdio.h>
int a[31];
int main(){
    int i,k;
    for(i=1;i<29;++i)scanf("%d",&k),a[k]=1;
    for(i=1;i<31;++i)if(!a[i])printf("%d\n",i);
    return 0;
}
