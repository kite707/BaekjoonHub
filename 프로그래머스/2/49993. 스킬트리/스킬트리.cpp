#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool isExist[27][2];

bool compareSkill(string skillTree, string userSkill){
    for(int i=0;i<userSkill.length();i++){
        if(userSkill[i]!=skillTree[i])return false;
    }
    return true;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(auto k:skill){
        isExist[k-'A'][0]=true;
    }
    for(int i=0;i<skill_trees.size();i++){
        string curSkill=skill_trees[i];
        string newSkill="";
        for(auto k:curSkill){
            if(isExist[k-'A'][0]&&!isExist[k-'A'][1]){
                newSkill+=k;
                isExist[k-'A'][1]=true;
            }
        }
        for(int i=0;i<27;i++){
            isExist[i][1]=false;
        }
        skill_trees[i]=newSkill;
    }
    for(int i=0;i<skill_trees.size();i++){
        if(compareSkill(skill,skill_trees[i])){
            answer++;
        }
    }
    return answer;
}