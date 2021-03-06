#include <bits/stdc++.h>

using namespace std;

#define MAXN 205
#define MOD 1000000007

int parent[MAXN],A[MAXN];

void init()
{
    for(int i=0;i<MAXN;++i)
        parent[i] = -1;
}

int find(int i)
{
    if(parent[i]==-1)
        return i;
    else
        return parent[i] = find(parent[i]);
}

void merge(int x,int y)
{
    x = find(x);
    y = find(y);

    if(x!=y)
    {
        if(A[x]>A[y])
            parent[y] = x;
        else
            parent[x] = y;
    }
}


int main()
{
    int t,n;
    scanf("%d",&t);

    while(t--)
    {
        init();
        scanf("%d",&n);

        for(int i=0;i<n;++i)
        {
            scanf("%d",A+i);
        }

        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                if(__gcd(A[i],A[j])>1)
                    merge(i,j);
            }
        }

        long long result = 1;

        for(int i=0;i<n;++i)
        {
            if(parent[i]==-1)
            {
                result *= A[i];
                result %= MOD;
            }
        }

        printf("%lld\n",result);
    }

    return 0;
}



