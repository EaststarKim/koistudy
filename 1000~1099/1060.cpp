#include <stdio.h>
int a[101][101],g[101][101],cnt,n,m,o;
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
			if(a[i][j])++o;
			back(i,j);
		}
	}
	printf("%d\n%d",cnt-o,o);
	return 0;
}
