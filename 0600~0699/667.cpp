//Dinic Algorithm
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int LM=10010;
const int SZ=1010;
struct E{
	int n,c,p;//n:자식의 노드 번호 c:용량 p:자식의 adj[n]에서 자신의 위치
	E(){}E(int n,int c,int p):n(n),c(c),p(p){}
};
vector<E> adj[SZ];
int lev[SZ],st[SZ];
int N,M,ans;

void bfs(int s){
	memset(lev,-1,sizeof lev);
	queue<int> q;
	lev[s]=0;
	q.push(s);
	while(!q.empty()){
		int n=q.front();
		q.pop();
		for(int i=0;i<(signed)adj[n].size();++i){
			E &e=adj[n][i];
			if(e.c>0&&lev[e.n]<0){
				lev[e.n]=lev[n]+1;
				q.push(e.n);
			}
		}
	}
}

int flow(int n,int c){
	if(n==N)return c;
	for(int &i=st[n];i<(signed)adj[n].size();++i){
		E &e=adj[n][i];
		if(e.c<=0||lev[n]>=lev[e.n])continue;
		int rc=flow(e.n,min(c,e.c));
		if(rc){
			e.c-=rc;
			adj[e.n][e.p].c+=rc;
			return rc;
		}
	}
	return 0;
}

int main()
{
	scanf("%d%d",&N,&M);
	int i,s,e,c;
	for(i=0;i<M;++i){
		scanf("%d%d%d",&s,&e,&c);
		adj[s].push_back(E(e,c,adj[e].size()));
		adj[e].push_back(E(s,0,adj[s].size()-1));
	}
	while(1){
		bfs(1);
		if(lev[N]<0)break;
		memset(st,0,sizeof st);
		int rc;
		while((rc=flow(1,LM))>0){
			ans+=rc;
		}
	}
	printf("%d",ans);
	return 0;
}
