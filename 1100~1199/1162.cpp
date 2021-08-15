#include <stdio.h>
#include <string.h>
int chk[60],n,k;
char a[60],b[60];
void trav(int p){
    int i;
    chk[p]=1;
    for(i=p-1;i>=0&&!chk[i];--i)if(a[i]==b[k+1])break;
    if(i>=0&&!chk[i])++k,trav(i);
    for(i=p+1;i<n&&!chk[i];++i)if(a[i]==b[k+1])break;
    if(i<n&&!chk[i])++k,trav(i);
    printf("%c",a[p]);
}
int main(){
    int i;
    scanf("%s\n%s",a,b);
    n=strlen(a);
    for(i=0;i<n;++i)if(a[i]==b[0])break;
    trav(i);
    return 0;
}
