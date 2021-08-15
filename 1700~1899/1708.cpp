#include <stdio.h>
char a[5];
int dq[2][2000010],f[2],r[2],cnt,t;
int main(){
    int i,n,x;
    scanf("%d",&n);
    f[0]=f[1]=1e6;
    r[0]=r[1]=1e6-1;
    for(;n--;){
        scanf("%s",a);
        if(a[0]=='a'){
            scanf("%d",&x);
            dq[!t][++r[!t]]=x;
            if(cnt%2)dq[t][++r[t]]=dq[!t][f[!t]++];
            ++cnt;
        }
        if(a[0]=='t'){
            --r[!t];
            --cnt;
            if(cnt%2)dq[!t][--f[!t]]=dq[t][r[t]--];
        }
        if(a[0]=='m'){
            t=!t;
            if(cnt%2)dq[!t][--f[!t]]=dq[t][r[t]--];
        }
    }
    printf("%d\n",cnt);
    for(i=f[t];i<=r[t];++i)printf("%d ",dq[t][i]);
    for(i=f[!t];i<=r[!t];++i)printf("%d ",dq[!t][i]);
    return 0;
}
