#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int binary_search(int n) {
	int st = 0;
	int en = v.size() - 1;
	while (st <= en) {
		int mid = (st + en) / 2;
		if (v[mid] == n)return 1;
		if (v[mid] > n)en = mid - 1;
		if(v[mid]<n)st = mid + 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,t;
	cin >> n;
	while (n--) {
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	cin >> n;
	while (n--) {
		cin >> t;
		cout << binary_search(t) << "\n";
	}
}