#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	queue <int> d;
	for (int i = 1; i <= n; i++) {
		d.push(i);
	}
	int idx = 1;
	cout << "<";
	while (!d.empty()) {
		if (d.size() == 1) {
			cout << d.front() << ">";
			d.pop();
		}
		else if (idx % k == 0) {
			cout << d.front() << ", ";
			d.pop();
			++idx;
		}
		else {
			++idx;
			int a = d.front();
			d.pop();
			d.push(a);
		}
		
	}
}