#include <bits/stdc++.h>

using namespace std;

set<int>S[500000];

int Getnum(string s)
{
    int ans = 0;
    for(int i = 0;i<3;i++)
    {
        ans = ans*26+s[i]-'A';
    }

    return ans*10+s[3]-'0';
}

char s[10];

int main()
{
    int n,m;

    scanf("%d %d",&n,&m);

    int u,v;


    for(int i = 0;i<m;i++)
    {
        scanf("%d %d",&u,&v);

        for(int j = 0;j<v;j++)
        {
            scanf("%s",s);

            int num = Getnum(s);

            S[num].insert(u);
        }
    }

    for(int i = 1;i<=n;i++)
    {
        scanf("%s",s);
        
        u = Getnum(s);

        printf("%s %d",s,S[u].size());

        if(S[u].size() == 0) continue;

        for(set<int>::iterator it = S[u].begin(); it != S[u].end();it++)
        {
            printf(" %d",*it);
        }

        cout<<endl;

    }
    return 0;
}

