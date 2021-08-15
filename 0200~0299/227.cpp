#include <stdio.h>   
int main()   
{   
    int d,h,s;   
    scanf("%d%d",&d,&h);   
    if(d>119)   
    {   
        s=(h-1)*55000+(d+9)/10*1000+5000;   
        if(h==1)s+=20000;   
        else if(h>15)   
        {   
            s+=150000;   
            if(h>30)   
            {   
                s+=135000;   
                if(h>60)s+=240000+(h-60)*7000;   
                else s+=(h-30)*8000;   
            }   
            else s+=(h-15)*9000;   
        }   
        else s+=h*10000;   
    }   
    else s=((d+9)/10*1000+25000)*h;   
    printf("%d",s);   
    return 0;   
}  