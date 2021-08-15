#include <stdio.h>
#include <string.h>
#define M 1000000007
int a[9][9],n,m;
int D[65][65536];
int f(int i,int j){
    int r=i/n,c=i%n,t,s=0;
	if(D[i][j]>=0)return D[i][j];
	if(i>=n*n)return D[i][j]=1;
	if(a[r][c]<j%4)return D[i][j]=0;
	else{
		t=a[r][c]-j%4;
		s=(s+f(i+1,j/4))%M;
		if(t>=1){
			if(c<n-1&&j/4%4<3)s=(s+f(i+1,j/4+1))%M;
			if(r<n-1)s=(s+f(i+1,j/4+m))%M;
		}
		if(t>=2){
			if(c<n-1&&j/4%4<2)s=(s+f(i+1,j/4+2))%M;
			if(r<n-1)s=(s+f(i+1,j/4+2*m))%M;
			if(c<n-1&&r<n-1&&j/4%4<3)s=(s+f(i+1,j/4+m+1))%M;
		}
		if(t>=3){
			if(c<n-1&&j/4%4<1)s=(s+f(i+1,j/4+3))%M;
			if(r<n-1)s=(s+f(i+1,j/4+3*m))%M;
			if(r<n-1&&c<n-1){
				if(j/4%4<2)s=(s+f(i+1,j/4+2+m))%M;
				if(j/4%4<3)s=(s+f(i+1,j/4+1+m*2))%M;
			}
		}
		return D[i][j]=s;
	}
}
int main(){
    int i,j;
	scanf("%d",&n);
	for(i=0;i<n;++i){
        for(j=0;j<n;++j)scanf("%d",a[i]+j);
	}
	m=1<<(n*2-2);
	memset(D,-1,sizeof(D));
	printf("%d",f(0,0));
	return 0;
}
