#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
bool map[6][6];
int xx[110];//记录路径
int yy[110];
bool flag=0;
int step;//步数
bool complete()//判断是否都为'-'
{
    int i;
    for( i = 1 ; i<=4; i++)
        for( int j = 1 ; j <=4; j++)
            if(map[i][j]!= 1)
                return 0;
    return 1;
}
void flip( int x,int y)//翻转  去反
{
    int i,j;
    for( i = 1; i <=4; i++)
    {
        map[x][i] =!map[x][i];
        map[i][y]=!map[i][y];
    }
    map[x][y]=!map[x][y];//因为上面已经重复对map【x】【y】去反了,所以要在重新去反

}
void dfs(int x,int y,int dep)
{
    xx[dep] =x;//记录路径
    yy[dep] = y;
    if(dep==step)
    {
        flag=complete();
        if(flag)//如果符合条件
        {
            printf("%d\n",step);
            for(int i =0 ; i<step ; i++)
            {
                printf("%d %d\n",xx[i],yy[i]);
            }
            return;
        }
        return;

    }
    if(y==5)  return;//边界
    flip(x,y);//翻的情况
    if(y<4)  dfs(x,y+1,dep+1);//如果下一步 没到下一行就继续，横向走
    else  dfs(x+1,1,dep+1);//如果下一步是下一行了，就跳到下一行
    flip(x,y);//不翻的的情况
    if(y<4)  dfs(x,y+1,dep);
    else  dfs(x+1,1,dep);


}
int main()
{
    int  i,j;
    char c[5];
    for( i =1; i<=4; i ++) //建图，如果是‘’——‘就取’1‘，
    {
        scanf("%s",c);
        for( j=1; j<=4; j++)
        {
            if(c[i-1]=='-') map[i][j]=1;

            else map[i][j] = 0;
        }
    }

    for(step = 0 ; step <=16; step++) //枚举步数
    {
        dfs(1,1,1);
    }
    return 0;
}
