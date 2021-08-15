#include <stdio.h>
#include <algorithm>
#include <time.h>
#include <math.h>
using namespace std;
char c[33];
int a[33][33],b[33][33],s;
int main(){
    srand(time(NULL));
    int i,j,k,n,x,y,t;
    long double p=1;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%s",c+1);
		for(j=1;j<=n;++j)a[i][j]=(c[j]=='T'),s+=a[i][j];
	}
	x=s;
	for(k=1e4;--k;p*=0.9999){
        for(i=1;i<=n;++i)for(j=1;j<=n;++j)b[i][j]=a[i][j];
        i=rand()%n+1;
        for(j=1;j<=n;++j)b[i][j]=!b[i][j];
        for(j=1,y=0;j<=n;++j){
            t=0;
            for(i=1;i<=n;++i)t+=b[i][j];
            y+=min(t,n-t);
        }
		if(x-y>p*log(rand()%10000/1e4)){
			s=min(s,min(x,y)),x=y;
			for(i=1;i<=n;++i)for(j=1;j<=n;++j)a[i][j]=b[i][j];
		}
	}
	printf("%d",s);
	return 0;
}
