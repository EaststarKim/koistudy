#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct data{
    int a,b;
    bool operator<(const data&r)const{
        if(b==r.b)return a<r.a;
        return b<r.b;
    }
}seq[10010];
int b[125010],an;
int main(){
    int i,j,k,n,m,s;
    scanf("%d%d",&n,&m);
    for(i=0;i<=m;++i){
        for(j=0;j<=m;++j)b[i*i+j*j]=1;
    }
    m=m*m*2;
    for(i=0;i<=m;++i)if(b[i]){
        for(j=1;j<=3000;++j){
            s=i;
            if(s+j*(n-1)>m)continue;
            for(k=1;k<n;++k){
                s+=j;
                if(!b[s])break;
            }
            if(k==n)seq[an].a=i,seq[an++].b=j;
        }
    }
    sort(seq,seq+an);
    if(!an)puts("NONE");
    for(i=0;i<an;++i)printf("%d %d\n",seq[i].a,seq[i].b);
    return 0;
}
