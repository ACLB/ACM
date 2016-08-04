#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

struct node
{
    int x,y;
    int step;
} s,w;

int m,n;//m��ʾ��n��ʾ��
char map[300][300];//�����ͼ
int dis[300][300];//��¼������ĸ֮��ľ���
int book[300][300];//��־
int wz[300][300];//��¼��ĸ��λ�� �������ı��
int dx[4]= {-1,0,1,0};
int dy[4]= {0,1,0,-1};

int pd(int x,int y)//�ж��Ƿ�Ϸ�
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
        for(i=0; i<n; i++) //�����ͼ
            gets(map[i]);

        ans=0;
        memset(wz,0,sizeof(wz));

        for(i=0; i<n; i++) //�ҵ���ĸ ����¼λ�� �����
            for(j=0; j<m; j++)
            {
                if(map[i][j]=='A'||map[i][j]=='S')
                    wz[i][j]=++ans;//��¼���

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
                if(wz[i][j]!=0)//�������ĸ ��bfsѰ�ҵ������ľ���
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

