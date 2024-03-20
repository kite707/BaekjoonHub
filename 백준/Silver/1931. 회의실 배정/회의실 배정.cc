#include <iostream>
#include <vector>
#include <algorithm>
#define P pair<int,int>
using namespace std;

vector<P> time;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	int a, b;

	while (T--) {
		cin >> a >> b;
		time.push_back(P(b, a));
	}

	sort(time.begin(), time.end());

	int ans = 0;
	int curend = 0;
	for (int i = 0; i < time.size(); i++) {
		
		if (curend <= time[i].second) {
			curend = time[i].first;
			ans++;
		}
	}
	cout << ans;

	
}