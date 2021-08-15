#include <stdio.h>
#include <algorithm>
using namespace std;
int a[]={0,31,59,90,120,151,181,212,243,273,304,334,365},t,j,cnt;
struct data{
    int s,e;
    bool operator<(const data&r)const{
        return s<r.s;
    }
}f[100010];
int main()
{
    int i,n,m,d,mm,dd,flag,mx;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d%d%d",&m,&d,&mm,&dd);
        f[i].s=a[m-1]+d;
        f[i].e=a[mm-1]+dd;
    }
    sort(f,f+n);
    for(i=0;i<n&&f[i].s<61;i++)t=max(t,f[i].e);
    if(!t)t=335;
    else cnt=1;
    while(t<335){
        flag=mx=0;
        for(;j<n&&f[j].s<=t;j++){
            if(f[j].e>mx){
                mx=f[j].e;
                flag=1;
            }
        }
        if(!flag||t>=mx){
            printf("0");
            return 0;
        }
        else{
            t=mx;
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}
