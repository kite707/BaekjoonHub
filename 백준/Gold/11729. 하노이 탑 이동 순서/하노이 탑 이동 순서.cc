#include <iostream>
#include <cmath>
using namespace std;

void solution(int a, int b, int n){//a에서 b로 n개의 기둥 옮기기
    if(n==1){
        cout<<a<<" "<<b<<"\n";
        return;
    }
    solution(a,6-a-b,n-1);
    cout<<a<<" "<<b<<"\n";
    solution(6-a-b,b,n-1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    cout<<(1<<n)-1<<"\n";
    solution(1,3,n);
}