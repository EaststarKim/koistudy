#include <stdio.h>
char a[10][10],b[10][10],c[10][10],t[10][10],n;
int cmp(char a[10][10],char b[10][10]){
    int i,j;
    for(i=0;i<n;++i)for(j=0;j<n;++j)if(a[i][j]!=b[i][j])return 0;
    return 1;
}
void turn(char a[10][10]){
    int i,j;
    for(i=0;i<n;++i)for(j=0;j<n;++j)t[j][n-i-1]=a[i][j];
    for(i=0;i<n;++i)for(j=0;j<n;++j)a[i][j]=t[i][j];
}
int f(){
    int i,j;
    for(i=0;i<n;++i)scanf("%s",a[i]);
    for(i=0;i<n;++i)scanf("%s",b[i]);
    for(i=0;i<n;++i)for(j=0;j<n;++j)c[i][j]=a[i][n-j-1];
    for(i=1;i<4;++i){
        turn(a);
        if(cmp(a,b))return i;
    }
    if(cmp(c,b))return 4;
    for(i=1;i<4;++i){
        turn(c);
        if(cmp(c,b))return 5;
    }
    if(cmp(a,b))return 6;
    return 7;
}
int main(){
    scanf("%d",&n);
    printf("%d",f());
    return 0;
}
