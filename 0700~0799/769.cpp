#include <stdio.h>
int a[21],b[21],ans=200,cnt;
int main()
{
    int i,j;
    for(i=0;i<20;++i)scanf("%d",a+i);
    for(i=0;i<10;++i){
        for(j=0;j<20;++j)b[j]=a[j];
        b[0]+=i;
        b[1]+=cnt=i;
        for(j=0;j<19;++j)b[j+1]+=(30-b[j])%10,b[j+2]+=(30-b[j])%10,cnt+=(30-b[j])%10;
        if(!(b[19]%10)&&ans>cnt)ans=cnt;
    }
    if(ans==200)ans=-1;
    printf("%d",ans);
    return 0;
}
