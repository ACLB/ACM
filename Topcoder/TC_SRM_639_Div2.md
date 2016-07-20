#### Topcoder   639 Div2

##### A

题意：喂养宠物，给你两个宠物的喂养的初始的时间，喂养的次数和喂养的时间间隔。判断喂养两个宠物是不是有冲突，即两个宠物的喂养的时间是一样的，如果有返回”Difficult“，否则返回“Easy”。



思路：暴力计算即可。

```c++
#include <bits/stdc++.h>

using namespace std;

class ElectronicPetEasy
{
	public:
	string isDifficult(int st1, int p1, int t1, int st2, int p2, int t2)
	{
		for(int i = 0; i < t1; i++)
		{
			for(int j = 0;j < t2; j++)
			{
				if((st1 + i * p1) == (st2 + j * p2))
				{	
					return "Difficult";
				}
			}
		}
		return "Easy";
	}
};
```

##### B

题意：规定一种比赛的规则，在第i场比赛获胜的人将获得i分。现在给你两个人的得分，判断第一个人最少参加多少场比赛才能得到这些分数，如果输入不合法（即在n场比赛中不可能组成他们的这样的分数）输出-1。

思路：首先判断输如的两个分数是不是合法，即是不是存在一个n使的$\frac{n*(n-1)}{2} = x+y$，如果不存在输出-1，否则我们从大到小贪心的计算第一个人的比赛的次数。

```c++
#include <bits/stdc++.h>

using namespace std;

class AliceGameEasy
{
	public :
	
	long long GetMin(long long x,long long y)
	{
		long long sum = 2*(x+y);
		
		if(sum == 0) return 0;
		
		long long  s = (long long) (sqrt(sum))-1;
		
		if(s*s+s == sum) return s;
		
		s++;
		
		if(s*s+s == sum) return s;
		
		return -1;
	}
	
	long long findMinimumValue(long long x, long long y)
	{
		long long s = GetMin(x,y);
		
		if(s == -1 ||s == 0) return s;
		
		long long ans = 0;
		
		for(long long i = s;i>=1;i--)
		{
			if(x >= i)
			{	
				x -=i;
				
				ans++;
			}
		}
		return ans;
	}
};
```

##### C

题意：给你一个01矩阵，现在要折叠这个矩阵，折叠满足：

1. 平行于某条边折叠。
2. 要沿相邻两列数字之间折叠
3. 折叠后下方的数字与上方的数字相同。

问有多少的折叠的方法。

思路：显然我们可以将行和列进行分开计算。如果求出行的折叠的方案数ansR和列的方案数ansL,那么答案就是ans =  ansL*ansR.

行和列的求法是一样的。由于矩阵最大为50*50，所有我们可以将每一行转化为一个数字。

首先进行预处理，设visR[i] = true表示从右开始折叠，能折叠到i，即$i+1\sim n-1$的数都全部消失。visR[i] = false表示不能折叠到i。

然后枚举左边界，visR[i] = true时，左界为i，然后处理的方式和visR一样，统计方案数。



```c++
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

class BoardFoldingDiv2
{
	public :
	
	int n , m;
	
	LL R[55],C[55];
	
	bool visL[55],visR[55];
	
	int howMany(vector <string> paper)
	{
		n = paper.size();
		m = paper[0].size();
		memset(R,0,sizeof(R));
		memset(C,0,sizeof(C));
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<m;j++)
			{
				R[i] = R[i] * 2 + paper[i][j] - '0';
				C[j] = C[j] * 2 + paper[i][j] - '0';
			}
		}
		memset(visR,false,sizeof(visR));
		visR[n-1] = true;
		int ansR = 0;
		for(int i = n-2;i>=0;i--)
		{
			for(int j = 1; i + j < n && i - j + 1 >= 0; j++)
			{
				if(R[i+j] == R[i-j+1])
				{
					if(visR[i+j])
					{
						visR[i] = true;
						break;
					}
				}
				else break;
			}
		}
		for(int k = n-1;k>=0;k--)
		{
			if(!visR[k]) continue;
			memset(visL,false,sizeof(visL));
			visL[0] = true; ansR ++;
			for(int i = 1;i<=k;i++)
			{
				for(int j  = 1;i+j-1<=k&&i-j>=0;j++)
				{
					if(R[i+j-1] == R[i-j])
					{
						if(visL[i-j])
						{
							visL[i] = true;
							break;
						}
					}
					else break;
				}
				if(visL[i]) ansR ++;
			}
		}
		int ansL = 0;
		memset(visR,false,sizeof(visR));
		visR[m-1] = true;		
		for(int i = m-2;i>=0;i--)
		{
			for(int j = 1; i + j < m && i - j + 1 >= 0; j++)
			{
				if(C[i+j] == C[i-j+1])
				{
					if(visR[i+j])
					{
						visR[i] = true;
						
						break;
					}
				}
				else break;
			}
		}
		
		for(int k = m-1;k>=0;k--)
		{
			if(!visR[k]) continue;
			
			memset(visL,false,sizeof(visL));
			
			visL[0] = true; ansL++;
			
			for(int i = 1;i<=k;i++)
			{
				for(int j  = 1;i+j-1<=k&&i-j>=0;j++)
				{
					if(C[i+j-1] == C[i-j])
					{
						if(visL[i-j])
						{
							visL[i] = true;
							
							break;
						}
					}
					else break;
				}
				
				if(visL[i]) ansL ++;
			}
		}
		
		return ansR*ansL;
	}
};
```

