#include <bits/stdc++.h>
#include <vector>
using namespace std;


vector<int> add(vector<int> a,vector<int> b)
{
    int len = min(a.size(),b.size());

    vector<int> t;

    int temp = 0;

    for(int i = 0; i<len; i++)
    {
        temp+=(a[i]+b[i]);

        t.push_back(temp%10);

        temp/=10;
    }

    for(int i = len; i<a.size(); i++)
    {
        temp+=a[i];

        t.push_back(temp%10);

        temp/=10;
    }

    for(int i = len; i<b.size(); i++)
    {
        temp+=b[i];

        t.push_back(temp%10);

        temp/=10;
    }

    if(temp) t.push_back(temp);

    return t;
}


string str;

vector<int> a,b;

int main()
{
    int n;

    scanf("%d",&n);

    for(int i = 0; i<n; i++)
    {
        cin>>str;
        if(i)
        {
            b.clear();

            for(int j = 49; j>=0; j--)
            {
                b.push_back(str[j]-'0');
            }

            a= add(a,b);
        }
        else
        {
            a.clear();
            for(int j = 49; j>=0; j--)
            {
                a.push_back(str[j]-'0');
            }
        }
    }

    int len = a.size();

    for(int i = len-1; i>=len-10; i--) printf("%d",a[i]);
    printf("\n");
    return 0;
}
