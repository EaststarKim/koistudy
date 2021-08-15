#include <stdio.h>
int a[1010];
int main(){
	int i,n,m,t;
	scanf("%d",&n);
	for(i=1;i<=n;++i)a[i]=i;
	for(t=1;n;){
        for(m=0,i=1;i<=n;++i,t=!t){
            if(t)printf("%d ",a[i]);
            else a[++m]=a[i];
        }
        n=m;
	}
	return 0;
}
