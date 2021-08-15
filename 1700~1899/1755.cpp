#include <bits/stdc++.h>
using namespace std;
struct data{
    int i,g;
    bool operator<(const data&r)const{
        if(g==r.g)return i<r.i;
        return g<r.g;
    }
}a[1000010];
int st[1000010],g[1000010],t;
int seek(int n){return g[n]==n?n:g[n]=seek(g[n]);}
void uf(int a,int b){
    a=seek(a),b=seek(b);
    if(a<b)g[b]=a;
    else g[a]=b;
}
int main(){
    int i,j,n,k,mx;
    scanf("%d",&n);
    for(i=1;i<=n;++i)g[i]=i;
    for(i=1;i<=n;++i){
        scanf("%d",&k);
        mx=k;
        while(st[t]>k)uf(st[t],k),mx=max(mx,st[t--]);
        st[++t]=mx;
    }
    for(i=1;i<=n;++i)a[i]={i,seek(i)};
    sort(a+1,a+n+1);
    printf("%d\n",t);
    for(i=j=1;i<=n+1;++i)if(a[i].g!=a[j].g){
        printf("%d ",i-j);
        for(;j<i;++j)printf("%d ",a[j].i);
        puts("");
    }
    return 0;
}
