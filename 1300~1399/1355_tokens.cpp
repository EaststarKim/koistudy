#include "tokens.h"
int a[40][40],t[40],chk[40],n;
void init(int N, int A[40][40]){
    int i,j;
    n=N;
	for(i=0;i<n;++i){
		for(j=0;j<n;++j)a[i][j]=A[i][j];
	}
	for(i=0;i<n;++i){
        for(j=0;j<n;++j)t[i]+=a[i][j]+a[j][i];
	}
}
int play(int X){
    int i,m=n;
    chk[X]=1;
	for(i=0;i<n;++i)if(!chk[i]){
        if(t[m]<t[i])m=i;
	}
	if(m<n)chk[m]=1;
	return m<n?m:-1;
}
