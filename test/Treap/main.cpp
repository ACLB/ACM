#include <bits/stdc++.h>

using namespace std;

typedef struct Treap
{
    Treap *Left,*Right;

    int value,key;
}Node;

void Left_Rotate(Node *&p)
{
    Node *q = p->Right;

    p->Right = q->Left;

    q->Left = p;

    p = q;
}

void Right_Rotate(Node *&p)
{
    Node *q = p->Left;

    p->Left = q->Right;

    q->Right = p;

    p = q;
}

void InsertNode(Node *&p,int value)
{
    if(!p)
    {
        p = new Node;

        p->Left = p->Right = NULL;

        p->value = value;

        p->key = rand();

    }
    else
    {
        if(value < p->value)
        {
            InsertNode(p->Left,value);

            if(p->Left->key < p->key)
            {
                Right_Rotate(p);
            }
        }
        else if(value >p->value)
        {
            InsertNode(p->Right,value);

            if(p->Right->key<p->key)
            {
                Left_Rotate(p);
            }
        }
    }
}

int ans;

void Search(Node *p,int value)
{
    if(p->value == value)
    {
        ans = value;

        return ;
    }

    else
    {
        if(p->value<value)
        {
            ans = max(ans,p->value);
            if(p->Right)
                Search(p->Right,value);
        }
        else if(p->value>value)
        {
            if(p->Left)
                Search(p->Left,value);
        }
    }
}

int n , data;

char op[3];

int main()
{
    scanf("%d",&n);

    Node *root = NULL;

    for(int i = 0;i<n;i++)
    {
        scanf("%s %d",op,&data);

        if(op[0] == 'Q')
        {
            ans =-1e9;

            Search(root,data);

            printf("%d\n",ans);

            continue;
        }
        if(root)
        {
            InsertNode(root,data);
        }
        else
        {
            root  = new Node;

            root->value = data;

            root->key = rand();

            root->Left = root->Right = NULL;
        }


    }
    return 0;
}
