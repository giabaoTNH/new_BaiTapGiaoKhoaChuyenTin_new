// Tac gia: Ha Nguyen Gia Bao
// Trang thai: AC bang sinh test
#include <bits/stdc++.h>
using namespace std;

int f[1000][1000];
int a[1000];
int main() {
	freopen("tkseq.inp", "r", stdin);
	freopen("tkseq.out", "w", stdout);

	int n,k; cin >> n >> k;
	for (int i = 1; i<=n; i++) {
		cin >> a[i];
		f[i][1] = a[i];
	}
	for (int j = 2;j<=k*3; j++) {
		for (int i = 2; i<=n; i++) {
			int neg = (j%3==2)*(-2) + 1;
			f[i][j] = INT_MIN;
			for (int z = j-1; z <i; z++) {
				f[i][j] = max(f[i][j], neg*a[i] + f[z][j-1]);
			}
		}
	}
	int ans = INT_MIN;
	for (int i = k*3; i<=n; i++) {
		ans = max(ans, f[i][k*3]);
	}
	cout << ans << '\n';

	return 0;
}

/* Code sinh test:
#include <bits/stdc++.h>
using namespace std;

int ans;
int a[1000], x[1000];
bool visited[1000];
void Try(int j, int n, int k) {
	if (j>k) {
		int sum = 0;
		for (int i = 1; i<=k; i++) {
			int neg = (i%3==2)*(-2) + 1;
			sum += neg*a[x[i]];
			//cout << x[i] << ' ';
		}
		//cout << sum << '\n';
		ans = max(ans,sum);
		return;
	}
	
	int last = (j == 1 ? 1 : x[j-1]);
	for (int i = last; i<=n; i++) if (!visited[i]) {
		visited[i] = true;
		x[j] = i;
		Try(j+1,n,k);
		visited[i] = false;
	}
}

int main() {
	int n,k; cin >> n >> k;
	for (int i =1; i<=n; i++) cin >> a[i];
	ans = INT_MIN;
	Try(1,n,3*k);
	cout << ans << '\n';
	return 0;
}
*/