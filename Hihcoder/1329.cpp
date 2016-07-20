#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

typedef struct node
{
    int data;

    node *Left,*Right,*fa;

}Node;


void Zig(Node *p)
{
    Node *C = p->Left;

    Node *s = C->Right;

    Node *fa = p->fa;

    if(fa)
    {
        if(fa->Left == p) fa->Left = C;
        else fa->Right = C;
    }

    C->fa = fa;

    C->Right = p;

    p->fa = C;

    p->Left = s;

    if(s) s->fa = p;
}

void Zag(Node *p)
{
    Node *c = p->Right;

    Node *s = c->Left ;

    Node *fa = p->fa;

    if(fa)
    {
        if(fa->Left == p) fa->Left = c;
        else fa->Right = c;
    }

    c->fa = fa;

    p->Right = s;

    if(s) s->fa = p;

    c->Left = p;

    p->fa = c;
}

Node * Insert(Node *&p,int value,Node *fa)
{
    if(!p)
    {
        p = new Node;
        p->Left = p->Right = NULL;
        p->fa = fa;
        p->data = value;
        return p;
    }

    if(p->data == value) return p;
    if(p->data < value) return Insert(p->Right,value,p);
    else return Insert(p->Left,value,p);
}

void Rotate(Node *p,Node *fa)
{
    while(p->fa != fa)
    {
        Node *f = p->fa;
        Node *Gf = f->fa; 
        if(Gf != fa)
       {
           if(Gf->Left == f)
           {
               if(f->Left == p)
               {
                   Zig(Gf);
                   Zig(f);
               }
               else
               {
                   Zag(f);
                   Zig(Gf);
               }
           }
           else
           {
               if(f->Left == p)
               {
                   Zig(f);
                   Zag(Gf);
               }
               else
               {
                   Zag(Gf);
                   Zag(f);
               }
           }
       }
      else
      {
          if(f->Left == p) Zig(f);
          else Zag(f);
      } 
    }
}

Node *ans;

void Min(Node *p,int value)
{
    if(!p) return ;

    if(p->data == value) 
    {
        ans = p;

        return ;
    }

    if(p->data < value)
    {
        ans = p;

        Min(p->Right,value);
    }
    
    else Min(p->Left,value);
}

void Max(Node *p,int value)
{
    if(!p) return ;

    if(p->data == value)
    {
        ans = p;

        return ;
    
    }

    if(p->data>value)
    {
        ans = p;

        Max(p->Left,value);
    }

    
    else Max(p->Right,value);
}


int main()
{
    int n;

    char op[3];

    int l,r;

    Node *root = NULL;

    scanf("%d",&n);

    Insert(root,-INF,NULL);

    Insert(root,INF,NULL);

    while(n--)
    {
        scanf("%s",op);

        if(op[0] == 'I')
        {
            scanf("%d",&l);

            Node * p = Insert(root,l,NULL);

            Rotate(p,NULL);

            root = p;

        }
        else if(op[0] == 'Q')
        {
            scanf("%d",&l);
            
            ans = NULL;

            Min(root,l);

            Rotate(ans,NULL);

            root = ans;

            printf("%d\n",ans->data);
        }
        else if(op[0] == 'D')
        {
            scanf("%d %d",&l,&r);

            ans = NULL; Min(root,l-1);

            Rotate(ans,NULL);

            root = ans;

            ans = NULL;

            Max(root,r+1);

            Rotate(ans,root);

            root->Right->Left = NULL;
        }
    }
    return 0;
}
