#include <stdio.h>   
int x[10005], leng[10005],dir[10005];   
int main()   
{   
    int l,n,i,right=-1,left=-1,right_index=0,left_index=0,tmp=0;   
    double cnt,max;   
    scanf("%d %d",&l,&n);   
    for(i=0;i<n;i++)   
    {   
        scanf("%d %d %d",x+i,leng+i,dir+i);   
        if(dir[i] == 1)   
        {   
            if(right==-1)   
            {   
                right = i;   
                left_index=0;   
            }   
            tmp++;   
        }   
        else  
        {   
            right_index+=tmp;   
            tmp = 0;   
            left_index++;   
            left = i;   
        }   
    }   
    cnt = leng[right]/2.0;   
    for(i=1;i<=left_index;i++)   
    {   
        cnt+=leng[right+i];   
    }   
    cnt-=leng[right+left_index]/2.0;   
    max = l-x[right]-cnt;   
    cnt = leng[left]/2.0;   
    for(i=1;i<=right_index;i++)   
    {   
        cnt+=leng[left-i];   
    }   
    cnt-=leng[left-right_index]/2.0;   
  
    if(max < x[left]-cnt)   
        max = x[left]-cnt;   
  
    if(max - (int)max==0) printf("%.0lf",max);   
    else printf("%.1lf",max);   
    return 0;   
}