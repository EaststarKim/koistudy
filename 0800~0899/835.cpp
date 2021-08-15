#include <stdio.h>
int a[110],b[110],chk[110],s,n,mn,mx;
void back(int p){
    if(mn>b[p])mn=b[p];
    if(chk[p])return;
    chk[p]=1;
    b[(p+3)%n]=b[p]+a[(p+2)%n]-a[(p+1)%n];
    back((p+3)%n);
    b[p]-=mn-1;
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;++i)scanf("%d",a+i),s+=a[i];
    s/=3;
    for(i=0;i<n;++i)if(!b[i])mn=0,back(i);
    for(i=0;i<n;++i)s-=b[i];
    if(n%3)for(i=0;i<n;++i)b[i]+=s/n;
    else{
        for(i=2;i<n;i+=3)if(mx<b[i])mx=b[i];
        if(mx+s*3/n<101)for(i=2;i<n;i+=3)b[i]+=s*3/n;
        else{
            for(i=2;i<n;i+=3)b[i]+=100-mx;
            s-=(100-mx)*n/3;
            mx=0;
            for(i=1;i<n;i+=3)if(mx<b[i])mx=b[i];
            if(mx+s*3/n<101)for(i=1;i<n;i+=3)b[i]+=s*3/n;
            else for(i=1;i<n;i+=3)b[i]+=100-mx;
            s-=(100-mx)*n/3;
            if(s>0)for(i=0;i<n;i+=3)b[i]+=s*3/n;
        }
    }
    for(i=0;i<n;++i)printf("%d\n",b[i]);
    return 0;
}
