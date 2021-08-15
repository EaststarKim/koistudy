#include <stdio.h>
int a[210];
void trav(int i){
    if(a[i*2])trav(i*2);
    printf("%d ",a[i]);
    if(a[i*2+1])trav(i*2+1);
}
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    trav(1);
    return 0;
}
