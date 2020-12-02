/***
  $2500 Dp Math Brute Force
  https://codeforces.com/contest/1443/problem/B
  One take away from this problem is that there are cases where brute force
  is the only way of solving the problem and normally the input size is a hint.
  
  The problem is just brutally solved with O(N^2)
  The input size is relatively small(2000)
  which makes brutally solving it possible.
  However, some bug still have to be fixed.
***/

#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

struct seg{
	int l, r;
};

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<seg> a(m);
	forn(i, m){
		cin >> a[i].l >> a[i].r;
		--a[i].l;
	}
	sort(a.begin(), a.end(), [](const seg &a, const seg &b){
		return a.l + a.r < b.l + b.r;
	});
	vector<int> su(m + 1);
	forn(i, n - k + 1){
		int cur = 0;
		for (int j = m - 1; j >= 0; --j){
			cur += max(0, min(i + k, a[j].r) - max(i, a[j].l));
			su[j] = max(su[j], cur);
		}
	}
	int ans = su[0];
	forn(i, n - k + 1){
		int cur = 0;
		forn(j, m){
			cur += max(0, min(i + k, a[j].r) - max(i, a[j].l));
			ans = max(ans, cur + su[j + 1]);
		}
	}
	cout << ans << endl;
	return 0;
}
