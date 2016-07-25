#include <bits/stdc++.h>

using namespace std;

int f[17];

int Sg[1100];

bool vis[1100];

void GetF(){
    f[1] = 1; f[2] = 2;
    for(int i = 3;i<=16;i++) f[i] = f[i-1] +f[i-2];
}

int GetSg(int s)
{
    memset(vis,false,sizeof(vis));

    for(int i = 1;f[i]<=s;i++)
    {
        vis[Sg[s-f[i]]] = true;
    }

    for(int i = 0;i<=s;i++)
    {
        if(!vis[i])
        {
            return i;
        }
    }
}

int main()
{
    GetF();

    Sg[0] = 0;

    for(int i  = 1;i<=1000;i++)
        Sg[i] = GetSg(i);
    int n,m,p;

    while(~scanf("%d %d %d",&n,&m,&p) &&(n+m+p))
    {
        printf("%s\n",(Sg[n]^Sg[m]^Sg[p]) == 0?"Nacci":"Fibo");
    }

    return 0;
}
