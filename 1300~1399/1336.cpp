#include <stdio.h>
#include <algorithm>
using namespace std;
struct data{
	int w,i;
	bool operator<(const data&r)const{
		return w<r.w;
	}
}a[1010];
int chk[1010],mn=1e4,ans;
int main(){
	int i,n,t,tm,ts,l;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&a[i].w);
		a[i].i=i;
		mn=min(mn,a[i].w);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;++i){
        for(t=i,tm=1e4,ts=l=0;!chk[t];++l){
            chk[t]=1;
            ts+=a[t].w;
            tm=min(tm,a[t].w);
            t=a[t].i;
        }
        if(l>1)ans+=min(ts+(l-2)*tm,tm+ts+(l+1)*mn);
	}
	printf("%d",ans);
	return 0;
}
