#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int a[40][40],s1[40],s2[40],n,s,mx,T;
void R(){
    int i,j;
    for(i=1;i<=n;i++){
        if(rand()&1){
            for(j=1;j<=n;j++){
                s1[i]=-s1[i];
                for(j=1;j<=n;j++)a[i][j]=-a[i][j],s2[j]+=a[i][j]*2,s+=a[i][j]*2;
            }
        }
    }
    for(j=1;j<=n;j++){
        if(rand()&1){
            for(i=1;i<=n;i++){
                s2[j]=-s2[j];
                for(i=1;i<=n;i++)a[i][j]=-a[i][j],s1[i]+=a[i][j]*2,s+=a[i][j]*2;
            }
        }
    }
}
int main(){
    T=clock();
    srand(time(NULL));
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%1d",&a[i][j]);
            if(!a[i][j]) a[i][j]=-1;
            s1[i]+=a[i][j];
            s2[j]+=a[i][j];
            s+=a[i][j];
        }
    }
    mx=s;
    for(;;){
        for(i=1;i<=n;i++)if(s1[i]<0)break;
        if(i!=n+1){
            s1[i]=-s1[i];
            for(j=1;j<=n;j++)a[i][j]=-a[i][j],s2[j]+=a[i][j]*2,s+=a[i][j]*2;
        }
        else {
            for(j=1;j<=n;j++)if(s2[j]<0)break;
            if(j!=n+1){
                s2[j]=-s2[j];
                for(i=1;i<=n;i++) a[i][j]=-a[i][j], s1[i]+=a[i][j]*2, s+=a[i][j]*2;
            }
            else R();
        }
        if(s>mx)mx=s;
        if(clock()-T>0)break;
    }
    printf("%d",mx+(n*n-mx)/2);
    return 0;
}
