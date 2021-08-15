#include <bits/stdc++.h>
using namespace std;
int d[100010],q[100010],s,f,r=1;
int main(){
    int i,n,m,t;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)scanf("%d",&t),s+=t;
    d[q[1]=s]=1;
    while(f<r){
        s=q[++f];
        for(i=max(0,m-n+s);i<=min(s,m);++i)if(!d[s+m-i*2])d[s+m-i*2]=d[s]+1,q[++r]=s+m-i*2;
        if(d[0])break;
    }
    printf("%d",d[0]-1);
    return 0;
}
