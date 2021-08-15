#include <stdio.h>
int s[21][21]={{1}};
int f(int n,int k){
    if(k<0||n<k)return 0;
    if(s[n][k])return s[n][k];
    return s[n][k]=(s[n][k]+k*f(n-1,k)+f(n-1,k-1));
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    printf("%d",f(n,k));
    return 0;
}
