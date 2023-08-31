#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> edge[1001];
int check1[1001];
int check2[1001];
void dfs(int start) {
	check1[start] = 1;
	cout << start << " ";
	for (int i = 0; i < edge[start].size(); i++) {
		if (check1[edge[start][i]] == 0) {
			dfs(edge[start][i]);
		}
	}
}
void bfs(int start) {
	queue<int> q;
	q.push(start);
	check2[start] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		

		for (int i = 0; i < edge[cur].size(); i++) {
			if (check2[edge[cur][i]] == 0) {
				q.push(edge[cur][i]);
				check2[edge[cur][i]] = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M, S;
	cin >> N >> M >> S;
	while (M != 0) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);

		M--;
	}
	for (int i = 0; i < 1001; i++) {
		sort(edge[i].begin(), edge[i].end());
	}
	dfs(S);
	cout << "\n";
	bfs(S);

}