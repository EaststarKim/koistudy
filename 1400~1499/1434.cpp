#include <stdio.h>
int a[3010][3010],t[3010][3010],ans;
int main(){
    int i,j,h,w,r,c,lp,rp,mid,s,flag;
    scanf("%d%d%d%d",&h,&w,&r,&c);
    for(i=1;i<=h;++i){
        for(j=1;j<=w;++j)scanf("%d",a[i]+j);
    }
    lp=1,rp=h*w;
    while(lp<=rp){
        mid=(lp+rp)/2;
        for(i=1;i<=h;++i){
            for(j=1;j<=w;++j)t[i][j]=(a[i][j]>mid?1:(a[i][j]<mid?-1:0))+t[i-1][j]+t[i][j-1]-t[i-1][j-1];
        }
        flag=0;
        for(i=r;i<=h;++i){
            for(j=c;j<=w;++j){
                s=t[i][j]-t[i-r][j]-t[i][j-c]+t[i-r][j-c];
                if(s<=0)flag=1;
                if(!s){
                    ans=mid;
                    break;
                }
            }
            if(j<=w)break;
        }
        if(flag)rp=mid-1;
        else lp=mid+1;
    }
    printf("%d",ans);
    return 0;
}
