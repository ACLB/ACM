#include <bits/stdc++.h>

using namespace std;

string s[100100];

int a[100100];

int main()
{
    int n;

    ios::sync_with_stdio(false);

    priority_queue<int,vector<int>,greater<int> >Q;

    cin>>n;

    int ans = 0;

    for(int i = 0; i<n; i++)
    {
        cin>>s[i];

        if(s[i]!="removeMin") cin>>a[i];

        if(s[i] == "insert")
        {
            ans++;

            Q.push(a[i]);
        }
        else if(s[i] == "getMin")
        {
            if(!Q.empty() && Q.top() == a[i])
            {
                ans++;

                continue;
            }
            else if(Q.empty() || Q.top()>a[i])
            {
                ans++;

                ans++;

                Q.push(a[i]);
            }
            else
            {
                while(!Q.empty() && Q.top()<a[i])
                {
                    ans++;

                    Q.pop();
                }

                if(Q.empty())
                {
                    ans++;
                    ans++;
                    Q.push(a[i]);
                }
                else
                {
                    if(Q.top() > a[i])
                    {
                        ans++;

                        Q.push(a[i]);
                    }
                    ans++;
                }
            }
        }
        else if(s[i]== "removeMin")
        {
            if(Q.empty())
            {
                ans++;
                ans++;
            }
            else if(!Q.empty())
            {
                ans++;
                Q.pop();
            }
        }
    }

    cout<<ans<<endl;

    while(!Q.empty())
    {
        Q.pop();
    }

    for(int i = 0; i<n; i++)
    {
        if(s[i] == "insert")
        {
            cout<<s[i]<<" "<<a[i]<<endl;

            Q.push(a[i]);
        }
        else if(s[i] == "getMin")
        {
            if(!Q.empty() && Q.top() == a[i])
            {
                cout<<s[i]<<" "<<a[i]<<endl;

                continue;
            }
            else if(Q.empty() || Q.top()>a[i])
            {
                cout<<"insert "<<a[i]<<endl;

                cout<<s[i]<<" "<<a[i]<<endl;

                Q.push(a[i]);
            }
            else
            {
                while(!Q.empty() && Q.top()<a[i])
                {
                    cout<<"removeMin"<<endl;

                    Q.pop();
                }

                if(Q.empty())
                {
                    cout<<"insert "<<a[i]<<endl;

                    cout<<s[i]<<" "<<a[i]<<endl;

                    Q.push(a[i]);
                }
                else
                {
                    if(Q.top() > a[i])
                    {
                        cout<<"insert "<<a[i]<<endl;
                        Q.push(a[i]);
                    }
                    cout<<s[i]<<" "<<a[i]<<endl;
                }
            }
        }
        else if(s[i]== "removeMin")
        {
            if(Q.empty())
            {
                cout<<"insert 0"<<endl;
                cout<<s[i]<<endl;
            }
            else if(!Q.empty())
            {
                cout<<s[i]<<endl;
                Q.pop();
            }
        }
    }
    return 0;
}
