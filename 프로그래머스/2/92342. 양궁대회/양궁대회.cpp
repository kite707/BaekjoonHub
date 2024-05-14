#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]!=b[i])return a[i]<b[i];
    }
    return false;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer(12,-1);
    vector<int> seq(n+10);
    fill(seq.begin()+n,seq.end(),1);
    do{
        vector<int> cand;
        int before=-1;
        for(int i=0;i<n+10;i++){
            if(seq[i]){
                cand.push_back(i-before-1);
                before=i;
            }
        }
        cand.push_back(n+10-before-1);
        
        int score=0;
        for(int i=0;i<info.size();i++){
            if(cand[i]>info[i]){
                score+=10-i;
            }else if(info[i]!=0){
                score-=10-i;
            }
        }
        if(score<=0)continue;
        cand.push_back(score);
        if(cmp(answer,cand))answer=cand;
    }while(next_permutation(seq.begin(),seq.end()));
    if(answer[0]==-1){
        return vector<int>({-1});
    }
    answer.pop_back();
    return answer;
}