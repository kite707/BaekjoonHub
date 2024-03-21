#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
#define P pair<int,int>

using namespace std;
int checker[1000001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int a;
	cin >> a;
	while(a != 0) {
		priority_queue <P> bigq;
		priority_queue <P,vector<P>,greater<P>> smallq;
		int k;
		cin >> k;
		string op;
		int b;
		for (int i = 1; i <= k; i++) {
			cin >> op >> b;
			if (op == "I") {
				bigq.push(P(b,i));
				smallq.push(P(b, i));
			}
			else {
				if (!bigq.empty()) {
					if (b == 1) {
						//q에서 최대 삭제
						while (!bigq.empty() && checker[bigq.top().second] == 1) {
							bigq.pop();
						}
						if (!bigq.empty()) {
							checker[bigq.top().second] = 1;
							bigq.pop();
						}

					}
					else {
						while (!smallq.empty() && checker[smallq.top().second] == 1) {
							smallq.pop();
						}
						if (!smallq.empty()) {
							checker[smallq.top().second] = 1;
							smallq.pop();
						}

					}
				}
				
			}
			while (!bigq.empty() && checker[bigq.top().second] == 1) {
				bigq.pop();
			}
			while (!smallq.empty() && checker[smallq.top().second] == 1) {
				smallq.pop();
			}
		}
		
		if (bigq.empty()) {
			cout << "EMPTY" << "\n";
		}
		else {
			cout << bigq.top().first << " " << smallq.top().first << "\n";
		}
		memset(checker, 0, sizeof(checker));


		a--;
	}
}