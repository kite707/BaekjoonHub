#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
	int a, b, c, d, e,f,g,h,i;
	cin >> a >> b >> c >> d >> e>>f>>g>>h>>i;
	vector<int> v2{ a, b, c, d, e,f,g,h,i};
	int sum,n1;
	sum = accumulate(v2.begin(), v2.end(), 0);
	n1 = sum - 100;

	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (v2[i] + v2[j] == n1) {
				v2.erase(v2.begin() + i);
				v2.erase(v2.begin() + j-1);
				i = 8;
				break;
			}
		}
	}
	
	sort(v2.begin(), v2.end());
	for (int i = 0; i < 7; i++) {
		cout << v2[i] << '\n';
	}

}