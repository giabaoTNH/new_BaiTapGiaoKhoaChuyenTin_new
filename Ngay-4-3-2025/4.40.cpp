#include <bits/stdc++.h>
using namespace std;
long long a[1007], cd[1007], sq[1007]; 
double ts[1007][1007], f[1007][1007];
int main() {
	freopen("lss.inp","r",stdin);
	freopen("lss.out", "w", stdout);
	int n,g; cin >> n >> g;
	for (int i = 1; i<=n; i++) {
		cin >> a[i];
		cd[i] = cd[i-1] + a[i];
		sq[i] = sq[i-1] + a[i]*a[i];
	}
	for (int i = 1; i<=n; i++) {
		for (int j = i; j<=n; j++) {
			long long sum = cd[j] - cd[i-1];
			long long sum_2 = sq[j] - sq[i-1];
			double mean = ((double)(sum))/(j-i+1);
			ts[i][j] = (double)(sum_2) - 2*sum*mean + (mean*mean)*(j-i+1);
		}
		f[i][1] = ts[1][i];
	}
	for (int j = 2; j<=g; j++) {
		for (int i = j; i<=n; i++)	{
			f[i][j] = (1e9);
			for (int k = j-1; k<i;k++) {
				f[i][j] = min(f[i][j], f[k][j-1]+ts[k+1][i]);
			}
		}
	}
	cout << f[n][g];
}