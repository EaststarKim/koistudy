#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int a[210][210],lev[210],st[210],N,ans;
void bfs(){
	memset(lev,0,sizeof lev);
	queue<int> q;
	lev[1]=1;
	q.push(1);
	while(!q.empty()){
		int n=q.front();
		q.pop();
		for(int i=1;i<=N;++i){
			if(a[n][i]&&!lev[i]){
				lev[i]=lev[n]+1;
				q.push(i);
			}
		}
	}
}
int flow(int n,int c){
	if(n==N)return c;
	for(int &i=st[n];i<=N;++i){
		if(!a[n][i]|lev[n]>=lev[i])continue;
		int rc=flow(i,min(c,a[n][i]));
		if(rc){
			a[n][i]-=rc;
			a[i][n]+=rc;
			return rc;
		}
	}
	return 0;
}
int main(){
	int i,m,s,e,c;
	scanf("%d%d",&N,&m);
	for(i=0;i<m;++i){
		scanf("%d%d%d",&s,&e,&c);
		a[s][e]+=c,a[e][s]+=c;
	}
	while(1){
		bfs();
		if(!lev[N])break;
		memset(st,0,sizeof st);
		int rc;
		while((rc=flow(1,1e6))>0)ans+=rc;
	}
	printf("%d",ans);
	return 0;
}
