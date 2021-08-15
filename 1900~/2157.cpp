#include <bits/stdc++.h>
using namespace std;
int D[10010];
int main(){
	int i,n,W,w,v;
	scanf("%d%d",&n,&W);
	for(;n--;){
		scanf("%d%d",&w,&v);
		for(i=W-w+1;i--;)D[i+w]=max(D[i+w],D[i]+v);
	}
	printf("%d",D[W]);
	return 0;
}
