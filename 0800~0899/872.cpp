#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int a[1010],m1,m2,mx1,mn1=1e3,mx2,mn2=1e3;
int main(){
    int i,n,k;
    scanf("%d",&n);
    for(;n--;)scanf("%d",&k),++a[k];
    for(i=1;i<1001;++i){
        if(m1<a[i])m2=m1,m1=a[i];
        else if(m2<a[i])m2=a[i];
    }
    for(i=1;i<1001;++i)if(a[i]==m1)mx1=max(mx1,i),mn1=min(mn1,i);
    for(i=1;i<1001;++i)if(a[i]==m2)mx2=max(mx2,i),mn2=min(mn2,i);
    printf("%d",max(abs(mx1-mn2),abs(mx2-mn1)));
    return 0;
}
