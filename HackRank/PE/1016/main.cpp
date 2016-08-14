#include <bits/stdc++.h>

using namespace std;

vector<int>s;

int num[11000];

void Get()
{
    s.clear();

    s.push_back(2);

    num[1] = 2;

    for(int i = 2; i<=10000; i++)
    {
        int temp = 0;

        int sum = 0;
        for(int j = 0; j<s.size(); j++)
        {
            int t= s[j];
            s[j] = (s[j]*2+temp)%10;
            temp = (t*2+temp)/10;

            sum+=s[j];
        }

        if(temp) s.push_back(temp);

        sum+=temp;

        num[i] = sum;
    }

}

int main()
{
    int T,n;

    Get();

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        printf("%d\n",num[n]);
    }
    return 0;
}
