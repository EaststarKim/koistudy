#include <stdio.h>
int a[16],d[21][16],p,m;
int main(){
	int i,j,t,n;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	d[a[1]][1]=1;
	for(i=2;i<n;++i){
		for(j=0;j<21;++j){
			p=m=0;
			t=j-a[i];
			if(0<=t&&t<=20)p=d[t][i-1];
			t=j+a[i];
			if(0<=t&&t<=20)m=d[t][i-1];
			d[j][i]=p+m;
		}
	}
	printf("%d",d[a[n]][n-1]);
	return 0;
}
