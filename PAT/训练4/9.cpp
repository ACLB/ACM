
#include <bits/stdc++.h>

using namespace std;

map<string,int>M;

map<int,string>MS;

set<int>S[41100];

string s;

int main()
{
    int n,m;

    cin>>n>>m;

    int u,v;

    int num = 1;

    for(int i = 0;i<m;i++)
    {
        cin>>u>>v;

        for(int j = 0;j<v;j++)
        {
            cin>>s;

            if(!M[s])
            {
                M[s] = num++;
            }

            S[M[s]].insert(u);

            MS[M[s]] = s;
        }
    }

    for(int i = 1;i<=n;i++)
    {
        cin>>s;

        u = M[s];

        cout<<s<<" "<<S[u].size();

        if(S[u].size() == 0) continue;

        for(set<int>::iterator it = S[u].begin(); it != S[u].end();it++)
        {
            cout<<" "<<*it;
        }

        cout<<endl;

    }
    return 0;
}
