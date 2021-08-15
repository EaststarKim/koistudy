#include<stdio.h>
#include<string.h>
int d[105][105];
int main()
{
    int n,i,j,l,len,k,m;
    int div=1000000007;
    scanf("%d",&n);
    for(l=1;l<=n;l++)
	{
        int a[105];
        char s[105];
        for(i=0;i<=101;i++)
		{
			for(j=0;j<=101;j++)d[i][j]=0;
		}
        d[0][0]=1;
        scanf("%d",&k);scanf("%s",s+1);
        for(i=1;i<=strlen(s);i++)a[i]=s[i]-'0';
        len=strlen(s)-1;
        for(i=1;i<=len;i++)
		{
            for(j=1;j<=i;j++)
			{
                int t=0;
                for(m=j;m<=i;m++)t=((t*10)+a[m])%k;
                for(m=0;m<k;m++)
				{
                    int temp=m+t;
                    if(temp>=k)temp-=k;
                    d[i][temp]+=d[j-1][m];
                    if(d[i][temp]>div)d[i][temp]%=div;
                    if(j==1)continue;
                    temp=m-t;
                    if(temp<0)temp+=k;
                    d[i][temp]+=d[j-1][m];
                    if(d[i][temp]>div)d[i][temp]%=div;
                }
            }
        }
        printf("%d\n",d[len][0]);
    }
	return 0;
}