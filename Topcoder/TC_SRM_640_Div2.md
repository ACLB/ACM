## Topcoder 640 Div2
### A

----

`题意：给你每一个序列的编号和对应的颜色，判断对应颜色不同的有多少个。`

```cpp

#include <bits/stdc++.h>

using namespace std;

class ChristmasTreeDecorationDiv2
{
	public:
	
	int solve(vector <int> col, vector <int> x, vector <int> y)
	{
		int n = col.size();
		
		int ans = 0;
		
		for(int i = 0;i<n-1;i++)
		{
			if(col[x[i]-1]!=col[y[i]-1])
			{
				ans++;
			}
		}
		return ans;
	}
};
```

### B

----

题意：规定一个游戏：从1开始每次$\times$2和$\times$2+1，就是一颗满二叉树，现在给你二叉树的层数，和在游戏中不能出现的数字，判断这样的二叉树有多少个节点。

`思路:对于每次的操作，就相当于在这个数的后面增加一位，那么我们就可以很方便的计算出以某一个数为根的子树节点的个数`

```cpp
#include <bits/stdc++.h>

using namespace std;

class NumberGameAgain
{
	public:
	
	int a[50],b[50];
	
	long long Pow(int k)
	{
		long long ans =1;
		
		for(int i = 1;i<=k;i++) ans*=2;
		
		return ans-2;
	}
	void GetBit(long long u,long long v)
	{
		a[0] = 0; b[0]= 0 ;
		while(u)
		{
			a[++a[0]] = u%2;
			
			u>>=1;
		}
		while(v)
		{
			b[++b[0]] = v%2;
			
			v>>=1;
		}
	}
	
	int GetBitSize(long long u)
	{
		int ans = 0;
		
		while(u) 
		{
			u>>=1;
			
			ans++;
		}
		return ans;
	}
	
	bool Judge(long long u,long long v)
	{
		GetBit(u,v);
		
		for(int i =a[0],j = b[0];i>=1; i--, j--)
		{
			if(a[i] != b[j]) return true;
		}
		
		return false;	
	}
	
	long long cal(int k,long long u)
	{
		
		long long  ans = 1;
		
		for(int i = GetBitSize(u);i <= k;i++) ans *= 2;
		
		return ans-1;
	}
	long long solve(int k, vector<long long> table)
	{
		long long n = Pow(k);
		
		long long ans = 0;
		
		sort(table.begin(),table.end());
		
		table.erase(unique(table.begin(),table.end()),table.end());
		
		int m = table.size();
		
		for(int i = 0;i < m;i++)
		{
			bool flag = false;
			
			for(int j = 0;j < i; j++)
			{
				if(!Judge(table[j],table[i]))
				{
					
					flag = true;
					
					break;
				}
			}
			if(!flag) ans+=cal(k,table[i]);	
		}
		return n - ans;	
	}
};
```

### C

-----

`题意:给你两个集合，求解两个集合最小的距离，距离：两个集合相同元素个数的绝对值之和。`

思路：对于这两个集合中的$x和y，如果 x \% m == y \% m，那么此时的结果是比较小的$。
$$那么x = k_1m+b_1,y = k_2m+b_2,|x-y|\%m = |b_1-b_2|\%m$$所以我们统计的是（x-y）的因子作为模数。

```cpp
#include <bits/stdc++.h>

using namespace std;

class TwoNumberGroupsEasy
{
	public :
	
	int n,m;
	
	set<int>S;
	
	map<int,int>M;
	
	void Getfactor(int num)
	{
		for(int i = 2;i*i<=num;i++)
		{
			if(num %i == 0)
			{
				S.insert(i);
				
				S.insert(num/i);
			}
		}
		if(num > 1) S.insert(num);
	}
	
	int solve(vector <int> A, vector <int> numA, vector <int> B, vector <int> numB)
	{
		n = A.size();
		
		m = B.size();
		
		S.clear();
		
		for(int i = 0 ;i<n;i++)
		{
			for(int j = 0;j<m;j++)
			{
				Getfactor(abs(A[i]-B[j]));
			}
		}
		
		M.clear();
		
		for(int i = 0;i < n; i++) M[A[i]] += numA[i];
		
		for(int i = 0;i < m; i++) M[B[i]] -= numB[i];
		
		int ans = 0;
		
		for(map<int,int>::iterator it = M.begin();it != M.end();it++)
			ans += abs(it->second);
			
		for(set<int>::iterator its = S.begin(); its != S.end(); its++)
		{
			M.clear();
			
			for(int i = 0;i < n; i++) M[A[i]%(*its)] += numA[i];
			
			for(int i = 0;i < m; i++) M[B[i]%(*its)] -= numB[i];
		
			int ant = 0;
				
			for(map<int,int>::iterator it = M.begin();it != M.end();it++)
				ant+=abs(it->second);
				
			ans = min(ant,ans);
		}
		return ans;
	}
};
```