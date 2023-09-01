#include <iostream>
#include<queue>
#pragma warning(disable : 4996)
#define P pair<int,int>

using namespace std;

int N, M;
queue<pair<int, int>> q;
int map[101][101];
int direction[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };


void bfs() {
	q.push(P(0, 0));

	while (!q.empty()) {
		P current = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = current.first + direction[i][0];
			int dy = current.second + direction[i][1];

			if (dx >= 0 && dy >= 0 && dx < M && dy < N && map[dx][dy] == 1) {
				q.push(P(dx, dy));
				map[dx][dy] = map[current.first][current.second] + 1;
			}
		}
	}
	return;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[j][i]);
		}
	}
	bfs();
	cout << map[M - 1][N - 1];
}