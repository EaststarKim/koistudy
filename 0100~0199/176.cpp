#include <stdio.h>
#include <string.h>
char a[210],b[210];
int bn,cn;
long long c[210],t;
void cal(int flag){
    int i,j;
    if(flag){
        for(i=bn;i>0;--i)if(b[i]=='(')break;
        j=bn-i;
        for(++i;i<=bn;++i){
            if(b[i]=='+')c[cn-j]+=c[cn-bn+i];
            else c[cn-j]-=c[cn-bn+i];
        }
        bn-=j+1;
        cn-=j;
    }
    if(b[bn]=='*')c[cn-1]*=c[cn];
    else if(b[bn]=='/') c[cn-1]/=c[cn];
    else return;
    --bn,--cn;
}
int main(){
    int i,n;
    scanf("%s",a);
    n=strlen(a);
    for(i=0;i<n;++i){
        if(47<a[i]&&a[i]<58)t=t*10+a[i]-48;
        else{
            if(t){
                c[++cn]=t,t=0;
                cal(0);
            }
            if(a[i]==')')cal(1);
            else b[++bn]=a[i];
        }
    }
    if(t)c[++cn]=t,cal(0);
    cal(1);
    printf("%lld",c[1]);
    return 0;
}
