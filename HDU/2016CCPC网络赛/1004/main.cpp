#include <bits/stdc++.h>

using namespace std;


int main()
{
    int T,n,z = 1;

    scanf("%d",&T);

    while(T--)
    {
        int sum = 0,data;

        scanf("%d",&n);

        priority_queue<int>Q;

        for(int i  = 0; i<n; i++)
        {
            scanf("%d",&data);

            sum+=data;

            Q.push(data);
        }

        int ans = 0;

        while(Q.size()>1)
        {
            int a = Q.top();
            Q.pop();

            int b = Q.top();
            Q.pop();

            ans+=2*b;

            a-=b;

            if(a) Q.push(a);
        }
        int a ;
        if(Q.empty()) a= 0 ;
        else
        {
            a =  Q.top();
            Q.pop();
        }
        if(a <=ans) ans+=a;
        else ans+=ans;

        printf("Case #%d: %d\n",z++,ans/2);
    }
    return 0;
}
