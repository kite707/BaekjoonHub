#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

bool arr[100001];
bool comp(set<int> a, set<int> b){
    return a.size()<b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<set<int>> uni;
    set<int> tmp;
    string str="";
    for(int i=1;i<s.length()-1;i++){
        if(s[i]=='{'){
            str="";
            tmp.clear();
            continue;
        }else if(s[i]=='}'){
            tmp.insert(stoi(str));
            uni.push_back(tmp);
           
        }else if(s[i]==','){
            tmp.insert(stoi(str));
            str="";
        }else{
            str+=s[i];
        }
    }
    sort(uni.begin(),uni.end(),comp);
    for(int i=0;i<uni.size();i++){
        for(auto k:uni[i]){
            //cout<<k<<" ";
            if(!arr[k]){
                answer.push_back(k);
                arr[k]=true;
            }
        }
       // cout<<endl;
    }
    
    cout<<endl;
    return answer;
}