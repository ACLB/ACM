#include <bits/stdc++.h>

using namespace std;

int  vis[200];

int main()
{
    int n;

    string s;

    cin>>n;


    cin>>s;

    int num = 0;

    for(int i = 0;i<s.size();i++)
    {
        if(!vis[s[i]]) num++;
        vis[s[i]]++;
    }

    int ans = s.size();

    int ant = 0;

    int l = 0;

    memset(vis,0,sizeof(vis));

    for(int i =0 ;i<s.size();i++)
    {
        if(!vis[s[i]]) ant++;

        vis[s[i]] ++;
        if(ant == num)
        {
            while(l<s.size() && ant == num)
            {

                ans = min(i-l+1,ans);

                vis[s[l]] --;


                if(!vis[s[l]]) ant--;

                l++;
            }
        }
    }

    cout<<ans<<endl;


    return 0;
}
