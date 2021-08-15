#include <bits/stdc++.h>
using namespace std;
int a[10],st[10],ans[20],s,t;
main(){
	int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)a[i]=-n+i-1;
    do{
		for(s=t=0,i=1;i<=n;++i){
			for(;s<=n&&st[t]!=-a[i];)st[++t]=++s;
			if(st[t]!=-a[i])break;
			--t;
		}
		if(i>n){
			for(i=1;i<=n;++i)printf("%d",-a[i]);
			puts("");
		}
    }while(next_permutation(a+1,a+n+1));
    return 0;
}
