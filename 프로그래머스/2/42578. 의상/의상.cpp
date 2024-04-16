#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<string> arr[30];

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> types;
    for(int i=0;i<clothes.size();i++){
        types.insert({clothes[i][1],i});
        
    }
    for(int i=0;i<clothes.size();i++){
        int idx=types.find(clothes[i][1])->second;
        arr[idx].push_back(clothes[i][0]);
    }
    for(auto k: types){
        int idx=k.second;
        answer*=(arr[idx].size()+1);
    }
    
    return answer-1;
}