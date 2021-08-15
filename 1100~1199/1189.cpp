#include <stdio.h>
#include <string.h>
int a[110][110],chk[110][110],t[10],n,m;
int q[10010][2],x[]={-1,0,1,0},y[]={0,1,0,-1};
int seek(){
    int i,f=0,r=1,nr,nc;
    memset(chk,0,sizeof chk);
    for(i=1;i<=m;++i)if(t[a[1][i]])chk[q[r][0]=1][q[r++][1]=i]=1;
    while(f<r){
        ++f;
        if(q[f][0]==n)return 1;
        for(i=0;i<4;++i){
            nr=q[f][0]+x[i],nc=q[f][1]+y[i];
            if(nr<1||nr>n||nc<1||nc>m||chk[nr][nc]||!t[a[nr][nc]])continue;
            chk[q[r][0]=nr][q[r++][1]=nc]=1;
        }
    }
    return 0;
}
int main(){
    int i,j,k;
    scanf("%d%d",&m,&n);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j)scanf("%d",a[i]+j);
    }
    for(i=0;i<10;++i){
        t[i]=1;
        for(j=i;j<10;++j){
            t[j]=1;
            for(k=j;k<10;++k){
                t[k]=1;
                if(seek()){
                    printf("%d %d %d",i,j,k);
                    return 0;
                }
                t[k]=0;
            }
            t[j]=0;
        }
        t[i]=0;
    }
    printf("-1 -1 -1");
    return 0;
}
