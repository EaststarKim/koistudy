#include <stdio.h>
#include <string.h>
struct data{
    char name[110];
    int age,height;
}a[1010];
int main(){
    int i,n,q,x,y,t,flag;
    char w[110];
    scanf("%d",&n);
    for(i=1;i<=n;++i)scanf("%s%d%d",a[i].name,&a[i].age,&a[i].height);
    scanf("%d",&q);
    for(;q--;){
        flag=0;
        scanf("%d%d",&x,&y);
        if(x==1)scanf("%s",w);
        else scanf("%d",&t);
        for(i=1;i<=n;++i)if((x==1&&!strcmp(a[i].name,w))||(x==2&&a[i].age==t)||(x==3&&a[i].height==t)){
            if(y==1)puts(a[i].name);
            else if(y==2)printf("%d\n",a[i].age);
            else printf("%d\n",a[i].height);
            flag=1;
        }
        if(!flag)puts("none");
        puts("");
    }
    return 0;
}
