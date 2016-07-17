## Topcoder SRM 641 Div2

----
### A

----

`题意：Quimy和Pablo喜欢T-shirts，每天Quimy打工可以收获Q[i]元，Pablo打工可以收获P[i]元，T-shirts的价格是T元，当他们的钱可以买T-shirts他们就会买，问他们有多少次可以一起去买。`

```cpp
#include <bits/stdc++.h>

using namespace std;

class BuyingTshirts
{
	public :
	
	int meet(int T, vector <int> Q, vector <int> P)
	{
		int n = Q.size();
		
		int sum1 = 0 ,sum2 = 0;
		
		int ans = 0 ;
		
		for(int i = 0;i<n;i++)
		{
			sum1 += Q[i];
			
			sum2 += P[i];
			
			if(sum1 >= T && sum2 >= T)
			{
				ans++;
			}
			
			if(sum1 >= T) sum1 -= T;
			
			if(sum2 >= T) sum2 -= T;
		}
		
		return ans;
	}
};
```

### B

----

`题意：给你一些点，判断这些点中的三个点组成的三角形有多少是包括原点的。`

`思路：如果原点在三角形中，那么三角形的任意两个定点之间和原点组成的小三角形的面积和等于三角形的面积。`

```cpp
#include <bits/stdc++.h>

using namespace std;

class TrianglesContainOriginEasy
{
	public :
	
	bool Judge(int x1, int y1, int x2, int y2, int x3, int y3)
	{
		int area1 =abs(x1*y2-x2*y1)+abs(x2*y3-x3*y2)+abs(x3*y1-x1*y3);
		
		int area2 = abs((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1));
		
		return area1 == area2;
		
	}
	
	int count(vector <int> x, vector <int> y)
	{
		int n = x.size();
		
		int ans = 0 ;
		
		for(int i = 0;i < n; i++)
		{
			for(int j = i + 1 ; j < n; j++)
			{
				for(int k = j+1;k < n; k++)
				{
					if(Judge(x[i],y[i],x[j],y[j],x[k],y[k])) ans++;
				}
			}
		}
		
		return ans;
	}
};
```

### C

---
`先贴个代码，思路不是很清楚`
```cpp
#include <bits/stdc++.h>

using namespace std;

class ShufflingCardsDiv2
{
	public:
	
	int n,m;
	
	string shuffle(vector <int> permutation)
	{
		m  =  permutation.size();
		
		n = m/2;
		
		int num = 0;
		
		for(int i = 0;i<n;i++)
		{
			if(permutation[i*2]<=n)
			{
				num++;
			}
		}
		if(num == (n+1)/2) return "Possible";
		return "Impossible";
	}
};
```
