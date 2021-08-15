#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a[100010];
int p[100010],mn[100010],o[100010],idx[100010],sp[17][100010],n,cnt,ans;
bool cmp(int i,int j){return mn[i]<mn[j];}
void dfs(int n){
    int i,k,m;
    mn[n]=n;
    m=a[n].size();
    for(i=0;i<m;++i){
        k=a[n][i];
        dfs(k);
        mn[n]=min(mn[n],mn[k]);
    }
}
void post_order(int n){
    int i,m;
    for(i=1;i<17;++i)sp[i][n]=sp[i-1][sp[i-1][n]];
    m=a[n].size();
    for(i=0;i<m;++i)post_order(a[n][i]);
    idx[o[n]=++cnt]=n;
}
struct tree{
    int t[1<<19],lp[1<<19];
    void lazy_propagation(int n){
        if(!lp[n])return;
        int l=n*2,r=l+1;
        t[l]=t[r]=0,lp[l]=lp[r]=1;
        lp[n]=0;
    }
    void init(int n,int s,int e){
        if(s==e){
            t[n]=1;
            return;
        }
        int m=(s+e)/2,l=n*2,r=l+1;
        init(l,s,m);
        init(r,m+1,e);
        t[n]=t[l]+t[r];
    }
    void kcnt(int n,int s,int e,int k){
        if(s==e){
            ans=idx[s];
            return;
        }
        lazy_propagation(n);
        int m=(s+e)/2,l=n*2,r=l+1;
        if(t[l]<k)kcnt(r,m+1,e,k-t[l]);
        else kcnt(l,s,m,k);
    }
    void del(int n,int s,int e,int si,int ei){
        if(ei<s||e<si)return;
        if(si<=s&&e<=ei){
            t[n]=0,lp[n]=1;
            return;
        }
        lazy_propagation(n);
        int m=(s+e)/2,l=n*2,r=l+1;
        del(l,s,m,si,ei);
        del(r,m+1,e,si,ei);
        t[n]=t[l]+t[r];
    }
    int chk(int n,int s,int e,int p){
        if(s==e)return t[n];
        int m=(s+e)/2,l=n*2,r=l+1;
        lazy_propagation(n);
        if(p>m)return chk(r,m+1,e,p);
        else return chk(l,s,m,p);
    }
    void add(int n,int s,int e,int p){
        if(s==e){
            t[n]=1,lp[n]=0;
            return;
        }
        lazy_propagation(n);
        int m=(s+e)/2,l=n*2,r=l+1;
        if(p>m)add(r,m+1,e,p);
        else add(l,s,m,p);
        t[n]=t[l]+t[r];
    }
    void find_anc(int p){
        int i;
        ans=0;
        for(i=17;i--;)if(sp[i][p]&&!chk(1,1,n,o[sp[i][p]]))p=sp[i][p],ans+=(1<<i);
        add(1,1,n,o[p]);
    }
}segtree;
int main(){
    int i,q,k;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;++i){
        scanf("%d",sp[0]+i);
        if(!sp[0][i])k=i;
        else a[sp[0][i]].push_back(i);
    }
    dfs(k);
    for(i=1;i<=n;++i)sort(a[i].begin(),a[i].end(),cmp);
    post_order(k);
    segtree.init(1,1,n);
    for(;q--;){
        scanf("%d%d",&i,&k);
        if(i<2){
            segtree.kcnt(1,1,n,k);
            segtree.del(1,1,n,1,o[ans]);
        }
        else segtree.find_anc(k);
        printf("%d\n",ans);
    }
    return 0;
}
