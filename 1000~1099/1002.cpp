#include <stdio.h>
#include <stdlib.h>
struct data{
    int x,y;
}a[3010];
int b[3010],q[1000010],d[21],ans[3010],n,m,k,h,hp,s;
void BFS(){
	int i,p,f=0,r=1,t;
	for(i=1;i<=n+1;++i)b[i]=k+1;
	q[1]=0;
	while(f<r){
		p=q[++f];
		if(p==n+1)return;
		for(i=1;i<=n+1;++i){
			if(i==p||(i<n+1&&b[i]<b[p]+2)||(i==n+1&&b[i]<b[p]+1))continue;
			if(b[p]==k)i=n+1;
			t=abs(a[i].x-a[p].x)+abs(a[i].y-a[p].y);
			if(t<=h){
				q[++r]=i;
				if(i<n+1)b[i]=b[p]+1;
				else b[i]=b[p];
			}
		}
	}
}
void bs(int l,int r){
	h=(l+r)/2;
	BFS();
	if(l==r){
		s=l-hp;
		return;
	}
	if(b[n+1]<=k)bs(l,h);
	else bs(h+1,r);
}
int main()
{
	int i,j;
	scanf("%d%d%d%d",&n,&m,&k,&hp);
	for(i=1;i<=m;++i)scanf("%d",d+i);
	for(i=1;i<=n;++i)scanf("%d%d",&a[i].x,&a[i].y);
	a[n+1].x=a[n+1].y=1000;
	bs(1,2000);
	ans[0]=1;
	for(i=1;i<=m;++i){
        for(j=2000;j>=0;--j){
            if(ans[j])ans[j+d[i]]=1;
        }
	}
	for(i=0;i<=2000;++i){
        if(i>=s&&ans[i])break;
	}
	if(i>2000)puts("-1");
	else printf("%d",i);
	return 0;
}
