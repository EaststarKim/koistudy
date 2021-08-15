#include <stdio.h>
int t[1<<20],bit[1<<20],n;
int getsum(int k){
    int s=0;
    while(k){
        s+=bit[k];
        k-=k&-k;
    }
    return s;
}
void update(int k,int v){
    while(k<=n){
        bit[k]+=v;
        k+=k&-k;
    }
}
int main()
{
    int i,m,k,a,b;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i){
        scanf("%d",t+i);
        update(i,t[i]);
    }
    for(i=1;i<=m;++i){
        scanf("%d%d%d",&k,&a,&b);
        if(k&1)printf("%d\n",getsum(b)-getsum(a-1));
        else update(a,b-t[a]),t[a]=b;
    }
    return 0;
}
