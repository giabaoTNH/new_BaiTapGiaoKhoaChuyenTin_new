#include <bits/stdc++.h>
using namespace std;

int f[20][32769];
int a[20][20];

int dp(int i, int mask) {
	//cout << "Hello world" << i << ' ' << mask << '\n';
	if (i < __builtin_popcount(mask)) return INT_MIN;
	if (__builtin_popcount(mask) == 1) {
		//cout << 32 - __builtin_clz(mask) << '\n';;
		return a[i][32-(__builtin_clz(mask))];
	}
	if (f[i][mask] != -1) return f[i][mask];	

	int kq = INT_MIN;
	int mask2 = mask;
	int j = 0;
	while(mask2) {
		mask2 = (mask>>j);
		kq = max(kq,dp(i-1,(mask & ~(1 << j))) + (mask2&1)*a[i][j+1]);
		j+=1;
	}

	return f[i][mask] = kq;
}
int main() {
	int n,k; cin >> n >> k;
	for (int i = 1; i<=n; i++) {
		for (int j = 1; j<=n; j++) cin >> a[i][j];
	}
	for (int i = 0; i<=n; i++) {
		for (int mask = 0; mask < (1<<n); mask++) {
			f[i][mask] = -1;
		}
	}	
	int ans = INT_MIN;
	for (int i = k; i<=n; i++) {
		for (int mask = 1; mask < (1 << n); mask++) if (__builtin_popcount(mask) == k) {
			ans = max(ans, dp(i,mask));
		}	
	}
	int d = 0;
	for (int i = k; i<=n; i++) {
		for (int mask = 1; mask < (1 << n); mask++) if (__builtin_popcount(mask) == k) {
			d += (f[i][mask] == ans);
		}	
	}

	cout << ans << ' ' << d << '\n';
}
