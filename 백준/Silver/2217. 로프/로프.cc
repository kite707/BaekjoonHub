#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int a;
    int b = n;
    int ans=0;
    while(b--){
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=v.size()-1;i>=0;i--){
        int cnt=v.size()-i;
        ans=max(ans,v[i]*cnt);
    }
    cout<<ans;


}