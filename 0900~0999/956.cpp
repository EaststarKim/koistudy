#include <stdio.h>
int a[11][11],chk[11],ans=1e9,n;
void back(int p,int s,int cnt){
	int i;
	if(s>=ans)return;
	if(cnt==n&&p==n){
		ans=s;
		return;
	}
	chk[p]=1;
	for(i=1;i<=n;++i)if(a[p][i]&&!chk[i]){
	    back(i,s+a[p][i],cnt+1);
        chk[i]=0;
	}
}
int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j)scanf("%d",a[i]+j);
	}
	back(1,0,1);
	printf("%d",ans);
	return 0;
}
