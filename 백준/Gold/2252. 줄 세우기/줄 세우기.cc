#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[32001];
vector<int> v[32001];
queue<int> q;
int n, m, a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        arr[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if (arr[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        cout << cur << " ";
        q.pop();
        for (int i = 0; i < v[cur].size(); i++) {
            arr[v[cur][i]]--;
            if (arr[v[cur][i]] == 0)q.push(v[cur][i]);
        }
    }
}