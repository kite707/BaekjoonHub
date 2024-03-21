#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,l,t;
bool arr[1000];
vector<int> v;

int minNum(int length){
    int cnt=0;
    int curMax=0;
    for(int i=0;i<v.size();i++){
        int rest= v[i];
        int curlength=rest-curMax;
        //cout<<"curLength is "<<curlength<<endl;
        int toBuild=curlength/length;
        if(curlength%length==0)toBuild--;
        cnt+=toBuild;
        //cout<<v[i]<<"   "<<toBuild<<"   "<<curMax<<endl;
        curMax=max(v[i],toBuild*length);
        //cout<<"curMax is "<<curMax<<endl;
    }
    //cout<<cnt<<endl;
    //cout<<l<<"  "<<curMax<<"  "<<length<<endl;
    cnt+=(l-curMax)/length;
    //cout<<cnt<<endl;
    if((l-curMax)%length==0)cnt--;
    return cnt;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>l;
    while(n--){
        cin>>t;
        v.push_back(t);
        arr[t]=true;
    }
    sort(v.begin(),v.end());
    int st=1;
    int en=l;
    int mid=0;
    while(st!=en){
        mid= (st+en)/2;
        if(minNum(mid)>m)st=mid+1;
        else en=mid;
    }
    cout<<st;

}