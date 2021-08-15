#include <stdio.h>
#include <string.h>
int a[210][210],left[210],right[210],visit[210],ans,m;
int augment(int n){
    int i;
    for(i=1;i<=m;++i)if(a[n][i]&&!visit[i]){
        visit[i]=1;
        if(!right[i]||augment(right[i])){
            left[n]=i,right[i]=n;
            return 1;
        }
    }
    return 0;
}
int main(){
	int i,j,n,k,e;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%d",&k);
		for(j=1;j<=k;++j)scanf("%d",&e),a[i][e]=1;
		memset(visit,0,sizeof visit);
		ans+=augment(i);
	}
	printf("%d",ans);
	return 0;
}
