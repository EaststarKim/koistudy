#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1005],b[1005],c[1005],ans;
char x[1005];
int main()
{
    int i,n,t,t1,t2,t3;
    scanf("%d",&n);
	scanf(" %s",x+1);
    for(i=1;i<=n;i++){
        if(x[i]=='R')t=1;
        else if(x[i]=='Y')t=2;
        else t=3;
        a[i]=b[i]=t;
    }
    sort(b+1,b+n+1);
    for(i=1;i<=n;i++){
        if(a[i]==1&&b[i]==2)c[1]++;
        else if(a[i]==2&&b[i]==1)c[2]++;
        else if(a[i]==3&&b[i]==2)c[3]++;
        else if(a[i]==2&&b[i]==3)c[4]++;
        else if(a[i]==1&&b[i]==3)c[5]++;
        else if(a[i]==3 && b[i]==1)c[6]++;
    }
    t1=min(c[1],c[2]);
    t2=min(c[3],c[4]);
    t3=min(c[5],c[6]);
    ans+=(t1+t2+t3);
    c[1]-=t1,c[2]-=t1,c[3]-=t2,c[4]-=t2,c[5]-=t3,c[6]-=t3;
    ans+=(c[1]+c[2]+c[3]+c[4]+c[5]+c[6])*2/3;
    printf("%d",ans);
    return 0;
}
