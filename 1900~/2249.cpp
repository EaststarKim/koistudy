#include <bits/stdc++.h>
using namespace std;
int a[2000010],s[10][2000010];
long long ans;
int main(){
	int i,j,l,n,k,t;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<=n;++i)if((a[i]&k)==k){
		for(j=i;j<=n&&(a[j]&k)==k;++j){
			for(l=0;l<10;++l)if(!(k&(1<<l))){
				if(!(a[j]&(1<<l)))s[l][j]=1;
				s[l][j]+=s[l][j-1];
			}
		}
		for(;i<j;++i){
			for(t=l=0;l<10;++l)if(!(k&(1<<l)))t=max(t,lower_bound(s[l]+i,s[l]+j,s[l][i-1]+1)-s[l]);
			ans+=j-t;
		}
	}
	printf("%lld",ans);
	return 0;
}
