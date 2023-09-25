#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

constexpr auto Mod = ll{ 1'000'000'000 };

ll n, k;
vvl dp;

ll solve(ll n, ll k) {
	if (0 == n || 1 == k) {
		return 1;
	}

	if (dp[n][k] < 0) {
		dp[n][k] = 0;
		for (auto i = 0; i <= n; ++i) {
			dp[n][k] += solve(n - i, k - 1);
			dp[n][k] %= Mod;
		}
	}

	return dp[n][k];
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n >> k;
	dp = vvl(n + 1, vl(k + 1, -1));
	dp[0][1] = 1;

	const auto ans = solve(n, k);
	cout << ans;

	return 0;
}