#include <bits/stdc++.h>
using namespace std;

bool giaiduoc;
int a[100],b[100],c[100],ansa[100],ansb[100],ansc[100];
void next_solve(int i, int phat) {
	if (giaiduoc) return;
	if (i == -1 && phat == 0) {
		giaiduoc=true;
		return;
	}
	// 000
	if (a[i] < 0 && b[i] < 0 && c[i] < 0) {
		ansa[i] = 4;
		ansb[i] = 4;
		ansc[i] = 8 +phat;
		next_solve(i-1, 0);
		if (giaiduoc) return;
		ansa[i] = 9;
		ansb[i] = 9;
		ansc[i] = 8 + phat;
		next_solve(i-1,1);
		return;
	}
	// 101
	if (a[i] >= 0 && b[i] <0 && c[i] >= 0) {
		if (i == 0 && a[i] == 0 && c[i] == 0) return;
		if (c[i] == 0) {
			ansb[i] = 10-phat-a[i];
			ansa[i] = a[i];	
			ansc[i] = c[i];
			next_solve(i-1,1);
			return;	
		}
		if (c[i] - phat > a[i]) {
			ansb[i] = c[i]-phat-a[i];
			ansa[i] = a[i];
			ansc[i] = c[i];
			next_solve(i-1,0);
			return;
		}
		if (c[i] - phat < a[i]) {
			ansb[i] = (10+c[i]-phat)-a[i];
			ansa[i] = a[i];
			ansc[i] = c[i];
			next_solve(i-1,1);
			return;
		}
		if (c[i] - phat == a[i]) {
			ansb[i] = 0;
			ansa[i] = a[i];
			ansc[i] = c[i];
			next_solve(i-1,0);
			return;
		}
	}
	// 011
	if (a[i] < 0 && b[i]>= 0 && c[i] >= 0) {
		if (i == 0 && b[i] == 0 && c[i] == 0) return;
		if (c[i] == 0) {
			ansa[i] = 10-phat-b[i];
			ansb[i] = b[i];	
			ansc[i] = c[i];
			next_solve(i-1,1);
			return;	
		}
		if (c[i] - phat > b[i]) {
			ansa[i] = c[i]-phat-b[i];
			ansb[i] = b[i];
			ansc[i] = c[i];
			next_solve(i-1,0);
			return;
		}
		if (c[i] - phat < b[i]) {
			ansa[i] = (10+c[i]-phat)-b[i];
			ansb[i] = b[i];
			ansc[i] = c[i];
			next_solve(i-1,1);
			return;
		}
		if (c[i] - phat == b[i]) {
			ansa[i] = 0;
			ansb[i] = b[i];
			ansc[i] = c[i];
			next_solve(i-1,0);
			return;
		}
	}
	// 001
	if (a[i] < 0 && b[i] < 0 && c[i] >= 0) {
		if (i == 0 && a[i] == 0 && b[i] == 0) return;
		if (c[i] == 0 && phat) {
			ansa[i] = 4;
			ansb[i] = 5;
			ansc[i] = c[i];
			next_solve(i-1,1);
		}
		if (c[i] == 0 && !phat) {
			ansa[i] = 0;
			ansb[i] = 0;
			ansc[i] = c[i];
			next_solve(i-1,0);
			if (giaiduoc) return;
			ansa[i] = 5;
			ansb[i] = 5;
			ansc[i] = 0;
			next_solve(i-1,1);
			return;
		}
		ansa[i] = (c[i]-phat)/2;
		ansb[i] = c[i]-c[i]/2;
		ansc[i] = c[i];
		next_solve(i-1,0);
		if (giaiduoc)return;
		ansa[i] = (10+c[i]-phat)/2;
		ansb[i] = (10+c[i]-phat)-(10+c[i]-phat)/2;
		ansc[i] = c[i];
		next_solve(i-1,1);
		return;
	}
	// 010
	if (a[i] < 0 && b[i] >= 0 && c[i] < 0) {
		if (i == 0 && b[i] == 0) return;
		if (b[i] == 9 && phat) {
			ansb[i] = b[i];
			ansa[i] = 0;
			ansc[i] = 0;
			next_solve(i-1,1);
			return ;
		}
		if (b[i] == 9 && !phat) {
			ansb[i] = b[i];
			ansa[i] = 1;
			ansc[i] = 0;
			next_solve(i-1,1);
			if (giaiduoc) return;	
			ansb[i] = b[i];
			ansa[i] = 0;
			ansc[i] = b[i];
			return;
		}
		if (b[i] == 0 && phat) {
			ansa[i] = 4;
			ansb[i] = 0;
			ansc[i] = 5;
			next_solve(i-1,0);
			if (giaiduoc)return;
			ansa[i] = 9;
			ansb[i] = 0;
			ansc[i] = 0;
			next_solve(i-1,1);
			return;
		}
		if (b[i] == 0 && !phat) {
			ansa[i] = 9;
			ansb[i] = 0;
			ansc[i] = 9;
			next_solve(i-1,0);
			return;
		}
		ansb[i] = b[i];
		ansa[i] = 9-b[i]-phat;
		ansc[i] = 9;
		next_solve(i-1,0);
		if (giaiduoc)return;
		ansb[i] = b[i];
		ansa[i] = 10-(b[i]+phat);
		//cout << b[i] << ' '<< phat << ' ' << i << endl;
		ansc[i] = 0;
		next_solve(i-1,1);
		return;
	}
	// 100
	if (a[i] >= 0 && b[i] < 0 && c[i] < 0) {
		if (i == 0 && a[i] == 0) return;
		if (a[i] == 9 && phat) {
			ansa[i] = a[i];
			ansb[i] = 0;
			ansc[i] = 0;
			next_solve(i-1,1);
			return ;
		}
		if (a[i] == 9 && !phat) {
			ansa[i] = a[i];
			ansb[i] = 1;
			ansc[i] = 0;
			next_solve(i-1,1);
			if (giaiduoc) return;	
			ansa[i] = a[i];
			ansb[i] = 0;
			ansc[i] = a[i];
			return;
		}
		if (a[i] == 0 && phat) {
			ansb[i] = 4;
			ansa[i] = 0;
			ansc[i] = 5;
			next_solve(i-1,0);
			if (giaiduoc)return;
			ansb[i] = 9;
			ansa[i] = 0;
			ansc[i] = 0;
			next_solve(i-1,1);
			return;
		}
		if (a[i] == 0 && !phat) {
			ansb[i] = 9;
			ansa[i] = 0;
			ansc[i] = 9;
			next_solve(i-1,0);
			return;
		}

		ansa[i] = a[i];
		ansb[i] = 0;
		ansc[i] = a[i]+phat;
		next_solve(i-1,0);
		if (giaiduoc)return;
		ansa[i] = a[i];
		ansb[i] = 10-(a[i]+phat);
		ansc[i] = 0;
		next_solve(i-1,1);
		return;
	}
	// 110
	if (a[i] >=0 && b[i] >=0 && c[i]<0) {
		if (i == 0 && a[i] == 0 && b[i] == 0 && !phat) {

			return;
		}
		ansa[i] = a[i];
		ansb[i] = b[i];
		ansc[i] = (a[i]+b[i]+phat)%10;
		next_solve(i-1,(a[i]+b[i]+phat)/10);
		return;
	}
	// 111
	if (a[i] >=0 && b[i] >=0 && c[i] >= 0) {
		ansa[i] = a[i];
		ansb[i] = b[i];
		ansc[i] = c[i];
		if ((a[i] + b[i] + phat)%10 != c[i]) return;
		next_solve(i-1, (a[i]+b[i]+phat)/10);
		return;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s1,s2,s3;
	cin >> s1 >> s2 >> s3;
	int o1 = (int)s1.size();
	int o2 = (int)s2.size();
	int o3 = (int)s3.size();
	// if ((int)s3.size() - max((int)s1.size(), (int)s2.size()) > 1) {
	// 	cout << "NO SOLUTION\n";
	// 	return 0;
	// }

	while((int)s1.size() < (int)s3.size()) 
		s1 = string("0") + s1;
	while((int)s2.size() < (int)s3.size())
		s2 = string("0") + s2;
	int n = (int)s1.size();
	for (int i = n-1; i>=0; i--) {
		a[i] = s1[i] == '*' ? -1 : s1[i]-48;
		b[i] = s2[i] == '*' ? -1 : s2[i]-48;
		c[i] = s3[i] == '*' ? -1 : s3[i]-48;
	}
	// for (int i = 0; i<n; i++) cout << a[i] << ' '; cout << endl;
	// for (int i = 0; i<n; i++) cout << b[i] << ' '; cout << endl;
	// for (int i = 0; i<n; i++) cout << c[i] << ' '; cout << endl;

	giaiduoc = false;
	next_solve(n-1,0);
	int i;
	i = 0;while(ansa[i] == 0) i++;
	if (n-i != o1) giaiduoc=false;
	i = 0;while(ansb[i] == 0) i++;
	if (n-i != o2) giaiduoc = false;
	i = 0;while(ansc[i] == 0) i++;
	if (n-i != o3) giaiduoc = false;

	if (giaiduoc) {
		cout << "Giai duoc" << '\n';
		i = 0;
		while(ansa[i] == 0) i++;
		for (; i<n; i++) cout << ansa[i]; cout << endl;
		i = 0; while(ansb[i] == 0) i++;
		for (; i<n; i++) cout << ansb[i]; cout << endl;
		i = 0; while(ansc[i] == 0) i++;
		for (; i<n; i++) cout << ansc[i]; cout << endl;
	} else {
		cout << "NO SOLUTION\n";
	}


	return 0;
}
