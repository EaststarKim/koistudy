#include <stdio.h>
int a[25][25],chk[25],mx,n;
void back(int p,int cnt){
	if(cnt+2*n-1-p<=mx)return;
	if(p==n*2-1){
		if(cnt>mx)mx=cnt;
		return;
	}
	int r=p, c=0;
	if(p>=n){
		c=p-n+1;
		r=n-1;
	}
	int flag=0;
	for(;r>=0&&c<n;r--,c++)if(a[r][c]&&!chk[n-c+r]){
		flag=1;
		chk[n-c+r]=1;
		back(p+1,cnt+1);
		chk[n-c+r]=0;
	}
	if(!flag)back(p+1,cnt);
}
int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		for(j=0;j<n;++j)scanf("%d",a[i]+j);
	}
	back(0, 0);
	printf("%d",mx);
	return 0;
}
