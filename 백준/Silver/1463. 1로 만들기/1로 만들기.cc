#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1000001];
int m = 10000000;

int solution(int i) {
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	if (dp[i] != m) {
		return dp[i];
	}
	if (i % 3 == 0) {
		dp[i] = min(dp[i], solution(i/3)+1);
	}
	if (i % 2 == 0) {
		dp[i] = min(dp[i], solution(i/2)+1);
	}
	dp[i] = min(dp[i], solution(i-1) + 1);
	return dp[i];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	fill(&dp[0], &dp[0] + 1000001, m);
	int k;
	cin >> k;
	cout << solution(k);
}