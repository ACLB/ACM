#include <bits/stdc++.h>

using namespace std;

typedef struct node
{
    int num,t;

    node(){}

    node(int _num,int _t):num(_num),t(_t){}

    bool operator < (const node &a)const
    {
        return t<a.t;
    }
}No;


char s[2],op[10];

char s1[2],s2[2];

int data;

int main()
{
    //freopen("in.in","r",stdin);
    int n;

    int z = 1;

    while(~scanf("%d",&n)&&n){
    
        priority_queue<No>Q;

        priority_queue<No>Q1;

        priority_queue<No>Q2;

        printf("Case #%d:\n",z++);

        for(int i = 1;i<=n;i++)
        {
            scanf("%s",op);

            if(op[1] == 'u')
            {
                scanf("%s %d",s,&data);

                if(s[0] == 'A') Q1.push(node(data,i));

                else Q2.push(node(data,i));
            }
            else if(op[1] == 'o')
            {
                scanf("%s",s);

                if(s[0] == 'A')
                {
                    if(Q1.empty()) printf("%d\n",Q.top().num),Q.pop();

                    else printf("%d\n",Q1.top().num),Q1.pop();
                }
                else 
                {
                    if(Q2.empty()) printf("%d\n",Q.top().num),Q.pop();

                    else printf("%d\n",Q2.top().num),Q2.pop();
                }
            }
            else
            {
                scanf("%s %s",s1,s2);
                while(!Q2.empty()) Q.push(Q2.top()),Q2.pop();
                while(!Q1.empty()) Q.push(Q1.top()),Q1.pop();
            }
        }    
    }
    
    return 0;
}
