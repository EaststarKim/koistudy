#include <stdio.h>
long long a[10010],b[10010],D[10010],q[10010],n,f,r;
int T(int i,int j){return a[i-1]-a[j-1];}
int F(int i){return b[n]-b[i-1];}
int main(){
    int i,s;
    scanf("%d%d",&n,&s);
    for(i=1;i<=n;++i)scanf("%d%d",a+i,b+i),a[i]+=a[i-1],b[i]+=b[i-1];
    q[0]=n+1;
    for(i=n;i;--i){
        while(f<r&&T(q[f],q[f+1])*F(i)>D[q[f+1]]-D[q[f]])++f;
        D[i]=D[q[f]]+F(i)*(s+T(q[f],i));
        while(f<r&&(D[q[r]]-D[q[r-1]])*T(q[r-1],i)>(D[i]-D[q[r-1]])*T(q[r-1],q[r]))--r;
        q[++r]=i;
    }
    printf("%d",D[1]);
    return 0;
}
