#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string,string> mp;
    string oper,userId,nick;
    for(int i=0;i<record.size();i++){
        istringstream ss(record[i]);
        ss>>oper>>userId>>nick;
        if(oper!="Leave"){
            mp[userId]=nick;
            //cout<<oper<<" "<<userId<<" "<<nick<<endl;
        }
    }
    for(int i=0;i<record.size();i++){
        istringstream ss(record[i]);
        ss>>oper>>userId>>nick;
        string tmp="";
        if(oper=="Enter"){
            tmp+=mp[userId]+"님이 들어왔습니다.";
        }else if(oper=="Leave"){
            tmp+=mp[userId]+"님이 나갔습니다.";
        }else{
            continue;
        }
        answer.push_back(tmp);
    }
    return answer;
}