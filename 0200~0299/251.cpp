#include <stdio.h>       
int y=1900,m=1,d=1,N,month[13]= {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};;   
int Sun, Mon, Tues, Wed, Thurs, Fri, Sat;    
char D = 'A';   
int Leapyear()       
{       
    if(y%400==0)return 1;     
    if(y%4==0 && y%100!=0) return 1;       
    return 0;       
}       
void proc()       
{         
    int i,t;      
    for(i=1;;i++)       
    {       
        if(Leapyear())month[2]=29;     
        else month[2]=28;       
        if(d<=13&&d+7>13)       
        {       
            t=13-d;       
            d+=t;       
            D+=t;       
            if(D>'G')D=(D-'G')%7+64;      
            if(D=='A') Mon++;       
            if(D=='B') Tues++;       
            if(D=='C') Wed++;       
            if(D=='D') Thurs++;       
            if(D=='E') Fri++;       
            if(D=='F') Sat++;       
            if(D=='G') Sun++;       
        }   
        d+=7;       
        if(d>month[m])       
        {       
            m++;       
            d-=month[m-1];       
            if(m>12)       
            {       
                m=1;       
                y++;       
            }       
        }       
        if((y==1900+N-1 && m>=12 && d>=31)||y>1900+N-1)break;         
    }      
    printf("%d %d %d %d %d %d %d", Sat, Sun, Mon, Tues, Wed, Thurs, Fri);       
}   
int main()   
{       
    scanf("%d",&N);       
    proc();       
    return 0;       
}  