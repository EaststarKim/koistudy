#include <stdio.h>
#include <string.h>
int a[2010][2010],chk[2010],cnt[2010],k,s;
void back(int p){
	int i;
	chk[p]=1;
	for(i=1;i<=a[p][0];++i)if(!chk[a[p][i]]){
        ++cnt[k];
        ++cnt[a[p][i]];
        back(a[p][i]);
    }
}
int main(){
	int i,x,y,n,m;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		a[x][++a[x][0]]=y;
	}
	for(i=1;i<=n;++i){
		k=i;
		back(i);
		memset(chk,0,sizeof(chk));
	}
	for(i=1;i<=n;++i)printf("%d\n",n-cnt[i]-1);
	return 0;
}
