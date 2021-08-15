#include <stdio.h>

#include <algorithm>

using namespace std;

class bus

{

    public:

    int fr,bk;

    bool operator < (const bus& p) const

    {

        return bk < p.bk; 

    }

}a[200005];

class data

{

    public:

    int num,ind;

    bool chk;

    bool operator < (const data& p) const

    {

        return num < p.num; 

    }

}b[300005];

int in_cnt;

long long int tree[600005]; 

int k;

long long int d = 1000000007; 

void add(int r,long long int val)

{

    tree[r] = (tree[r] + val)%d;

    r>>=1;

    while(r!=0)

    {

        tree[r] = (tree[r*2] + tree[r*2+1])%d;

        r>>=1;

    }

    return;

}

long long int sum(int fr, int bk)

{

    long long int cnt=0;

    while(fr <= bk)

    {

        if(fr==bk)

        {

            cnt = (cnt+tree[fr])%d;

            break;

        }

        if(fr&1) cnt = (cnt+ tree[fr++])%d;

        if(!(bk&1)) cnt = (cnt+tree[bk--])%d;

        fr>>=1; bk>>=1;

    }

    return cnt;

}

int main()

{

    int n,m,i;

    scanf("%d %d",&n,&m);

    for(i=0;i<m;i++)

    {

        scanf("%d %d",&a[i].fr,&a[i].bk);

        b[2*i].num = a[i].fr; b[2*i].ind = i; b[2*i].chk = 0;

        b[2*i+1].num = a[i].bk; b[2*i+1].ind = i; b[2*i+1].chk = 1;

    }

    sort(b,b+2*m); 

    int tmp = 0;

    in_cnt = 1;

    for(i=0;i<2*m;i++) 
    {

        if(tmp!= b[i].num)

        {

            tmp = b[i].num;

            in_cnt++;

        }

        if(b[i].chk==0) a[b[i].ind].fr = in_cnt-1;

        else a[b[i].ind].bk = in_cnt-1;

    }

    if(tmp!=n)

    {

        printf("0"); 

        return 0;

    }

    n = in_cnt;

    for(k=1;k<n;k<<=1);

    add(k,1);

    sort(a,a+m);

    for(i=0;i<m;i++)

    {

        add(k+a[i].bk,sum(k+a[i].fr,k+a[i].bk-1)); 

    }

    if(in_cnt==1) printf("0");

    printf("%lld",tree[k+in_cnt-1]);

    return 0;

}

