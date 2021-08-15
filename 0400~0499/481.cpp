#include <stdio.h>
#include <stdlib.h>
struct data{
    int l,a,x,y;
}a[50];
double cos2[]={1,0.75,0.25,0,0.25,0.75},s,t;
int main(){
    int i,j,k,l,n,r,chk;
    scanf("%d%d",&l,&n);
    for(i=0;i<n;++i)scanf("%d%d%d%d",&a[i].l,&a[i].a,&a[i].x,&a[i].y);
    for(i=0;i<l;++i){
        for(j=0;j<l;++j){
            r=chk=0,t=1e5;
            for(k=0;k<n;++k)if(a[k].x<=i&&i<a[k].x+a[k].l&&a[k].y<=j&&j<a[k].y+a[k].l){
                if(chk)t*=cos2[abs(r-a[k].a)/30];
                else t/=2;
                r=a[k].a,chk=1;
            }
            s+=t;
        }
    }
    printf("%d",(int)s/l/l);
    return 0;
}
