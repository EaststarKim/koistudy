#include <stdio.h>
int main()
{
    int qr,qc,rr,rc,r,c,qa,ra;
    scanf("%d%d%d%d%d%d",&qr,&qc,&rr,&rc,&r,&c);
    if(qr==r&&qc==c)qa=0;
    else if((qr-r==qc-c)||qr==r||qc==c)qa=1;
    else qa=2;
    if(rr==r&&rc==c)ra=0;
    else if(rr==r||rc==c)ra=1;
    else ra=2;
    printf("%d\n%d",qa,ra);
    return 0;
}
