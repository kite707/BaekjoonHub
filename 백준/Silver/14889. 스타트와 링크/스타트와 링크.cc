#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[21][21];
int n, s;
//스타트팀은 1, 링크팀은 0
int people[21];

priority_queue <int, vector<int>, greater<int>> q;
int calculate_start() {
	int startscore = 0;
	vector<int> teamstart;
	for (int i = 1; i <= n; i++) {
		if (people[i] == 1) {
			teamstart.push_back(i);
		}
	}

	for (int i = 0; i < teamstart.size() - 1; i++) {
		for (int j = i + 1; j < teamstart.size(); j++) {
			startscore += arr[teamstart[i]][teamstart[j]] + arr[teamstart[j]][teamstart[i]];
		}
	}
	return startscore;
}
int calculate_link() {
	int linkscore = 0;
	vector<int> teamlink;
	for (int i = 1; i <= n; i++) {
		if (people[i] == 0) {
			teamlink.push_back(i);
		}
	}

	for (int i = 0; i < teamlink.size() - 1; i++) {
		for (int j = i + 1; j < teamlink.size(); j++) {
			linkscore += arr[teamlink[i]][teamlink[j]] + arr[teamlink[j]][teamlink[i]];
		}
	}
	return linkscore;
}


void maketeam(int curteamsiz, int before_end) {
	if (curteamsiz == n/2) {
		int save = calculate_start()-calculate_link();
		if (save < 0) {
			save *= -1;
		}
		q.push(save);
	}
	else {
		for (int i = before_end+1; i <= n; i++) {
			people[i] = 1;
			maketeam(curteamsiz + 1, i);
			people[i] = 0;
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	maketeam(0, 1);
	cout << q.top();

}