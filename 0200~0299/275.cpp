#include <stdio.h>
int a[]={0,1,3,6,7,7,8,10,13,14},b[]={0,0,0,0,1,2,3,4,5,5};
int main()
{
    int n,t;
    scanf("%d",&n);
    t=n/10*14+a[n%10];
    if(t)printf("I %d\n",t);
    t=n/10*5+b[n%10];
    if(t)printf("V %d\n",t);
    t=n/100*150+(n>9&&n%10? 1:0)+(n%100/10? a[n%100/10-1]*10+n%100/10-1+(a[n%100/10]-a[n%100/10-1])*(n%10+1)+(n%10==9? 1:0):0)+(n>8&&n<100? 1:0);
    if(t)printf("X %d\n",t);
    t=n/100*50+(n%100/10>3? b[n%100/10]*10+(n%100/10<9? n%10-9:0):0);
    if(t)printf("L %d\n",t);
    t=n/1000*1500+(n>99&&n%100? 10:0)+(n%1000/100? a[n%1000/100-1]*100+(n%1000/100-1)*10+(a[n%1000/100]-a[n%1000/100-1])*(n%100+1)+(n%100/10==9? 1:0)*(n%10+1):0)+(n>89&&n<1000? (n>98? 10:n-89):0);
    if(t)printf("C %d\n",t);
    t=n/1000*500+(n%1000/100>3? b[n%1000/100]*100+(n%1000/100<9? n%100-99:0):0);
    if(t)printf("D %d\n",t);
    t=(n/1000? a[n/1000-1]*1000+(n/1000-1)*100+(a[n/1000]-a[n/1000-1])*(n%1000+1)+(n%1000/100==9? 1:0)*(n%100+1):0)+(n>899? (n>998? 100:n-899):0);
    if(t)printf("M %d\n",t);
    return 0;
}
