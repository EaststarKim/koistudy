#include <stdio.h>
int a[110],D[110][4][4],n;
int f(int p,int s,int t){
    int i;
    if(D[p][s][t])return D[p][s][t];
    if(p>n)return 1;
    if(a[p]){
        if(s==t&&t==a[p])return 0;
        return f(p+1,t,a[p]);
    }
    for(i=1;i<4;++i)if(s!=i||t!=i)D[p][s][t]+=f(p+1,t,i);
    return D[p][s][t]%=10000;
}
int main(){
    int m,k,l;
    scanf("%d%d",&n,&m);
    for(;m--;)scanf("%d%d",&k,&l),a[k]=l;
    printf("%d",f(1,0,0));
    return 0;
}
