#include <bits/stdc++.h>

using namespace std;

char a[30],b[30];

vector<pair<int,int> >S;

int main()
{
    scanf("%s",a);

    scanf("%s",b);

    int len = strlen(a);

    stack<char>ST;

    int i = 0, j= 0;

    bool flag = false;

    for(;i<len && j<len;i++)
    {
        if(a[i] == b[j])
        {
            S.push_back(make_pair(1,2));

            j++;
        }
        else
        {
            ST.push(a[i]);

            S.push_back(make_pair(1,3));
        }
    }

    while(!ST.empty() && j < len)
    {
        if(ST.top() == b[j])
        {
            S.push_back(make_pair(3,2));

            ST.pop(); j++;
        }
        else
        {
            break;
        }
    }

    if(!ST.empty())
    {
        flag = true;
    }

    if(flag)
    {
        printf("Are you kidding me?\n");
    }
    else
    {
        for(int i = 0;i<S.size();i++)
        {
            printf("%d->%d\n",S[i].first,S[i].second);
        }
    }
    return 0;
}
