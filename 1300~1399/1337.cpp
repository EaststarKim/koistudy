#include <stdio.h>
int ans[21]={0,1};
void h(int s,int n,char a,char b,char c){
    if(!n)return;
    h(s,n-1,a,c,b);
    printf("%d : %c->%c\n",s+n-1,a,c);
    h(s,n-1,b,a,c);
}
void f(int n,char a,char b,char c,char d){
    if(n==1){
        printf("1 : %c->%c\n",a,d);
        return;
    }
    int i;
    for(i=n-1;i;--i)if(ans[n]==(1<<i)-1+2*ans[n-i])break;
    f(n-i,a,c,d,b);
    h(n-i+1,i-1,a,d,c);
    printf("%d : %c->%c\n",n,a,d);
    h(n-i+1,i-1,c,a,d);
    f(n-i,b,a,c,d);
}
int main(){
	int i,j,n,m=0,k=1;
	scanf("%d",&n);
	for(i=2;i<=n;++i){
		ans[i]=300;
		for(j=1;j<i;++j){
			k=(1<<j)-1+2*ans[i-j];
			if(ans[i]>k)ans[i]=k;
		}
	}
	printf("%d\n",ans[n]);
	f(n,'A','B','C','D');
	return 0;
}
