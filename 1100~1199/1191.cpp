#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int l[20010],r[20010],lD[20010],rD[20010];
int main(){
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%d%d",l+i,r+i);
    lD[1]=r[i]*2-l[i]-1;
    rD[1]=r[i]-1;
    for(i=2;i<=n;++i){
        lD[i]=min(lD[i-1]+abs(r[i]-l[i-1]),rD[i-1]+abs(r[i]-r[i-1]))+r[i]-l[i];
        rD[i]=min(lD[i-1]+abs(l[i]-l[i-1]),rD[i-1]+abs(l[i]-r[i-1]))+r[i]-l[i];
    }
    printf("%d",min(lD[n]+n-l[n],rD[n]+n-r[n])+n-1);
    return 0;
}

