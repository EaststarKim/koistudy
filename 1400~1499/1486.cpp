#include <stdio.h>
char a[4010][4010],b;
int chk[4010][4010],q[16000010][2],n,m,t,flag,f,r,pf,pr;
int x[]={-1,0,1,0},y[]={0,1,0,-1};
void g(){
    int i,ro,co,nr,nc;
    while(f<r){
        ro=q[++f][0],co=q[f][1];
        for(i=0;i<4;++i){
            nr=ro+x[i],nc=co+y[i];
            if(a[nr][nc]!=b||chk[nr][nc])continue;
            flag=1;
            chk[nr][nc]=1;
            q[++r][0]=nr,q[r][1]=nc;
        }
    }
    pf=pr,pr=r;
}
int main(){
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)scanf("%s",a[i]+1);
    if(a[1][1]=='.'){
        puts("0");
        return 0;
    }
    ++t,b=a[1][1];
    q[1][0]=q[1][1]=chk[1][1]=1;
    f=0,r=1;
    g();
    for(;;){
        ++t,flag=0;
        b=(b=='F'?'R':'F');
        f=pf,r=pr;
        g();
        if(!flag)break;
    }
    printf("%d",t-1);
    return 0;
}
