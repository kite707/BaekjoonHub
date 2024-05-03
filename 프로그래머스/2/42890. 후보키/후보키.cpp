#include <bits/stdc++.h>
using namespace std;
bool possi(vector<int> &vec,int now){
    for(int i=0;i<vec.size();i++)
        if((vec[i]&now)==vec[i])return false;
    return true;
}
int solution(vector<vector<string>> relation) {
    int n=relation.size();
    int m=relation[0].size();
    //cout<<"n와 m은 "<<n<<" "<<m<<endl;
    vector<int> ans;
    for(int i=1;i<(1<<m);i++){
        if(ans.size()!=0&&!possi(ans,i))continue;
        set<string> s;
        for(int j=0;j<n;j++){
            string now="";
            for(int k=0;k<m;k++){
                
                if(i&(1<<k)){
                //     cout<<"i는 "<<bitset<4>(i)<<endl;
                // cout<<"1<<k는 "<<bitset<4>(1<<k)<<endl;
                    now+=relation[j][k];
                }
            }
            s.insert(now);
        }
        if(s.size()==n)ans.push_back(i);
    }
    return ans.size();
}