#include <stdio.h>
#include <string.h>
#define min(a,b) a<b? a:b
int a[5010][5010],visit[5010],ans,n,e;
int flow(int p, int f){
	int i,m;
	if(p==e)return f;
	visit[p]=1;
	for(i=1;i<=n;++i)if(a[p][i]&&!visit[i]){
		m=min(f,a[p][i]);
		int k=flow(i,m);
		if(k){
			a[p][i]-=k;
			a[i][p]+=k;
			return k;
		}
	}
	return 0;
}
int main()
{
	int i,x,y,c,m,s;
	scanf("%d%d%d%d",&n,&m,&s,&e);
	for(i=1;i<=m;++i){
		scanf("%d%d%d",&x,&y,&c);
		a[x][y]+=c;
	}
	while(1){
		memset(visit,0,sizeof(visit));
		int k=flow(s,1e9);
		if(!k)break;
		ans+=k;
	}
	printf("%d",ans);
	return 0;
}
