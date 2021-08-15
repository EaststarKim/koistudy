#include <stdio.h>
int h[500010];
int main(){
	int n,k,i,j,l=1,r=1<<20,m;
	long long cnt,s=0,t;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i)scanf("%d",h+i),s+=h[i];
	while(l<=r){
		m=(l+r)/2;
		cnt=0;
		for(i=1;i<=n;++i)cnt+=(h[i]-1)/m+1;
		if(cnt>k)l=m+1;
		else t=m,r=m-1;
	}
	cnt=0;
	for(i=1;i<=n;++i)cnt+=(h[i]-1)/t+1;
	printf("%d",(t*cnt-s)%1000000007);
	return 0;
}
