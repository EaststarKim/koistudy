#include <stdio.h>
#include <string.h>
#define M 1000000007
char a[3][10010];
int D[3][10010][8][2],n,x,y;
int f(int r,int c,int s,int t){
	if(r>2)return f(0,c+1,s,t);
	if(c==n)return s==7&&t;
	int &ans=D[r][c][s][t];
	if(ans>=0)return ans;
	ans=0;
	if(a[r][c]!='.'){
		if(s&(1<<r))ans=f(r+1,c,s,t);
		return ans;
	}
	if(c>0&&!(s&(1<<r)))ans+=f(r+1,c,s|(1<<r),t||(x==r&&(y==c+1||y==c-2)));
	else{
		if(r>0&&!(s&(1<<(r-1))))ans+=f(r+1,c,s|(1<<(r-1)),t||(y==c&&(x==r+1||x==r-2)));
		ans+=f(r+1,c,s&~(1<<r),t);
	}
	return ans%=M;
}
int main(){
    int i,j;
	scanf("%d",&n);
	for(i=0;i<3;++i){
        scanf("%s",a+i);
        for(j=0;j<n;++j)if(a[i][j]=='O')x=i,y=j;
	}
	memset(D,-1,sizeof D);
	printf("%d",f(0,0,7,0));
	return 0;
}
