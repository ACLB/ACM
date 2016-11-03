#include <bits/stdc++.h>

#define rep(i, x, y) for (int i = (x), _ = (y); i <= _; ++i)
#define down(i, x, y) for (int i = (x), _ = (y); i >= _; --i)
#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long LL;

template<typename T> inline void upmax(T & x, T y) { x < y ? x = y : 0; }
template<typename T> inline void upmin(T & x, T y) { x > y ? x = y : 0; }

template<typename T>
inline void read(T & x)
{
	char c;
	while ((c = getchar()) < '0' || c > '9');
	for (x = c - '0'; (c = getchar()) >= '0' && c <= '9'; x = x * 10 + c - '0');
}

typedef long double ldb;

const ldb eps = 1e-8;
const int N = 55;

inline int dcmp(const ldb x)
{
	return x < -eps ? -1 : x > eps;
}

LL C[N][N];

vector<int> G[N];
int col[N], A[N], use[N];
int fa[N], d[N], n;

void Dfs(int x)
{
	for (int y = fa[x]; y; y = fa[y])
	{
		if (use[y] && d[x] - d[y] <= A[y])
			col[x] ^= 1;
	}
	if (!col[x])
	{
		use[x] = 1;
		col[x] = 1;
	}
	rep (i, 0, G[x].size() - 1)
	{
		d[G[x][i]] = d[x] + 1;
		Dfs(G[x][i]);
	}
}

ldb a[N][N];

ldb Gauss(int n)
{
	int i = 0, j, k;
	for ( ; i <= n; ++i)
	{
		for (j = i; dcmp(a[j][i]) == 0; ++j) ;
		if (i != j)
			swap(a[i], a[j]);
		for (j = i + 1; j <= n; ++j)
		{
			if (dcmp(a[j][i]))
			{
				ldb tmp = a[j][i] / a[i][i];
				for (k = i; k <= n + 1; ++k)
					a[j][k] -= tmp * a[i][k];
			}
		}
	}
	for (i = n; ~i; --i)
	{
		a[i][n + 1] /= a[i][i];
		for (j = i - 1; ~j; --j)
		{
			if (dcmp(a[j][i]))
				a[j][n + 1] -= a[i][n + 1] * a[j][i];
		}
	}
	return abs(a[0][n + 1]);
}

void work()
{
	read(n);
	int x, y;
	rep (i, 1, n)
		G[i].clear();
	rep (i, 2, n)
	{
		read(x), read(y);
		G[x].pb(y);
		fa[y] = x;
	}
	rep (i, 1, n)	read(col[i]);
	rep (i, 1, n)	read(A[i]);
	memset(use, 0, sizeof(use));
	Dfs(1);
	int cnt = count(use + 1, use + n + 1, 1);
	memset(a, 0, sizeof(a));
	rep (i, 0, n) 
	{
		a[i][i] = 1.0;
		a[i][n + 1] = 1.0;
		ldb tmp = 1.0 / n;
		if (i == cnt)
		{
			ldb t = 1.0 / C[n][i];
			a[i][n + 1] *= 1.0 - t;
			tmp *= 1.0 - t;
		}
		if (i < n)
			a[i][i + 1] = -tmp * (n - i);
		if (i > 0)
			a[i][i - 1] = -tmp * i;
	}
	printf("%.3Lf\n", Gauss(n));
}

int main()
{
#ifdef LX_JUDGE
	freopen("in.txt", "r", stdin);
#endif

	C[0][0] = 1;
	rep (i, 1, 50)
	{
		C[i][0] = 1;
		rep (j, 1, i)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}

	int kase;
	read(kase);
	while (kase--)
		work();

	return 0;
}
