#include <bits/stdc++.h>

using namespace std;

typedef struct node
{
    int value;

    int ci;

    node *Left,*Right;
}No;

void Insert(No *&p,int ci,int value)
{
    if(!p)
    {
        p = new No;

        p->value = value;

        p->ci = ci;

        p->Left = p->Right = NULL;

    }
    else
    {
        if(value < p->value)
        {
            Insert(p->Right,ci*2,value);
        }
        else Insert(p->Left,ci*2+1,value);
    }
}

int a[100];

int b[100];

int num ;

void bfs(No *p)
{
    queue<No *>Q;

    Q.push(p);

    while(!Q.empty())
    {
        p = Q.front();

        Q.pop();
        a[num] = p->value;

        b[num++] = p->ci;

        if(p->Left) Q.push(p->Left);

        if(p->Right) Q.push(p->Right);
    }
}

int main()
{
    int n,data;

    No *root = NULL;

    cin>>n;

    for(int i =0;i<n;i++)
    {
        cin>>data;

        Insert(root,1,data);
    }

    num = 0;

    bfs(root);

    bool flag = false;

    for(int i = 0;i<num;i++)
    {
        if(i) 
        {
            printf(" ");

            if(b[i] != b[i-1]+1)
            {
                flag = true;
            }
        }

        printf("%d",a[i]);
    }

    printf("\n");
    
    if(flag) printf("NO\n");
    else printf("YES\n");

    return 0;

}
