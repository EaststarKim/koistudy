#include <bits/stdc++.h>
using namespace std;
int a[110][110],b[110][110];
int main(){
	int i,j,n,mn=1e9;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		for(j=0;j<n;++j)scanf("%d",a[i]+j),mn=min(mn,a[i][j]);
	}
	for(;;){
		for(i=0;i<n;++i)for(j=0;j<n;++j)b[n-j-1][i]=a[i][j];
		for(i=0;i<n;++i)for(j=0;j<n;++j)a[i][j]=b[i][j];
		if(a[0][0]==mn){
			for(i=0;i<n;++i){
				for(j=0;j<n;++j)printf("%d ",a[i][j]);
				puts("");
			}
			break;
		}
	}
	return 0;
}
