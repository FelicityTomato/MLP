#include <bits/stdc++.h>
//#define int long long
#define INF 0x3f3f3f3f
#define mod 1000000007
#define endl '\n'
#define rep(i, st, ed) for (int (i) = (st); (i) <= (ed);++(i))
#define pre(i, ed, st) for (int (i) = (ed); i >= (st);--(i))
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
inline int lowbit(int x) { return x & -x; }
const int N = 200005;

int n, m,c;
int w[N], v[N];
int f[N];
int g[N]; // 价值为f[i] 的方案数 

void solve() {
	cin >> n >> c >> m;
	for (int i = 1; i <= n; ++i)cin >> w[i] >> v[i];
	// 价值为f[0] 即价值为0时的方案数为 1 那就是都不选 
	g[0] = 1;
	// 01背包
	for (int i = 1; i <= n; ++i) {
		for (int j = m; j >= w[i]; --j) {
			int maxn = max(f[j], f[j - w[i]] + v[i]);
			int cnt = 0;
			if (maxn == f[j])cnt += g[j];
			if (maxn == f[j - w[i]] + v[i])cnt += g[j - w[i]];

			f[j] = maxn;
			g[j] = cnt % mod;
		}

	}

	// 求出价值最大为多少
	int cnt = 0;
	for (int i = 0; i <= m; ++i) {
		cnt = max(cnt, f[i]);
	}

	//枚举体积 如果当前体积下价值与最大价值相等  那么答案加上 g[j]
	int res = 0;
	for (int i = 0; i <= m; ++i) {
		if (f[i] == cnt)
			res = (res + g[i]) % mod;
	}

	cout << cnt << ' '<< res << '\n';
}

signed main() {
	// int t;cin >> t;
	// while(t--)
	solve();

	return 0;
}