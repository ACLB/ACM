#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct node
{
    int x,y;
    int step;
} s,w;

char map[100][100];
int vis[100][100];
int m,n;
int sx,sy,ex,ey;
int dx[4]= {-1,0,1,0};
int dy[4]= {0,1,0,-1};
int pd(int x,int y)
{
    if(x>=0&&x<m&&y>=0&&y<n&&map[x][y]!='#'&&!vis[x][y])
        return 1;
    return 0;
}
void bfs()
{
    queue<node>q;
    memset(vis,0,sizeof(vis));

    s.x=sx;
    s.y=sy;
    s.step=1;
    vis[sx][sy] = 1;
    q.push(s);
    while(!q.empty())
    {
        int i,j;
        s=q.front();
        q.pop();
        if(map[s.x][s.y] == 'E')
        {
            for(i=0; i<n; i++)
            {
                for(j=0; j<m-1; j++)
                    printf("%d ",vis[i][j]);
                printf("%d\n",vis[i][j]);
            }
            printf("%d\n",s.step);
            break;
        }

        for(i=0; i<4; i++)
        {
            int nowx = s.x+dx[i];
            int nowy = s.y+dy[i];
            if(pd(nowx,nowy))
            {
                w.x=nowx;
                w.y=nowy;
                w.step=s.step+1;
                vis[w.x][w.y]=1;
                q.push(w);
            }
        }


    }
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);

        for(i=0; i<n; i++)
            scanf("%s",map[i]);

        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
            {
                if(map[i][j] == 'S')
                {
                    sx=i;
                    sy=j;
                }
                if(map[i][j] == 'E')
                {
                    ex=i;
                    ey=j;
                }
            }
        bfs();

    }
}
