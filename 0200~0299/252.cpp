#include <stdio.h>
int n,,mx,flag;
char a[360];
int main(){
	int i,t,ii,tt,c;
	scanf("%d",&n);
	scanf("%s",a);
	for(i=0;i<n;++i){
		t=a[i];
		tt=a[i+1];
		if(t!=tt){
			flag=1;
			c=1;
			ii=i;
			while(1){
				--ii;
				if(ii==-1)ii=n-1;
				if(t=='w'&&a[ii]!='w')t=a[ii],++c;
				else if(a[ii]==t||a[ii]=='w')++c;
				else break;
				if(c>=n){
					printf("%d",n);
					return 0;
				}
			}
			ii=i;
			while(1){
				++ii;
				if(ii==n)ii=0;
				if(tt=='w'&&a[ii]!='w')tt=a[ii],++c;
				else if(a[ii]==tt||a[ii]=='w')++c;
				else break;
				if(c>=n){
					printf("%d",n);
					return 0;
				}
			}
			if(c>mx)mx=c;
		}
	}
	printf("%d",flag?mx:n);
	return 0;
}
