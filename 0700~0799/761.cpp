#include <stdio.h>
#include <algorithm>
using namespace std;
#define M 2137
int c[M][M],p[3],q[3];
long long s;
struct data{
	int x,y,z;
	bool operator<(const data&r)const{
		if(x==r.x)return y<r.y;
		return x<r.x;
	}
}a[M+2];
void f(int n,int *a){a[0]=n%M,n/=M,a[1]=n%M,n/=M,a[2]=n;}
void L(){
	int i;
	for(i=0,s=1;i<3;++i){
        if(p[i]<q[i])s=0;
        s=(s*c[p[i]][q[i]])%M;
	}
}
int main(){
	int i,j,n,m,k,x,y;
	for(i=0;i<M;++i){
        c[i][0]=c[i][i]=1;
        for(j=i/2;j;--j)c[i][j]=c[i][i-j]=(c[i-1][j]+c[i-1][j-1])%M;
	}
	scanf("%d%d%d",&n,&m,&k);
	a[0].z=1;
	a[k+1].x=n,a[k+1].y=m;
	for(i=1;i<=k;++i)scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+k+1);
	for(i=0;i<=k;++i){
		for(j=i+1;j<=k+1;++j)if(a[i].y<=a[j].y){
            x=a[j].x-a[i].x,y=a[j].y-a[i].y;
            f(x+y,p),f(x,q),L();
            if(i)a[j].z-=a[i].z*s;
            else a[j].z+=s;
            a[j].z=(a[j].z+M)%M;
		}
	}
	printf("%d",(a[k+1].z+M)%M);
	return 0;
}
