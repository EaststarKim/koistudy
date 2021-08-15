#include <stdio.h>
int a[1000010],s;
int main(){
    int i,j,n;
    scanf("%d",&n);
    a[2]=1;
    for(i=3;i<n-1;i+=2){
        for(j=3;j*j<=i;j+=2)if(i%j==0)break;
        if(j*j>i)a[i]=1;
    }
    if(n%2)s=a[n-2];
    else{
        for(i=3;i<=n/2;i+=2)if(a[i]&&a[n-i])++s;
    }
    printf("%d",s);
    return 0;
}
