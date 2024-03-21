#include <iostream>
#include <queue>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    priority_queue<int,vector<int>,greater<int>> q;
    int n,t;
    cin>>n;
    while(n--){
        cin>>t;
        q.push(t);
    }
    long long ans=0;
    while(q.size()!=1){
        int num1=q.top();
        q.pop();
        int num2=q.top();
        q.pop();
        ans+=num1+num2;
        q.push(num1+num2);

    }
    cout<<ans;
}