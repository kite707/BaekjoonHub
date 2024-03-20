#include <iostream>
using namespace std;

int arr[100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,M;
    int t;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>t;
        arr[i]=arr[i-1]+t;
    }
    while(M--) {
        int i, j;
        cin >> i >> j;
        cout << arr[j] - arr[i - 1]<<"\n";
    }
}