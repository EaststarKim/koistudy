#include <stdio.h>
char c[1000001];
int n,l;
bool f(int p){
    int I,K,O,i,t;
    I=K=O=t=0;
    for(i=n;i>0&&K<p;--i){
        if(c[i]=='I'&&t<p)++I,++t;
        else if(c[i]=='O'&&I>0)--I,++O;
        else if((c[i]=='K'||c[i]=='I')&&O>0)--O,++K;
    }
    return K==p;
}
int main()
{
    int r,m;
    scanf("%d",&n);
    scanf("%s",c+1);
    r=n/3;
    while(l<=r){
        m=(l+r)/2;
        if(f(m))l=m+1;
        else r=m-1;
    }
    printf("%d",r);
    return 0;
}
