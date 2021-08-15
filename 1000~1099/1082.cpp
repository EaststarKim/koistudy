#include <stdio.h>
int a[300010],bit[1<<17];
int getsum(int k){
    int s=0;
    while(k)s+=bit[k],k-=k&-k;
    return s;
}
void update(int k,int v){while(k<100001)bit[k]+=v,k+=k&-k;}
int main(){
    int i,n,q,t,k;
    double s;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%lf",&s);
        a[i]=s*100+1.1;
        update(a[i],1);
    }
    scanf("%d",&q);
    for(i=1;i<=q;++i){
        scanf("%d%d",&t,&k);
        if(t==1)printf("%d\n",n-getsum(a[k])+1);
        else{
            scanf("%lf",&s);
            update(a[k],-1);
            a[k]=s*100+1.1;
            update(a[k],1);
        }
    }
    return 0;
}
