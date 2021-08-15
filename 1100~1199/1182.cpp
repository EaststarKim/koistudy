#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[210][210],visit[210],ans,n;
int flow(int p,int f){
	int i,m;
	if(p==n)return f;
	visit[p]=1;
	for(i=2;i<=n;++i)if(a[p][i]&&!visit[i]){
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
int main(){
	int i,m,s,e,c;
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;++i){
		scanf("%d%d%d",&s,&e,&c);
		a[s][e]+=c;
	}
	while(1){
		memset(visit,0,sizeof visit);
		int k=flow(1,1e8);
		if(!k)break;
		ans+=k;
	}
	printf("%d",ans);
	return 0;
}
