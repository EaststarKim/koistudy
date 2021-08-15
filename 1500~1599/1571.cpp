#include <stdio.h>
int a[1000010],b[1000010],an;
long long D[1000010],E[1000010],dq[1000010],ans=1e12;
void proc(int *a,long long *t){
    int i,f=0,r=0;
    for(i=1;i<=an;++i){
        while(f<r&&-dq[f]*a[i]+t[dq[f]]>=-dq[f+1]*a[i]+t[dq[f+1]])++f;
        t[i]=t[dq[f]]+(i-dq[f]+1)*a[i];
        while(f<r&&(t[dq[r]]-t[dq[r-1]])*(i-dq[r])>=(t[i]-t[dq[r]])*(dq[r]-dq[r-1]))--r;
        dq[++r]=i;
    }
}
int main(){
    int i,n,t;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&t);
        if(t)a[++an]=i;
    }
    for(i=1;i<=an;++i)b[an-i+1]=n-a[i]+1;
    proc(a,D);
    proc(b,E);
    for(i=0;i<=an;++i)if(ans>D[i]+E[an-i])ans=D[i]+E[an-i];
    printf("%lld",ans);
    return 0;
}
