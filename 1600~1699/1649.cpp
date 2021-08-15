#include <stdio.h>
#include <string.h>
char a[110],b[110];
int x[10],y[10];
int main(){
    int i,j,n,m;
    scanf("%s %s",a+1,b+1);
    n=strlen(a+1);
    m=strlen(b+1);
    for(i=1;i<=n;++i)a[i]-=48;
    for(i=1;i<=m;++i)b[i]-=48;
    for(i=1;i<=n;++i)++x[a[i]];
    for(i=1;i<=m;++i)++y[b[i]];
    for(i=0;i<10;++i)if((x[i]&&!y[i])||(!x[i]&&y[i]))break;
    if(i>9){
        puts("GSHS Friends");
        return 0;
    }
    for(i=1;i<n;++i){
        if(((i>1&&a[i])||(i<2&&a[i]>1))&&a[i+1]<9){
            --x[a[i]],--x[a[i+1]],++x[a[i]-1],++x[a[i+1]+1];
            for(j=0;j<10;++j)if((x[j]&&!y[j])||(!x[j]&&y[j]))break;
            if(j>9){
                puts("Almost Friends");
                return 0;
            }
            ++x[a[i]],++x[a[i+1]],--x[a[i]-1],--x[a[i+1]+1];
        }
        if(a[i]<9&&a[i+1]){
            --x[a[i]],--x[a[i+1]],++x[a[i]+1],++x[a[i+1]-1];
            for(j=0;j<10;++j)if((x[j]&&!y[j])||(!x[j]&&y[j]))break;
            if(j>9){
                puts("Almost Friends");
                return 0;
            }
            ++x[a[i]],++x[a[i+1]],--x[a[i]+1],--x[a[i+1]-1];
        }
    }
    for(i=1;i<m;++i){
        if(((i>1&&b[i])||(i<2&&b[i]>1))&&b[i+1]<9){
            --y[b[i]],--y[b[i+1]],++y[b[i]-1],++y[b[i+1]+1];
            for(j=0;j<10;++j)if((x[j]&&!y[j])||(!x[j]&&y[j]))break;
            if(j>9){
                puts("Almost Friends");
                return 0;
            }
            ++y[b[i]],++y[b[i+1]],--y[b[i]-1],--y[b[i+1]+1];
        }
        if(b[i]<9&&b[i+1]){
            --y[b[i]],--y[b[i+1]],++y[b[i]+1],++y[b[i+1]-1];
            for(j=0;j<10;++j)if((x[j]&&!y[j])||(!x[j]&&y[j]))break;
            if(j>9){
                puts("Almost Friends");
                return 0;
            }
            ++y[b[i]],++y[b[i+1]],--y[b[i]+1],--y[b[i+1]-1];
        }
    }
    puts("Nothing");
    return 0;
}
