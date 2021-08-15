#include <stdio.h>
int a[110],b[10010],cnt;
int main(){
    int i,j,n,l,t;
    scanf("%d%d",&n,&l);
    for(i=1;i<=n;++i)scanf("%d",a+i),b[a[i]]=1;
    for(i=1;i<l*2;++i){
        for(j=1;j<=n;++j){
            t=i-a[j];
            if(0<=t&&t<=l&&!b[t])break;
        }
        if(j>n)++cnt;
    }
    printf("%d",cnt);
    return 0;
}
