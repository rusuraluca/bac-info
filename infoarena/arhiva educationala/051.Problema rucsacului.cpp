#include <fstream>

using namespace std;

ifstream cin("rucsac.in");
ofstream cout("rucsac.out");

const int maxn = 5005;
const int maxg = 10005;

int n, g, w[maxn], p[maxn], dp[2][maxg];

int main() {
	cin >> n >> g;
	for(int i=1; i<=n; ++i)
		cin >> w[i] >> p[i];
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=g; ++j) {
			dp[i & 1][j] = dp[i & 1 ^ 1][j];
			if(j >= w[i])
				dp[i & 1][j] = max(dp[i & 1][j], dp[i & 1 ^ 1][j - w[i]] + p[i]);
		}
	int ans = 0;
	for(int i=0; i<=g; ++i)
		ans = max(ans, dp[n & 1][i]);
	cout << ans << '\n';
}