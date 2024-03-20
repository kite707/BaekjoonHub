#include <iostream>
using namespace std;

int arr[1001];

int solution(int n) {
	if (arr[n] != 0) {
		return arr[n];
	}
	if (n < 3) {
		return n;
	}
	arr[n] = (solution(n-1) + solution(n-2)) % 10007;
	return arr[n];
}

int main() {
	int n;
	cin >> n;
	cout<<solution(n);

}