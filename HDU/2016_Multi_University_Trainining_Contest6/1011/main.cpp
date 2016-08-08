#include <bits/stdc++.h>

using namespace std;

int s,t;

int dfs(int p,int q,int step,int stop)
{
    if(p == q) return step;

    int x  =0;

    while(p-(1 << x) + 1 > q ) x++;

    if(p-(1<<x)+1== q) return step+x;

    int up = q-max(0,p-(1<<x)+1);

    int temp = x+max(0,up-stop);

    return min(step+temp,dfs(p-(1<<(x-1))+1,q,step+x,stop+1));

}

int main()
{
    int T;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d %d",&s,&t);

        if(s<=t) printf("%d\n",t-s);

        else printf("%d\n",dfs(s,t,0,0));
    }
    return 0;
}
