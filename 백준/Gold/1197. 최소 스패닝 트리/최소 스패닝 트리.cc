#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[10001];
int find(int x) {
	if (parent[x] == x)return x;
	return parent[x] = find(parent[x]);
}

void uni(int x, int y) {
	x = find(x);
	y = find(y);
	parent[y] = x;
}

bool isSameParent(int x, int y) {
	x = find(x);
	y = find(y);
	return x == y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int v, e;
	cin >> v >> e;
	int result = 0;
	vector<pair<int, pair<int,int>>> vec;
	for (int i = 0; i < e; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		vec.push_back({ cost,{from,to} });
	}
	sort(vec.begin(), vec.end());
	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < vec.size(); i++) {
		if (!isSameParent(vec[i].second.first, vec[i].second.second)) {
			uni(vec[i].second.first, vec[i].second.second);
			result += vec[i].first;
		}
	}
	cout << result;
}