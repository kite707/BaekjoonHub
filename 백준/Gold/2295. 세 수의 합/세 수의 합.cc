#include <iostream>
#include <algorithm>
using namespace std;

vector<int> one;
vector<int> two;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin>>N;
    int t;
    while(N--){
        cin>>t;
        one.push_back(t);
    }
    sort(one.begin(),one.end());
    for(int i=0;i<one.size();i++){
        for(int j=0;j<one.size();j++){
            two.push_back(one[i]+one[j]);
        }
    }
    sort(two.begin(),two.end());
    for(int i=one.size()-1;i>0;i--){
        for(int j=0;j<i;j++){
            int num = one[i]-one[j];
            //cout<<"num is " <<num<<endl;
            if(!binary_search(two.begin(),two.end(),num))continue;
            cout<<one[i];
            return 0;
        }
    }
}