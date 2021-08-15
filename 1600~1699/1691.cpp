#include <stdio.h>
#include <algorithm>
using namespace std;
struct adjacency_list{
    int e,nx;
}a[50010];
int st[2510],n,cnt;
int q[2510],l[2510],spt[2510][17];
void make_al(int s,int e){a[++cnt]={e,st[s]},st[s]=cnt;}
void make_tree(){
    int i,j,f=0,r=1,p,c;
    q[1]=l[1]=1;
    while(f<r){
        p=q[++f];
        for(i=st[p];i;i=a[i].nx){
            c=a[i].e;
            if(l[c])continue;
            q[++r]=c,spt[c][0]=p,l[c]=l[p]+1;
        }
    }
    for(i=1;i<17;++i){
        for(j=1;j<=n;++j)spt[j][i]=spt[spt[j][i-1]][i-1];
    }
}
int LCA(int s,int e){
    int i;
    if(l[s]<l[e])swap(s,e);
    for(i=16;i>=0;--i)if(l[s]-l[e]>=1<<i)s=spt[s][i];
    if(s==e)return s;
    for(i=16;i>=0;--i)if(spt[s][i]!=spt[e][i])s=spt[s][i],e=spt[e][i];
    return spt[s][0];
}
int main(){
    int i,m,x,y;
    scanf("%d",&m);
    n=m+1;
    for(i=1;i<=m;++i){
        scanf("%d%d",&x,&y);
        make_al(x,y);
        make_al(y,x);
    }
    make_tree();
    scanf("%d%d",&x,&y);
    printf("%d\n",LCA(x,y));
    return 0;
}
