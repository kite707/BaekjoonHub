#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string,string> mp; //id nick

vector<string> solution(vector<string> record) {
    vector<string> answer;
    for(string rec:record){
        istringstream st(rec);
        string tmp;
        string key,id,nick;
        st>>key>>id>>nick;
        if(!nick.empty())mp[id]=nick;
    }
    
    for(string rec:record){
        istringstream st(rec);
        string tmp;
        string key,id,nick;
        st>>key>>id>>nick;
        string ans;
        if(key=="Leave"){
            ans=mp[id]+"님이 나갔습니다.";
        }else if(key=="Enter"){
            ans=mp[id]+"님이 들어왔습니다.";
        }else continue;
        answer.push_back(ans);
    }
    return answer;
}