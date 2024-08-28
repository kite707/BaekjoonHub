#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    unordered_map<char,int> mp;
    for(int i=0;i<skill.size();i++){
        mp.insert({skill[i],i});
    }
    for(int i=0;i<skill_trees.size();i++){
        string curSkill=skill_trees[i];
        int curMax=0;
        for(int j=0;j<curSkill.size();j++){
            if(mp.find(curSkill[j])!=mp.end()){
            int val=mp[curSkill[j]];
            if(val!=curMax)break;
            curMax++;
            }
            if(j==curSkill.size()-1){answer++;}
        }
    }

    return answer;
}