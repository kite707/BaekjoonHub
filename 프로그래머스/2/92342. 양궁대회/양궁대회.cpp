#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//칸막이 10개(0), 양 끝에 0 있을 시 스킵
//어피치가 활을 다 쏘고 라이언이 n발을 쏠 차례
//라이언이 가장 큰 점수차이로 이길 방법 구하기
vector<int> make_cand(vector<int> &a){
    int cursum=0;
    vector<int> ans;
    for(int i=0;i<a.size();i++){
        if(a[i]==0){
            ans.push_back(cursum);
            cursum=0;
        }
        else{
            cursum++;
        }
    }
    ans.push_back(cursum);
    return ans;
}

//a는 어피치 b는 라이언
int getScore(vector<int> &a, vector<int> &b){
    int apScore=0;
    int liScore=0;
    for(int i=0;i<a.size();i++){
        int curScore=10-i;
        if(a[i]==0&&a[i]==b[i])continue;
        if(a[i]>=b[i]){
            apScore+=curScore;
        }
        else if(a[i]<b[i]){
            liScore+=curScore;
        }
    }
    vector<int> realAns={0, 2, 2, 0, 1, 0, 0, 0, 0, 0, 0};
    
    return liScore-apScore;
}

bool cmp(vector<int> a, vector<int> b){
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]==b[i])continue;
        return a[i]>b[i];
    }
}


vector<int> solution(int n, vector<int> info) {
    vector<vector<int>> answer;
    vector<int> a;
    for(int i=0;i<10;i++){
        a.push_back(0);
    }
    for(int i=0;i<n;i++){
        a.push_back(1);
    }
    
    sort(a.begin(),a.end());
    do{
        vector<int> vec=make_cand(a);
        int score=getScore(info,vec);
        if(score>0){ //라이언이 이길 경우
        vec.push_back(score);
        answer.push_back(vec);
        }

    }while(next_permutation(a.begin(),a.end()));
    if(answer.empty()){
        vector<int> v1;
        v1.push_back(-1);
        return v1;
    }
    sort(answer.begin(),answer.end(),cmp);
    vector<int> ans=answer[0];
    ans.pop_back();
    return ans;
}