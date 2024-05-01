#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

unordered_map<string, string> parentInfo;
unordered_map<string, int> income; //사람별 이익
unordered_map<string, int> result;
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    for(int i=0;i<enroll.size();i++){
        parentInfo[enroll[i]]=referral[i];
        result[enroll[i]]=0;
    }

    for(int i=0;i<seller.size();i++){
        string sell=seller[i];
        int money=amount[i]*100;
        string parent=parentInfo[sell];
        do{
            parent=parentInfo[sell];
            if(money<10){
                result[sell]+=money;
                break;
            }
            int giveMoney=floor(money*0.1);
            int myMoney=money-giveMoney;
            //cout<<sell<<" "<<parent<<" "<<myMoney<<" "<<giveMoney<<endl;
            result[sell]+=myMoney;
            money=giveMoney;
            sell=parent;
        }while(parent!="-");
        //cout<<"new\n";
    }
    for(int i=0;i<enroll.size();i++){
        answer.push_back(result[enroll[i]]);
    }
    // for(auto k: result){
    //     cout<<k.first<<" "<<k.second<<endl;
    // }
    
    // for(auto k: graph){
    //     cout<<k.first<<" : ";
    //     for(int i=0;i<k.second.size();i++){
    //         cout<<k.second[i]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"----------"<<endl;
    // for(auto k: income){
    //     cout<<k.first<<" "<<k.second<<endl;
    // }
    return answer;
}