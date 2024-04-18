#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string, vector<int>> mp;



void adder(string st[4], int score){
    for(int i=0;i<16;i++){
        string tmp="";
        int curNum=i;
        for(int j=0;j<4;j++){
            tmp+=to_string(curNum%2);
            curNum/=2;
        }
        string key="";
        for(int i=0;i<tmp.size();i++){
            if(tmp[i]=='0'){
                key+="-";
            }else{
                key+=st[i];
            }
        }
        mp[key].push_back(score);
        tmp="";
    }
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for(int i=0;i<info.size();i++){
        string tmp[4];
        string stScore;
        istringstream stt(info[i]);
        stt>>tmp[0]>>tmp[1]>>tmp[2]>>tmp[3]>>stScore;
        adder(tmp,stoi(stScore));
    }
    for(auto iter=mp.begin();iter!=mp.end();iter++){
        sort(iter->second.begin(),iter->second.end());
    }

    for(int i=0;i<query.size();i++){
        istringstream stt(query[i]);
        string tmp[4];
        string dummy;
        string stScore;
        stt>>tmp[0]>>dummy>>tmp[1]>>dummy>>tmp[2]>>dummy>>tmp[3]>>stScore;
        vector<int> v=mp[tmp[0]+tmp[1]+tmp[2]+tmp[3]];
        if(v.empty()){
            answer.push_back(0);
            continue;
        }
        int idx=lower_bound(v.begin(),v.end(),stoi(stScore))-v.begin();
        answer.push_back(v.size()-idx);
        // cout<<"찾는점수: "<<stScore<<" idx: "<<idx<<" ";
        // cout<<"답? "<<<<endl;
        // for(int j=0;j<v.size();j++){
        //     cout<<v[j]<<" ";
        // }
        // cout<<endl;
    }
    
    return answer;
}