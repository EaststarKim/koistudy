#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
    int s,e;
}a[100010];
struct adjacency_list{
    int nx,ch;
}b[200010];
int st[100010],n,cnt;
int q[100010],l[100010],p[100010],spt[100010][17];
void make_al(int s,int e){b[++cnt].nx=st[s],b[cnt].ch=e,st[s]=cnt;}
void make_tree(){
    int i,j,f=0,r=1,pa,c;
    q[1]=1;
    while(f<r){
        pa=q[++f];
        for(i=st[pa];i;i=b[i].nx){
            c=b[i].ch;
            if(p[pa]==c)continue;
            q[++r]=c,p[c]=spt[c][0]=pa,l[c]=l[pa]+1;
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
    return p[s];
}
int main(){
    int i,m,x,y;
    scanf("%d%d",&n,&m);
    for(i=1;i<n;++i){
        scanf("%d%d",&a[i].s,&a[i].e);
        make_al(a[i].s,a[i].e),make_al(a[i].e,a[i].s);
    }
    make_tree();
    for(i=1;i<=m;++i){
        scanf("%d%d",&x,&y);
        printf("%d\n",LCA(x,y));
    }
    return 0;
}
