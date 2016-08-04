#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

struct node
{
    int x,y;
    int step;
} s,w;

int m,n;//m表示列n表示行
char map[300][300];//储存地图
int dis[300][300];//记录两个字母之间的距离
int book[300][300];//标志
int wz[300][300];//记录字母的位置 记下它的编号
int dx[4]= {-1,0,1,0};
int dy[4]= {0,1,0,-1};

int pd(int x,int y)//判断是否合法
{
    if(x>=0&&y>=0&&x<n&&y<m&&!book[x][y]&&map[x][y]!='#')
        return 1;
    return 0;
}

void bfs(int x,int y)
{
    memset(book,0,sizeof(book));
    int i,j,flag;
    queue<node>q;
    s.x=x;
    s.y=y;
    s.step=0;
    book[x][y]=1;
    q.push(s);

    while(!q.empty())
    {
        s=q.front();
        q.pop();


        if(map[s.x][s.y]=='A'||map[s.x][s.y]=='S')
        {
            dis[wz[x][y]][wz[s.x][s.y]]= dis[wz[s.x][s.y]][wz[x][y]]=s.step;

        }

        for(i=0; i<4; i++)
        {
            int nx=s.x+dx[i];
            int ny=s.y+dy[i];
            if(pd(nx,ny))
            {
                w.x=nx;
                w.y=ny;
                w.step=s.step+1;
                book[nx][ny]=1;
                q.push(w);
            }

        }
    }

}
int main()
{
    int t,i,j,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        getchar();
        for(i=0; i<n; i++) //输入地图
            gets(map[i]);

        ans=0;
        memset(wz,0,sizeof(wz));

        for(i=0; i<n; i++) //找到字母 并记录位置 和序号
            for(j=0; j<m; j++)
            {
                if(map[i][j]=='A'||map[i][j]=='S')
                    wz[i][j]=++ans;//记录序号

            }
        ///////
        /*for(i=0;i<n;i++)
            for(j=0;j<m;j++)
        {
                 printf("%d ",wz[i][j]);

        }
           printf("%d\n",wz[i][j]);*/
//        num=0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(wz[i][j]!=0)//如果是字母 就bfs寻找到其余点的距离
                    bfs(i,j);
            }
        }

        for(i=1; i<ans; i++)
            for(j=1; j<ans; j++)
                printf("%d %d %d\n",i,j,dis[i][j]);
        // fflush(stdin);
    }

    return 0;
}

