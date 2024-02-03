#include <iostream>
using namespace std;
int arr[3000001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,t,x;
    cin>>n;
    int ans=0;
    while(n--){
        cin>>t;
        arr[t]++;
    }
    cin>>x;
    int divid = x/2;
    if(x%2==1){
        divid=0;
    }
    for(int i=1;i<1000001;i++){
        if(i==x){
            break;
        }
        if(i==divid){
            continue;
        }
        if(arr[i]!=0){
            int idx = x-i;
            if(idx<0){
                idx*=-1;
            }
            if(arr[idx]!=0){
                arr[i]--;
                arr[idx]--;
                ans++;
            }
        }
    }
    cout<<ans;
}