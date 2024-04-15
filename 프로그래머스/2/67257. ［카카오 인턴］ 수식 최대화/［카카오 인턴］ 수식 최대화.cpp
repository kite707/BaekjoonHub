#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long calc(long long a, long long b, char oper){
    if(oper=='+')return a+b;
    if(oper=='-')return a-b;
    return a*b;
}

long long solution(string expression) {
    long long answer = 0;
    vector<long long> nums;
    vector<char> oper;
    string tmp="";
    for(int i=0;i<expression.length();i++){
        if(expression[i]<='9'&&expression[i]>='0')tmp+=expression[i];
        else{
            oper.push_back(expression[i]);
            nums.push_back(stoll(tmp));
            tmp="";
        }
    }
    nums.push_back(stoll(tmp));
    
    vector<int> v={0,1,2};
    string opers="+-*";
    do{
        vector<char> tmp_oper=oper;
        vector<long long> tmp_nums=nums;
        for(int i=0;i<v.size();i++){
            char curOper=opers[v[i]];
            for(int j=0;j<tmp_oper.size();j++){
                if(tmp_oper[j]==curOper){
                    long long res=calc(tmp_nums[j],tmp_nums[j+1],curOper);
                    tmp_nums.erase(tmp_nums.begin()+j);
                    tmp_nums[j]=res;
                    tmp_oper.erase(tmp_oper.begin()+j);
                    j--;
                }
            }
        }
        answer=max(answer,abs(tmp_nums[0]));
    }while(next_permutation(v.begin(),v.end()));
    
    return answer;
}