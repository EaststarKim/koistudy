#include <stdio.h>
#include <queue>
using namespace std;
struct data{
	int r,c,d;
	data(){}
	data(int r,int c,int d):r(r),c(c),d(d){}
	bool operator<(const data&r)const{
		return d>r.d;
	}
};
priority_queue<data> q;
char a[51][51];
int chk[51][51],n,m;
int x[]={-1,0,1,0},y[]={0,1,0,-1};
int bfs(int r,int c){
    int i,nr,nc,d;
    data t=data(r,c,0);
	q.push(t);
	chk[r][c]=1;
	while(!q.empty()){
		t=q.top();
		q.pop();
		if(a[t.r][t.c]=='X'&&t.d)return t.d;
		for(i=0;i<4;++i){
			nr=t.r+x[i],nc=t.c+y[i],d=t.d;
			if(nr<0||nr>=n||nc<0||nc>=m||chk[nr][nc])continue;
			chk[nr][nc]=1;
			if(a[nr][nc]=='.')++d;
			q.push(data(nr,nc,d));
		}
	}
}
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i)scanf("%s",a[i]);
	for(i=0;i<n;++i){
		for(j=0;j<m&&a[i][j]=='.';++j);
		if(j<m)break;
	}
	printf("%d",bfs(i,j));
	return 0;
}
