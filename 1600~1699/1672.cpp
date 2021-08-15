#include <stdio.h>
int a[1000010],st[1000010],chk[1000010],n,t;
int main(){
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d",a+i);
    for(i=1;i;){
        if(!chk[i])chk[i]=1,st[++t]=i;
        if(i==n){
            printf("%d ",a[i]);
            i=st[--t];
            continue;
        }
        if(a[i]>a[i+1]){
            if(chk[i+1]){
                printf("%d ",a[i]);
                i=st[--t];
                continue;
            }
            ++i;
            continue;
        }
        if(a[i]<a[i+1]){
            if(chk[i+1]){
                i=st[--t];
                continue;
            }
            printf("%d ",a[i]);
            ++i;
            continue;
        }
    }
    return 0;
}
