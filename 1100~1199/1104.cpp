#include <stdio.h>
int a[20],b[20],t;
int main(){
    int i,k,n,mi;
    long long m;
	scanf("%lld%d",&m,&k);
	for(n=1;m;++n)a[n]=m%10,m/=10;
	for(;--n;){
        mi=n;
		for(i=n-1;i&&i>=n-k;--i)if(a[mi]<a[i])mi=i;
		b[++t]=a[mi];
		k-=n-mi;
		for(i=mi;i<n;++i)a[i]=a[i+1];
	}
	for(i=1;i<=t;++i)printf("%d",b[i]);
	return 0;
}
