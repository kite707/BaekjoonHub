#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main(){
    int n,s,t;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        cin>>t;
        v.push_back(t);
    }
    int curmin=1000001;
    int st=0;
    int en=0;
    long long curSum=v[0];
    while(st<=en&&en<n){
        if(curSum>=s){
            //cout<<st<<"   "<<en<<endl;
            curmin=min(curmin,en-st+1);
            curSum-=v[st];
            st++;
        }
        else{
            en++;
            curSum+=v[en];
        }
    }
    if(curmin==1000001)cout<<0;
    else cout<<curmin;

}