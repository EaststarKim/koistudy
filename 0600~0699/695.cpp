#include <stdio.h>

#include <malloc.h>

struct data

{

    int loc,leng;

};

int max;

data ans[3005][3005];

int size[3005];

int main()

{

    int n,m,i,j,cnt;

    char str[3005];

    data tmp,p;

    scanf("%d %d",&n,&m);

    int flag;

    for(i=0;i<n;i++)

    {

        cnt = 0;

        scanf("%s",str);

        for(j=0;j<m;j++)

        {

            if(str[j]=='0')

                cnt=0;

            else cnt++;

            flag = i;

            while(size[j]!=0)

            {

                if(ans[j][size[j]-1].leng >cnt)

                {

					p = ans[j][size[j]-1];

					if((i-p.loc)*p.leng>max)

						max = (i-p.loc)*p.leng;

                    flag = ans[j][size[j]-1].loc;

                    size[j]--;

                }

                else break;

            }

            tmp.loc = flag; tmp.leng = cnt;

            ans[j][size[j]++] = tmp;

        }

    }

    for(j=0;j<m;j++)

    {

        while(size[j]!=0)

        {

			p = ans[j][size[j]-1];

            if((n-p.loc)*p.leng>max)

				max = (n-p.loc)*p.leng;

            size[j]--;

        }

    }

    printf("%d",max);

    return 0;

}

