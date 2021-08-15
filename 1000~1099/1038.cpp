#include <stdio.h>
#include <algorithm>
#define M 1024
using namespace std;
int a[1010][1010],mx[1010][1010],mn[1010][1010],s[3010],t[3010],ans;
int getmax(int l,int r){
    l+=M,r+=M;
    int lmx=s[l],rmx=s[r];
	while(l<r){
		if(l%2==0&&r%2)l/=2,r/=2;
		else l+=l%2,r-=!(r%2);
		lmx=max(lmx,s[l]),rmx=max(rmx,s[r]);
	}
	return max(lmx,rmx);
}
int getmin(int l,int r){
    l+=M,r+=M;
    int lmn=t[l],rmn=t[r];
	while(l<r){
		if(l%2==0&&r%2)l/=2,r/=2;
		else l+=l%2,r-=!(r%2);
		lmn=min(lmn,t[l]),rmn=min(rmn,t[r]);
	}
	return min(lmn,rmn);
}
int main(){
    int i,j,n,m,h,w;
    scanf("%d%d%d%d",&n,&m,&h,&w);
    for(i=0;i<n;++i){
        for(j=0;j<m;++j)scanf("%d",a[i]+j);
    }
    for(i=m;i<M;++i)t[M+i]=1e5;
    for(i=0;i<n;++i){
        for(j=0;j<m;++j)s[M+j]=a[i][j];
        for(j=M-1;j>0;--j)s[j]=max(s[j*2],s[j*2+1]);
        for(j=w-1;j<m;++j)mx[i][j-w+1]=getmax(j-w+1,j);
        for(j=0;j<m;++j)t[M+j]=a[i][j];
        for(j=M-1;j>0;--j)t[j]=min(t[j*2],t[j*2+1]);
        for(j=w-1;j<m;++j)mn[i][j-w+1]=getmin(j-w+1,j);
    }
    for(i=n;i<M;++i)s[M+i]=0,t[M+i]=1e5;
    for(i=0;i<=m-w;++i){
        for(j=0;j<n;++j)s[M+j]=mx[j][i];
        for(j=M-1;j>0;--j)s[j]=max(s[j*2],s[j*2+1]);
        for(j=h-1;j<n;++j)mx[j-h+1][i]=getmax(j-h+1,j);
        for(j=0;j<n;++j)t[M+j]=mn[j][i];
        for(j=M-1;j>0;--j)t[j]=min(t[j*2],t[j*2+1]);
        for(j=h-1;j<n;++j)mn[j-h+1][i]=getmin(j-h+1,j);
    }
    for(i=0;i<=n-h;++i){
        for(j=0;j<=m-w;++j)ans=max(ans,mx[i][j]-mn[i][j]);
    }
    printf("%d",ans);
    return 0;
}
