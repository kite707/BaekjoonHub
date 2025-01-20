#include <iostream>
#include <unordered_map>

using namespace std;

// 전역 변수 선언
char mp[1001][1001];       // 최대 크기 1001x1001의 char 배열
int parents[2000001];      // 최대 크기 2000001의 int 배열
int N, M;

int findParent(int x) {
    if (parents[x] != x)
        parents[x] = findParent(parents[x]);
    return parents[x];
}

void makeUnion(int x, int y) {
    int rootX = findParent(x);
    int rootY = findParent(y);
    if (rootX < rootY)
        parents[rootY] = rootX;
    else
        parents[rootX] = rootY;
}

void go(int r, int c) {
    int nowIndex = r * M + c; // 현재 인덱스 계산
    char curChar = mp[r][c];   // 현재 문자를 가져옴
    int nxtY, nxtX;

    if (curChar == 'R') {
        if (c == M - 1) return;
        nxtY = r;
        nxtX = c + 1;
    }
    else if (curChar == 'L') {
        if (c == 0) return;
        nxtY = r;
        nxtX = c - 1;
    }
    else if (curChar == 'U') {
        if (r == 0) return;
        nxtY = r - 1;
        nxtX = c;
    }
    else if (curChar == 'D') {
        if (r == N - 1) return;
        nxtY = r + 1;
        nxtX = c;
    }
    else {
        return;  // 잘못된 경우 처리를 위해
    }

    int nxtIdx = nxtY * M + nxtX; // 다음 인덱스 계산
    if (findParent(nowIndex) != findParent(nxtIdx)) {
        makeUnion(nowIndex, nxtIdx); // union 호출
        go(nxtY, nxtX); // 재귀 호출
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    // 초기화
    for (int i = 0; i < N * M; ++i) {
        parents[i] = i; // 각 부모를 자기 자신으로 초기화
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> mp[i][j]; // mp 배열에 입력 받기
        }
    }

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            if (findParent(r * M + c) == r * M + c) {
                go(r, c);
            }
        }
    }

    unordered_map<int, int> result;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            result[findParent(r * M + c)] = 1; // 결과에 루트 저장
        }
    }

    cout << result.size() << endl; // 서로 다른 부모의 수 출력

    return 0;
}
