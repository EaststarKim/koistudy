#include <stdio.h>
#include <math.h>
int cnt,n,x;
void back(int k,int r,int ld,int rd){
    int p,a;
    if(k>n){
        ++cnt;
        return;
    }
    ld<<=1;
    rd>>=1;
    a=r|ld|rd;
    while(1){
        p=((~a)&(a+1))%x;
        if(!p)return;
        a+=p;
        back(k+1,r+p,ld+p,rd+p);
    }
}
int main()
{
    int i,m,t;
    scanf("%d",&n);
    x=t=pow(2,n);
	m=n/2;
    for(i=1;i<=m;++i){
        t>>=1;
        back(2,t,t,t);
    }
	cnt<<=1;
	if(n%2){
	    t>>=1;
		back(2,t,t,t);
	}
	printf("%d",cnt);
    return 0;
}
