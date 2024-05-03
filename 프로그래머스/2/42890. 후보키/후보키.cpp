#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool isAns(vector<int> a, vector<int> b){
        for(int j=0;j<a.size();j++){
            if(a[j]==1&&b[j]!=1){
                return true;
            }
        }
    return false;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int totalColumn=relation[0].size();
    int totalRow=relation.size();
    vector<vector<int>> ans;
    for(int i=1;i<=totalColumn;i++){
        vector<int> btn(totalColumn,1);
        for(int j=0;j<totalColumn-i;j++){
            btn[j]=0;
        }
        do{
            if(ans.size()!=0){
                bool flag=true;
                for(int t=0;t<ans.size();t++){
                    if(!isAns(ans[t],btn)){
                        flag=false;
                        break;
                    }
                }
                if(!flag)continue;
            }
            unordered_map<string,int> mp;
            bool isAnswer=true;
            for(auto rel:relation){
                string key="";
                for(int idx=0;idx<btn.size();idx++){
                    if(btn[idx]==1)key+=rel[idx];
                }
                mp[key]++;
                if(mp[key]!=1){
                    isAnswer=false;
                    break;
                }
            }
            if(isAnswer){
            //        cout<<"후보키 추가\n";
            // for(auto k:btn){
            //     cout<<k<<" ";
            // }cout<<endl;
            ans.push_back(btn);
            answer++; 
            
                } 
        }while(next_permutation(btn.begin(),btn.end()));
        
    }
    return answer;
}