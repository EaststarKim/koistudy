#include<stdio.h>
int h[5010],l[5010],t[5010],cnt;
int main(){
	int n,i,j,mx,mi;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d%d",h+i,l+i);
	for(i=1;i<=n;++i){
        mx=0;
        for(j=1;j<=cnt;++j)if(h[i]-l[i]>=t[j]&&mx<t[j])mx=t[mi=j];
        if(!mx)mi=++cnt;
        t[mi]=h[i];
	}
	printf("%d",cnt);
	return 0;
}
