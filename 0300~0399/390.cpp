#include <stdio.h>
int a[1000010],t[1000010],n,ans;
void f(int x,int y,int cnt){
    int i;
    while(cnt<=ans){
        if(x==1&&y==1){
            if(ans==cnt){
                for(i=cnt;i;--i){
                    if(a[i]<t[i])return;
                    if(a[i]>t[i])break;
                }
            }
            ans=cnt;
            for(i=1;i<=cnt;++i)a[i]=t[i];
            return;
        }
        if(x>y)t[++cnt]=0,x-=y;
        else if(x<y)t[++cnt]=1,y-=x;
        else return;
    }
}
int main(){
    int i;
    scanf("%d",&n);
    if(n<2){
        puts("0");
        return 0;
    }
    ans=n;
    for(i=1;i<n;++i)f(i,n-i,1);
    printf("%d\n",ans);
    for(i=ans;i;--i)printf("%c",a[i]+'X');
    return 0;
}
