#include <stdio.h>
int a[110][110]={{1}},n,m,ans=1e5,ar,ac;
int x[]={-1,0,1,0},y[]={0,1,0,-1};
void BFS(int ro,int co){
	int q[2][10010]={},d[110][110]={},i,j,k,nr,nc,f=0,r=1;
	q[0][1]=n,q[1][1]=1;
	d[n][1]=1;
	while(f<r){
		i=q[0][++f],j=q[1][f];
		if(i==1&&j==m){
            if(ans>d[1][m])ans=d[1][m],ar=ro,ac=co;
            return;
		}
		for(k=0;k<4;++k){
			nr=i+x[k],nc=j+y[k];
			if(nr<1||nr>n||nc<1||nc>m||a[nr][nc]||d[nr][nc])continue;
			d[nr][nc]=d[i][j]+1;
			q[0][++r]=nr,q[1][r]=nc;
		}
	}
}
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)scanf("%d",a[i]+j);
	for(i=0;i<=n;++i)for(j=0;j<=m;++j)if(a[i][j])a[i][j]=0,BFS(i,j),a[i][j]=1;
	printf("%d %d\n%d",ar,ac,ans);
	return 0;
}
