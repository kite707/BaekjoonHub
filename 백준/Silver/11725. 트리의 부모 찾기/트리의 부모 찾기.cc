#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, a, b;

vector<int> v[100001];
int arr[100001];

void bfs(int start) {
	arr[start] = 1;
	queue <int> q;
	q.push(start);

	while(!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			if (arr[v[cur][i]] == 0) {
				arr[v[cur][i]] = cur;
				q.push(v[cur][i]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	int aa = n;
	n--;
	while (n--) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs(1);
	for (int i = 2; i <= aa; i++) {
		cout << arr[i] << "\n";
	}


}