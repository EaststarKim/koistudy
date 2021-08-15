#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
struct data{
    int x,t,l;
}a[200010];
bool cmp(data a, data b){
    return a.x<b.x;
}
bool cmpl(data a, data b){
    return a.l<b.l;
}
int lc[100010],l,lt,h;
int main()
{
    int i,j,pt,p,f,ht,hm;
    scanf("%d%d",&p,&f);
    for(i=1;i<=p;++i){
        scanf("%d",&a[i].x);
        a[i].t=1;
    }
    for(i=p+1;i<=p+f;++i){
        scanf("%d",&a[i].x);
        a[i].t=2;
    }
    sort(a+1,a+p+f+1,cmp);
    for(i=1;i<=p+f;++i){
        if(a[i].t==a[i-1].t){
            if(a[i].t==1){
                ++lt;
                if(lt>l)l=lt;
            }
            else --lt;
        }
    }
    for(i=1,lt=0;i<=p+f;++i){
        if(a[i].t==a[i-1].t){
            if(a[i].t==1)--lt;
            else ++lt;
        }
        a[i].l=lt+l;
        ++lc[lt+l];
    }
    sort(a+1,a+p+f+1,cmpl);
    for(i=0,pt=0;lc[i]>=1;++i){
        sort(a+1+pt,a+1+pt+lc[i],cmp);
        ht=0;
        for(j=1;j<=lc[i]/2;++j)ht+=a[pt+j*2].x-a[pt+j*2-1].x;
        if(lc[i]%2){
            hm=ht;
            for(j=lc[i]/2;j>=1;--j){
                ht-=a[pt+j*2].x-a[pt+j*2-1].x;
                ht+=a[pt+j*2+1].x-a[pt+j*2].x;
                if(ht<hm)hm=ht;
            }
            h+=hm;
        }
        else h+=ht;
        pt+=lc[i];
    }
    printf("%d",h);
    return 0;
}
