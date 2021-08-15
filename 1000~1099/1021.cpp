#include <stdio.h>
long long s[10][9],t[10][9],ans[10];
char c[1000010];
int main(){
	int i,j,k,n;
	scanf("%d\n%s",&n,c+1);
	for(i=1;i<=n;++i){
		for(j=2;j<10;++j){
			++s[j][0];
			for(k=0;k<j;++k)t[j][(k*10+c[i]-48)%j]+=s[j][k];
			for(k=0;k<j;++k)s[j][k]=t[j][k],t[j][k]=0;
			ans[j]+=s[j][0];
		}
	}
	for(i=2;i<10;++i)printf("%lld\n",ans[i]);
	return 0;
}
