#include <stdio.h>
struct data{
    int e,nx;
}a[22010];
int st[14010],cnt;
void make_al(int s,int e){a[++cnt]={e,st[s]},st[s]=cnt;}
int t[14010],s[14010],in[14010];
int main(){
    int i,j,n,m,k,l,x,y,z,w;
    scanf("%d%d%d%d",&n,&m,&k,&l);
    for(i=1;i<=k;++i)scanf("%d",t+n+i);
    for(i=1;i<=l;++i){
        scanf("%d%d%d%d",&x,&y,&z,&w);
        if(x>1)y+=n;
        w+=n;
        if(z<2)w+=k;
        make_al(y,w);
        ++in[w];
    }
    for(i=1;i<=n;++i)scanf("%d",s+i);
    for(i=1;i<=n+k;++i){
        for(j=1;j<=n+k;++j)if(!in[j])break;
        in[x=j]=-1;
        for(j=st[x];j;j=a[j].nx){
            --in[a[j].e];
            if(n<a[j].e&&a[j].e<=n+k){
                if(in[a[j].e])s[a[j].e]=s[x];
                else{
                    if(t[a[j].e]==1)s[a[j].e]&=s[x];
                    else if(t[a[j].e]==2)s[a[j].e]|=s[x];
                    else s[a[j].e]=!s[x];
                }
            }
            else s[a[j].e]=s[x];
        }
    }
    for(i=1;i<=m;++i)printf("%d ",s[n+k+i]);
    return 0;
}
