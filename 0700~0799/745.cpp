#include <stdio.h>
int a[110],b[110],D[110][110],H[110][110],T[110][110],n;
void seek(int i,int j){
    if(i>=j)return;
    if(T[i][j]==-1){
        b[i]=j,b[j]=i;
        seek(i+1,j-1);
    }
    else{
        seek(i,T[i][j]);
        seek(T[i][j]+1,j);
    }
}
int main(){
    int i,j,k,l;
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%1d",a+i);
    for(i=1;i<=n;++i)for(j=1;j<=n;++j)D[i][j]=-1;
    for(i=1;i<n;++i)if(a[i]!=a[i+1])D[i][i+1]=3,H[i][i+1]=1,T[i][i+1]=-1;
    for(i=3;i<n;i+=2){
        for(j=1;i+j<=n;++j){
            k=i+j;
            if(a[j]!=a[k]){
                if(D[j+1][k-1]==-1)continue;
                H[j][k]=H[j+1][k-1]+1;
                D[j][k]=D[j+1][k-1]+H[j][k]*2+k-j;
                T[j][k]=-1;
            }
            for(l=j+1;l<k;++l){
                if(D[j][l]==-1||D[l+1][k]==-1)continue;
                if(D[j][k]==-1||D[j][k]>D[j][l]+D[l+1][k]){
                    D[j][k]=D[j][l]+D[l+1][k];
                    if(H[j][l]>H[l+1][k])H[j][k]=H[j][l];
                    else H[j][k]=H[l+1][k];
                    T[j][k]=l;
                }
            }
        }
    }
    printf("%d\n",D[1][n]);
    seek(1,n);
    for(i=1;i<=n;++i)if(i<b[i])printf("%d %d\n",i,b[i]);
    return 0;
}
