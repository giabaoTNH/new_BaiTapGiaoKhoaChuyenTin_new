// Ha Nguyen Gia Bao
// Sinh test? Chua
// Day la loi giai giao khoa chuyen tin:v
#include <bits/stdc++.h>
using namespace std;

int cd[40][40], a[40][40], l[40][40][40][40];
int main() {
	int n,m;cin>>n>>m;
	for (int i =1; i<=n;i++){
		for (int j=1;j<=m;j++) {
			cin >> a[i][j];
			cd[i][j] = cd[i-1][j]+cd[i][j-1]-cd[i-1][j-1]+a[i][j];
		}
	}
	for (int x = 1; x <= n; x++)
	for (int y = 1; y <= m; y++)
	for (int i = 1; i+x-1<=n; i++) {
		for (int j = 1; j+y-1<=m; j++) {
			int u = i+x-1;
			int v = j+y-1;
			if ((cd[u][v]-cd[i-1][v]-cd[u][j-1]+cd[i-1][j-1] == (u-i+1)*(v-j+1)) 
				|| cd[u][v] - cd[i-1][v]-cd[u][j-1]+cd[i-1][j-1] == 0) {
				l[i][j][u][v] = 1;
				continue;
			}
			int bodoc = INT_MAX;
			int bongang = INT_MAX;
			// Bo doc
			for (int k = i; k<u; k++)  bodoc = min(bodoc, l[i][j][k][v] + l[k+1][j][u][v]);
			// Bo ngang 
			for (int k = j; k<v; k++)  bongang= min(bongang, l[i][j][u][k] + l[i][k+1][u][v]);
			l[i][j][u][v] = min(bongang,bodoc);
		}
	}
	cout << l[1][1][n][m];
}
