#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100010],t[300010],e[100010];
int back(int li,int ri){
	int lmax=t[li],rmax=t[ri];
	while(li<ri){
		if(li%2==0&&ri%2)li/=2,ri/=2;
		else li+=li%2,ri-=!(ri%2);
		lmax=max(lmax,t[li]),rmax=max(rmax,t[ri]);
	}
	return max(lmax,rmax);
}
int main(){
	int i,j,n,q,l,r,b=1,k=-1;
	scanf("%d%d",&n,&q);
	for(i=0;i<n;++i)scanf("%d",a+i);
	while(b<n)b*=2;
	t[b]=1;
	for(i=1;i<n;++i){
        t[i+b]=t[i+b-1]+1;
        if(a[i]!=a[i-1]){
            for(j=i-1;j>k;--j)e[j]=i-1;
            k=i-1,t[i+b]=1;
        }
    }
    for(j=n-1;j>k;--j)e[j]=n-1;
	for(i=b-1;i>0;--i)t[i]=max(t[i*2],t[i*2+1]);
	for(i=1;i<=q;++i){
		scanf("%d%d",&l,&r);
		--l,--r;
		if(e[l]<r)printf("%d\n",max(e[l]-l+1,back(e[l]+b+1,r+b)));
		else printf("%d\n",r-l+1);
	}
	return 0;
}
