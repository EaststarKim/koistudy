#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;
int c[50010],o[50010],n,m,cnt;
int idx[50010],sz[50010];
vector<int> g[50010],b[50010],s[50010];
vector<pair<int,int>> t[50010];
void dfs(int x){
    int i;
    sz[x]=1;
    idx[o[x]=++cnt]=x;
    b[c[x]].push_back(o[x]);
    for(i=0;i<g[x].size();++i){
        dfs(g[x][i]);
        sz[x]+=sz[g[x][i]];
    }
}
int x,y;
map<pair<int,int>,long long> mp;
long long f1(){
    int i,l,r;
    long long ans=0;
    for(i=0;i<b[x].size();++i){
        l=b[x][i];
        r=l+sz[idx[l]]-1;
        l=lower_bound(b[y].begin(),b[y].end(),l)-b[y].begin();
        r=upper_bound(b[y].begin(),b[y].end(),r)-b[y].begin()-1;
        ans+=r-l+1;
    }
    mp[{x,y}]=ans;
    return ans;
}
long long f2(){
    int i,p;
    long long ans=0;
    for(i=0;i<b[y].size();++i){
        p=b[y][i];
        p=lower_bound(t[x].begin(),t[x].end(),make_pair(p,10))-t[x].begin()-1;
        ans+=p<0?0:s[x][p];
    }
    mp[{x,y}]=ans;
    return ans;
}
pair<int,int> a[50010];
long long f3(){
    int i,j,s,tp=0;
    long long ans=0;
    for(i=j=0;i!=t[x].size()||j!=b[y].size();){
        if(i==t[x].size())a[tp++]={b[y][j++],2};
        else if(j==b[y].size())a[tp++]=t[x][i++];
        else if(t[x][i].first<=b[y][j])a[tp++]=t[x][i++];
        else a[tp++]={b[y][j++],2};
    }
    for(i=s=0;i<tp;++i){
        if(a[i].second==2)ans+=s;
        else s+=a[i].second;
    }
    mp[{x,y}]=ans;
    return ans;
}
int main(){
    int i,j,k,p,q,sum;
    scanf("%d%d",&n,&m);
    for(i=2;i<=n;++i){
        scanf("%d",&p);
        g[p].push_back(i);
    }j
    for(i=1;i<=n;++i)scanf("%d",c+i);
    dfs(1);
    for(i=1;i<=m;++i){
        for(j=0;j<b[i].size();++j){
            t[i].push_back({b[i][j],1});
            t[i].push_back({b[i][j]+sz[idx[b[i][j]]],-1});
        }
        sort(t[i].begin(),t[i].end());
        sort(b[i].begin(),b[i].end());
        for(j=sum=0;j<t[i].size();++j)s[i].push_back(sum+=t[i][j].second);
    }
    scanf("%d",&q);
    for(;q--;){
        long long ans=0;
        scanf("%d%d",&x,&y);
        for(i=0;i<2;++i){
            if(mp[{x,y}])ans+=mp[{x,y}];
            else{
                int c1=b[x].size()*log2(b[y].size());
                int c2=b[y].size()*log2(t[x].size());
                int c3=t[x].size()+b[y].size();
                int mn=min(c1,min(c2,c3));
                if(mn==c1)ans+=f1();
                else if(mn==c2)ans+=f2();
                else ans+=f3();
            }
            swap(x,y);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
