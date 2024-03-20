#include <iostream>
#include <vector>
#include <algorithm>
#define P pair<int,int>
using namespace std;

int n, k;
int w, v;
vector<P> vec;
int arr[101][100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	int save = n;
	while (n--) {
		cin >> w >> v;
		vec.push_back(P(w, v));
	}
	for (int i = 1; i <= vec.size(); i++) {
		for (int j = 1; j <= k; j++) {
			int curweight = vec[i-1].first;
			int curvalue = vec[i-1].second;
			//짐 넣기 가능
			if (curweight <= j) {
				int a = arr[i - 1][j];
				int b = arr[i - 1][j - curweight] + curvalue;
				arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - curweight]+curvalue);
			}
			//짐 넣기 불가능
			else {
				arr[i][j] = arr[i - 1][j];
			}
		}
		

		
	}
	cout << arr[save][k];

}