#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int M=101;
vector<int> v[M*M];
int a[M][M],g[M][M],chk[M][M],visit[M*M],q[M*M],d[M*M],node[M*M],cnt,n,m,td,md,ans=M*M;
int dr[]={-1,0,1,0},dc[]={0,1,0,-1};
void back(int r,int c){
	int i,nr,nc;
	g[r][c]=cnt;
	for(i=0;i<4;++i){
		nr=r+dr[i];
		nc=c+dc[i];
		if(nr<1||nr>n||nc<1||nc>m||a[nr][nc]!=a[r][c]||g[nr][nc])continue;
		back(nr,nc);
	}
}
void make_graph(int r,int c){
	int i,nr,nc,s,e;
	chk[r][c]=1;
	s=g[r][c];
	for(i=0;i<4;++i){
		nr=r+dr[i];
		nc=c+dc[i];
		if(nr<1||nr>n||nc<1||nc>m)continue;
		e=g[nr][nc];
		if(e!=s&&visit[e]!=s){
            v[s].push_back(e);
            visit[e]=s;
		}
		else if(!chk[nr][nc])make_graph(nr,nc);
	}
}
void BFS(int k)
{
    int i,f=0,r=1,p,t,e;
    node[k]=1;
	for(i=1;i<=cnt;++i)d[i]=-1;
	q[1]=k;
	d[k]=0;
	while(f<r){
		p=q[++f];
		t=v[p].size();
		for(i=0;i<t;++i){
            e=v[p][i];
            if(d[e]<0){
                d[e]=d[p]+1;
                q[++r]=e;
                if(d[e]>=ans)node[e]=1;
            }
		}
	}
	md=d[p];
	ans=min(ans,md);
	for(i=f;i>0;--i){
        if(d[q[i]]!=md)break;
        node[q[i]]=1;
	}
	for(i=1;i<=cnt;++i){
        if(d[i]<=md-ans)node[i]=1;
	}
}
int main()
{
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j)scanf("%d",&a[i][j]);
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j)if(!g[i][j]){
			++cnt;
			back(i,j);
		}
	}
	if(cnt==1){
		printf("0");
		return 0;
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j)if(!chk[i][j])make_graph(i,j);
	}
	BFS(1);
	ans=md;
	for(i=1;i<=cnt;++i)if(d[i]==md/2)BFS(i);
    for(i=2;i<=cnt;++i)if(!node[i])BFS(i);
	printf("%d",ans);
	return 0;
}
