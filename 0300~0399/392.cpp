#include <stdio.h>

#include <queue>

using namespace std;

class data

{

    public:

    int fr,to,d;

    bool operator < (const data& p) const

    {

        return d > p.d;

    }

};

priority_queue<data> Q;

int v[55][55];

int ans[55];

int dis[55];

int main()

{

    int n,i,j;

    scanf("%d",&n);

    for(i=0;i<n;i++)

    for(j=0;j<n;j++)

        scanf("%1d",&v[i][j]);

    data tmp;

    tmp.fr = 0;
    tmp.to = 0;

    tmp.d = 0;

    Q.push(tmp); 
    while(!Q.empty())

    {

        tmp = Q.top(); Q.pop();

        if(dis[tmp.to] == 0) 

        {

            dis[tmp.to] = tmp.d; 

            ans[tmp.to]++;

        }

        else if(dis[tmp.to]==tmp.d) 

        {

            ans[tmp.to]++; 

            continue; 

        }

        else continue; 

        int k = tmp.to;

        int tp = tmp.d;

        tmp.fr = tmp.to;

        for(i=0;i<n;i++)

        {

            if(v[k][i] !=0) 

            {

                tmp.to = i;

                tmp.d = tp+v[k][i]; 

                v[k][i] = 0;

                v[i][k] = 0;

                Q.push(tmp);

            }

        }

    }

    long long int answer = 1;

    for(i=0;i<n;i++)

    {

        answer = answer * ans[i];

        answer %= 1000000007;

    }

    printf("%lld",answer);

    return 0;

}

