#include <bits/stdc++.h>
using namespace std;
int n;
int b[10];
void dfs(int st,int a)
{
    if(st == n)
    {
        if(a) return ;
        for(int i = 1; i<=n; i++)
        {
            if(i!=1) printf(" ");
            printf("%d",b[i]);
        }
        puts();
        return  ;
    }
    for(int i = 1; i<=n; i++)
    {
        b[st+1] = i;
        dfs(st+1,a^i);
    }

}
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i = 1; i<=n; i++)
        {
            b[1] = i;
            dfs(1,i);
        }
    }
    return 0;
}
