#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[18][18],visit[18],ans;
int t[4][8]={1,1,1,1,1,1,1,1,0,0,1,1,0,0,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,1,1};
int flow(int p,int f){
	int i,m;
	if(p==17)return f;
	visit[p]=1;
	for(i=1;i<18;++i)if(a[p][i]&&!visit[i]){
		m=min(f,a[p][i]);
		int k=flow(i,m);
		if(k){
			a[p][i]-=k,a[i][p]+=k;
			return k;
		}
	}
	return 0;
}
int main(){
	int i,j;
	for(i=1;i<9;++i)scanf("%d",a[0]+i);
	for(i=9;i<17;++i)scanf("%d",a[i]+17);
	for(i=1;i<9;++i){
        for(j=1-i%2;j<9;j+=2-i%2)if(t[(i-1)/2][j])a[i][j+9]=1e8;
	}
	while(1){
		memset(visit,0,sizeof visit);
		int k=flow(0,1e8);
		if(!k)break;
		ans+=k;
	}
	printf("%d",ans);
	return 0;
}
