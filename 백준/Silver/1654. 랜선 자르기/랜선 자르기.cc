#include <iostream>
#include <algorithm>
using namespace std;

long long elec[100001];
int n, m;

bool checker(int cutter) {
	int cur = 0;
	for (int i = 0; i < n; i++) {
		cur += elec[i] / cutter;
	}
	if (cur >= m)return true;
	return false;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	cin >> n >> m;
	long long high = 0;
	long long low = 1;
	for (int i = 0; i < n; i++) {
		cin >> elec[i];
		high = max(high, elec[i]);
	}
	long long ans = 0;

	while (low<=high) {
		long long cutter = (high + low) / 2;
		if (checker(cutter)) {
			if (cutter > ans) {
				ans = cutter;
			}
			low = cutter + 1;
		}
		else {
			high = cutter - 1;
		}
	}
	cout << ans;
	
	

}