#include <stdio.h>
char a[20],b[20];
char d[10]="IVXLCDM";
int di[10]={1,5,10,50,100,500,1000},c[7];
int p(char x){
    int i;
    for(i=0;i<=6;++i)if(d[i]==x)break;
    return i;
}
int f(char x[]){
    int i,s=0;
    for(i=0;x[i];++i);
    while(i){
        i--;
        if(!i)return s+di[p(x[i])];
        else if(p(x[i-1])>=p(x[i]))s+=di[p(x[i])];
        else s+=di[p(x[i])]-di[p(x[i-1])],--i;
    }
    return s;
}
void g(int k){
    int i,j;
    for(i=6;i>=0;--i)while(k>=di[i])++c[i],k=k-di[i];
    for(i=1;i<=c[6];++i)printf("M");
    for(i=5;i>=1;i-=2){
        if(c[i-1]==4&&c[i]==1)printf("%c%c",d[i-1],d[i+1]);
        else if(c[i-1]==4&&c[i]==0)printf("%c%c",d[i-1],d[i]);
        else{
            if(c[i]==1)printf("%c",d[i]);
            for(j=1;j<=c[i-1];++j)printf("%c",d[i-1]);
        }
    }
}
int main(){
    scanf("%s\n%s",a,b);
    printf("%d\n",f(a)+f(b));
    g(f(a)+f(b));
    return 0;
}
