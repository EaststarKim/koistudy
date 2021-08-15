#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;
struct data{
    int r,c,chk;
}a[50010];
map<int,int> mr,mc;
int st[50010],r[50010],c[50010],rn,cn;
int main(){
    int i,j,n,x,y,rm,cm;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d%d",&x,&y);
        if(!mr[x])mr[x]=++rn;
        if(!mc[y])mc[y]=++cn;
        a[i].r=x=mr[x],a[i].c=y=mc[y];
        ++r[x],++c[y];
    }
    for(i=1;i<4;++i){
        for(rm=0,j=1;j<=rn;++j)if(r[rm]<r[j])rm=j;
        for(cm=0,j=1;j<=cn;++j)if(c[cm]<c[j])cm=j;
        if(r[rm]>c[cm]){
            r[rm]=0;
            for(j=1;j<=n;++j)if(a[j].r==rm&&!a[j].chk)a[j].chk=1,--c[a[j].c];
        }
        else{
            c[cm]=0;
            for(j=1;j<=n;++j)if(a[j].c==cm&&!a[j].chk)a[j].chk=1,--r[a[j].r];
        }
    }
    for(i=1;i<=n&&a[i].chk;++i);
    if(i>n)puts("1");
    else puts("0");
    return 0;
}
