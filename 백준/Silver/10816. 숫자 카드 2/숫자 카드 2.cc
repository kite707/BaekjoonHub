#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int cnt[500001];
int getSt(int n) {
	int st = 0;
	int en = v.size();
	while (st != en) {
		int mid = (st + en) / 2;
		if (v[mid] >= n)en = mid;
		if (v[mid] < n)st = mid + 1;
	}
	return en;
}

int getEn(int n) {
	int st = 0;
	int en = v.size();
	while (st != en) {
		int mid = (st + en) / 2;
		if (v[mid] > n)en = mid;
		if (v[mid] <= n)st = mid + 1;
	}
	return en;
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
		int stIdx = getSt(t);
		int enIdx = getEn(t);
		cout << enIdx-stIdx << " ";
	}
}