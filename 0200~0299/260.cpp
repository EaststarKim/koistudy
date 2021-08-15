#include <stdio.h>
#include <string.h>
#include <string>
char a[20010],b[20010],c[81],ans[20010];
int an,bn,mp,mq,mx,t,n;
void seek(int p,int q){
    int i=p,j=q;
    while(p>=0&&q<bn&&b[p]==b[q])i=p--,j=q++;
    if(i==p&&j==q)i=j=0;
    if(mx<j-i+1)mx=j-i+1,mp=i+1,mq=j+1;
}
int main(){
    int i,m;
    while(fgets(c,sizeof c,stdin)){
        m=strlen(c);
        if(c[m-1]=='\n')--m;
        for(i=0;i<m;++i){
            a[an++]=c[i];
            if(isalpha(c[i]))b[bn++]=tolower(c[i]);
        }
    }
    for(i=1;i<bn-1;++i)seek(i-1,i+1);
    for(i=1;i<bn;++i)seek(i-1,i);
    for(i=0;i<an&&t<mq;++i){
        if(isalpha(a[i]))++t;
        if(mp<=t&&t<=mq)ans[n++]=a[i];
    }
    printf("%d\n%s",mx,ans);
    return 0;
}
