clude <stdio.h>
#define M 1000000007
int main(){
    int i,n;
    long long m=1;
    scanf("%d",&n);
    for(i=1;i<=n;++i)m=(m*2*i)%M;
    printf("%d",m);
    return 0;
}
