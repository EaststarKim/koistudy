#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1010][1010],q[1000010],w[1010],n,D;
void f(int p){
    int i,t,f=0,r=1;
    w[p]=2e9;
    q[1]=p;
    while(f<r){
        p=q[++f];
        for(i=1;i<=n;++i)if(a[p][i]){
            t=min(w[p],a[p][i]);
            if(w[i]<t)w[i]=t,q[++r]=i;
        }
    }
}
int main(){
    int i,m,S,T,s,d,t;
    scanf("%d%d%d%d%d",&n,&m,&S,&D,&T);
    for(i=1;i<=m;++i)scanf("%d%d%d",&s,&d,&t),a[s][d]=a[d][s]=t;
    f(S);
    printf("%d",(T-1)/(w[D]-1)+1);
    return 0;
}
