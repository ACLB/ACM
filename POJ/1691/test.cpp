//Memory Time 
//260K  0MS 

#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct rectangle
{
	int Lx,Ly;		 //左上角坐标 
	int Rx,Ry;		 //右下角坐标
	int SetColor;    //预设着色
	bool flag;		 //标记当前矩形是否已着色
	int UpNum;		 //该矩形上方的矩形数  (UpNum=0表示该矩形上方的矩形已全部被着色，该矩形为待着色状态)
	int low[16];     //指向该矩形下方的矩形
	int pl;          //low[]指针
};

class info
{
public:
	info(int n=0):N(n)
	{
		memset(color,false,sizeof(color));
		Rect=new rectangle[N+1];
		initial();

		MinBrushNum=20;   //最多只有15个矩形
		DFS(0,0,1);   //c==0表示当下对填涂的颜色暂无要求
	}
	~info()
	{
		cout<<MinBrushNum<<endl;
		delete[] Rect;
	}
	void initial(void);
	bool Judge_Upper(int a,int b);  //判断矩形a是否在矩形b上方
	void DFS(int n,int c,int b);   //n:当前已着色的矩形数，c:当前着色, b:当前正在用第b把刷子

protected:
	int N;			  //矩形数量
	rectangle* Rect;  //N个矩形的信息
	bool color[21];   //标记出现过的颜色
	int MinBrushNum;  //最少刷子数
};

void info::initial(void)
{
	for(int k=1;k<=N;k++)
	{
		cin>>Rect[k].Ly>>Rect[k].Lx;
		cin>>Rect[k].Ry>>Rect[k].Rx;
		cin>>Rect[k].SetColor;

		Rect[k].flag=false;
		Rect[k].UpNum=0;
		Rect[k].pl=0;

		color[ Rect[k].SetColor ]=true;
	}
	for(int i=1;i<N;i++)
		for(int j=i+1;j<=N;j++)
		{
			if(!Judge_Upper(i,j))  //若矩形i不在矩形j上方
				Judge_Upper(j,i);  //则判断矩形j是否在矩形i上方
		}
	return;
}

bool info::Judge_Upper(int a,int b)
{
	if(Rect[a].Ry==Rect[b].Ly)
	{
		if((Rect[a].Lx>=Rect[b].Lx && Rect[a].Lx<Rect[b].Rx) ||    //情况1
		   (Rect[a].Lx<=Rect[b].Lx && Rect[a].Rx>=Rect[b].Rx) ||   //情况2
		   (Rect[a].Rx>Rect[b].Lx && Rect[a].Rx<=Rect[b].Rx))	   //情况3
		{
			Rect[b].UpNum++;
			Rect[a].low[ Rect[a].pl++ ]=b;
			return true;
		}
	}
	return false;
}

void info::DFS(int n,int c,int b)
{
	if(n==N)
	{
		if(MinBrushNum > b)
			MinBrushNum = b;
		return;
	}

	if(c==0)  //填涂颜色为随意时，枚举上方矩形均已被涂色的未涂色矩形
	{
		for(int i=1;i<=N;i++)
		{
			if(!Rect[i].flag && Rect[i].UpNum==0)
			{
				int j;

				Rect[i].flag=true;
				for(j=0;j<Rect[i].pl;j++)   //第i个矩形下方的矩形的UpNum均-1
					Rect[ Rect[i].low[j] ].UpNum--;

				DFS(n+1,Rect[i].SetColor,b);  //下一次填涂的颜色与当次一样，则用同一把刷子

				Rect[i].flag=false;
				for(j=0;j<Rect[i].pl;j++)
					Rect[ Rect[i].low[j] ].UpNum++;
			}
		}
	}
	else  //填涂颜色为上次填涂的颜色
	{
		bool tag=false;
		for(int i=1;i<=N;i++)
		{
			if(Rect[i].SetColor==c && !Rect[i].flag && Rect[i].UpNum==0)
			{
				int j;
				tag=true;

				Rect[i].flag=true;
				for(j=0;j<Rect[i].pl;j++)   //第i个矩形下方的矩形的UpNum均-1
					Rect[ Rect[i].low[j] ].UpNum--;

				DFS(n+1,c,b);  //下一次填涂的颜色与当次一样，则用同一把刷子

				Rect[i].flag=false;
				for(j=0;j<Rect[i].pl;j++)
					Rect[ Rect[i].low[j] ].UpNum++;
			}
		}

		if(!tag)
			DFS(n,0,b+1);  //颜色为c的矩形均已补满足填涂条件，启用新刷子填涂其他颜色
	}
	return;
}

int main(void)
{
	int Case;
	cin>>Case;
	for(int c=1;c<=Case;c++)
	{
		int N;
		cin>>N;
		info POJ1691(N);
	}
	return 0;
}
