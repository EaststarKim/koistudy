#include <bits/stdc++.h>
int a[4];
int main(){
	int i,j;
	for(i=2;i<6;++i)scanf("%d",a+i),a[i]+=a[i-1];
	for(i=1;i<6;++i){
		for(j=1;j<6;++j)printf("%d ",abs(a[i]-a[j]));
		puts("");
	}
	return 0;
}
