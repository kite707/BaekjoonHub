#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> ans;
bool possible(int n){
    for(int an:ans)if((n&an)==an)return false;
    return true;
}

int solution(vector<vector<string>> relation) {
    int colu=relation.size();
    int attr=relation[0].size();
    for(int i=1;i<(1<<attr);i++){
        if(!possible(i))continue;
        set<string> s;
        for(int k=0;k<relation.size();k++){
            string cand;
            for(int j=0;j<attr;j++){
                if(i>>j&1){
                    cand+=relation[k][j];
                }
            }
            s.insert(cand);
        }
       if(s.size()==colu)ans.push_back(i);
    }
    return ans.size();
}